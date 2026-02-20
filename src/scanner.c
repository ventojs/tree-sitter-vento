#include <tree_sitter/parser.h>
#include <wctype.h>
#include <stdio.h>

#define DEBUG 0

#if DEBUG == 1
#define PRINTF(...) printf(__VA_ARGS__)
#else
#define PRINTF(...)
#endif

enum TokenType {
  CODE,
  // Like `CODE`, but skips the initial keyword check. Used on JavaScript tags
  // (`{{>`).
  RAW_CODE,
  PARAMETER_DEFAULT_VALUE,
  TAG_START_DELIMITER_SIMPLE,
  TAG_START_DELIMITER_TRIM_WHITESPACE,
  TAG_START_DELIMITER_JAVASCRIPT,
  TAG_START_DELIMITER_JAVASCRIPT_TRIM_WHITESPACE,
  TAG_START_DELIMITER_COMMENT,
  TAG_START_DELIMITER_COMMENT_TRIM_WHITESPACE
};

void *tree_sitter_vento_external_scanner_create() { return NULL; }
void tree_sitter_vento_external_scanner_destroy(void *payload) {}
unsigned tree_sitter_vento_external_scanner_serialize( void *payload, char *buffer) { return 0; }
void tree_sitter_vento_external_scanner_deserialize( void *payload, const char *buffer, unsigned length) {}

static bool handle_delimiters(TSLexer *lexer, const char excluded_character);

static void skip_whitespace(TSLexer *lexer) {
  while (iswspace(lexer->lookahead)) {
    lexer->advance(lexer, true);
  }
}

// Invoked at the beginning of a word. Determines whether the word is equal to
// any of our known keywords.
static bool matches_any_keyword(TSLexer *lexer, const char **keywords) {
  PRINTF("in matches_any_keyword col: %i\n", lexer->get_column(lexer));
  // Determine how many keywords we're dealing with.
  int keyword_count = 0;
  while (keywords[keyword_count] != NULL) {
    keyword_count++;
  }

  // Use this array of booleans to track which of our keywords remain as
  // candidates. At first, they're all candidates; we'll weed some out as we
  // advance through the word.
  bool *active = malloc(keyword_count * sizeof(bool));
  for (int i = 0; i < keyword_count; i++) {
    active[i] = true;
  }

  int pos = 0;
  int32_t current_char = lexer->lookahead;

  while (current_char != 0) {
    bool any_active = false;

    // Check each keyword at the current position.
    for (int i = 0; i < keyword_count; i++) {
      if (!active[i]) continue;

      // If this keyword is shorter than the current position, it's eliminated.
      if (keywords[i][pos] == '\0') {
        active[i] = false;
        continue;
      }

      // If the character at this position doesn't match, this keyword is
      // eliminated.
      if (keywords[i][pos] != current_char) {
        active[i] = false;
        continue;
      }

      any_active = true;
    }

    // If no keywords are still possible, we're done!
    if (!any_active) {
      break;
    }

    // Advance to the next character.
    lexer->advance(lexer, false);

    // Before we do anything else, let's check if we've reached the end of a
    // word. If so, then we can stop looping and see if any of our candidates
    // are complete matches.
    if (iswspace(lexer->lookahead) || lexer->lookahead == '}' || lexer->eof(lexer)) {
      for (int i = 0; i < keyword_count; i++) {
        if (!active[i]) continue;
        // Skip anything that hasn't matched the entire keyword.
        if (keywords[i][pos + 1] != '\0') continue;

        // If we get this far, it means there is a match!
        PRINTF("Found a keyword match: %s", keywords[i]);
        free(active);
        return true;
      }

      // If we get through the loop without an exact match, it's because we've
      // typed, e.g., `{{ expor }}`, so the keyword isn't fully formed. Hence
      // this tag doesn't start with a keyword.
      //
      // BUT… when we relinquish control to the main logic that looks for
      // `code` nodes, it possibly won't get an opportunity to mark the
      // end of the node, since we've consumed an entire word and there may not
      // be another one before the `}}`. So we'll mark the end of the node here
      // just to be safe; this prevents a bug in the `{{ expor }}` example
      // above.
      PRINTF("No keyword matches; word might be a substring of a known keyword\n");
      lexer->mark_end(lexer);
      break;
    }

    current_char = lexer->lookahead;
    pos++;
  }

  free(active);
  PRINTF("No match found for any known keywords\n");
  return false;
}

static const char *KEYWORDS[] = {
  "if",
  "else",
  "for",
  "include",
  "set",
  "import",
  "export",
  "layout",
  "function",
  "fragment",
  "echo",
  "slot",
  "default",
  NULL  // sentinel value to mark end of array
};

// When the lookahead character is a `{`, advances past the balanced `}`.
// Returns `false` if balancing fails. Don't call this unless the next
// character is an open curly brace.
static bool scan_to_end_of_object(TSLexer *lexer) {
  uint32_t depth = 0;
  while (!lexer->eof(lexer)) {
    if (!handle_delimiters(lexer, '{')) return false;
    if (lexer->lookahead == '{') {
      depth++;
    } else if (lexer->lookahead == '}') {
      depth--;
      if (depth < 0) return false;
      else if (depth == 0) {
        lexer->advance(lexer, false);
        return true;
      }
    }
    lexer->advance(lexer, false);
  }
  return false;
}

// When the lookahead character is a `[`, advances past the balanced `]`.
// Returns `false` if balancing fails. Don't call this unless the next
// character is an open square bracket.
static bool scan_to_end_of_array(TSLexer *lexer) {
  uint32_t depth = 0;
  while (!lexer->eof(lexer)) {
    if (!handle_delimiters(lexer, '[')) return false;
    if (lexer->lookahead == '[') {
      depth++;
    }
    else if (lexer->lookahead == ']') {
      depth--;
      if (depth < 0) return false;
      else if (depth == 0) {
        lexer->advance(lexer, false);
        return true;
      }
    }
    lexer->advance(lexer, false);
  }
  return false;
}

// When the lookahead character is a `(`, advances past the balanced `)`.
// Returns `false` if balancing fails. Don't call this unless the next
// character is an open parenthesis.
static bool scan_to_end_of_parenthesized_clause(TSLexer *lexer) {
  uint32_t depth = 0;
  while (!lexer->eof(lexer)) {
    if (!handle_delimiters(lexer, '(')) return false;
    if (lexer->lookahead == '(') {
      depth++;
    }
    else if (lexer->lookahead == ')') {
      depth--;
      if (depth < 0) return false;
      else if (depth == 0) {
        lexer->advance(lexer, false);
        return true;
      }
    }
    lexer->advance(lexer, false);
  }
  return false;
}

// If the current lookahead position is a known opening delimiter, scans
// through to the balanced closing delimiter. Returns `true` if it has done so
// successfully, or if there was no opening delimiter at the current position.
//
// Returns `false` if delimiters could not be balanced because of syntactic
// invalidity or incompleteness.
//
// `excluded_character` accepts one opening delimiter to ignore; this allows us
// to call `handle_delimiters` recursively from the various `scan_to_end_of_`
// functions without looping infinitely. When we don't want to ignore any
// characters, we can pass a null character.
static bool handle_delimiters(TSLexer *lexer, const char excluded_character) {
  if (lexer->lookahead == '{' && lexer->lookahead != excluded_character) {
    return scan_to_end_of_object(lexer);
  } else if (lexer->lookahead == '[' && lexer->lookahead != excluded_character) {
    return scan_to_end_of_array(lexer);
  } else if (lexer->lookahead == '(' && lexer->lookahead != excluded_character) {
    return scan_to_end_of_parenthesized_clause(lexer);
  }
  return true;
}

// Advances until it can identify a complete default parameter, as in this
// example:
//
// {{ function foo (bar, baz = [1, 2, 3], thud) }}
//
// The delimiters that mark the end of a default value (`,` and `)`) can also
// validly be encountered during the definition of a default value, so we need
// to be able to skip past array literals and any other contexts in which those
// characters mean other things.
//
// If `CODE` is a valid symbol in this context, this function will recover from
// failure by marking the value as a `code` node and returning `true`. In this
// case (and in the case where this function returns `false`), we didn't
// encounter either delimiter, or else encountered some other balancing error.
static bool scan_for_default_value(TSLexer *lexer, bool code_allowed) {
  PRINTF("scan_for_default_value col: %i\n", lexer->get_column(lexer));
  while (!lexer->eof(lexer)) {
    PRINTF("Considering character %c at column %i\n", lexer->lookahead, lexer->get_column(lexer));
    // If this character is a known opening delimiter, skip all content until
    // its paired closing delimiter.
    if (!handle_delimiters(lexer, '\0')) {
      return false;
    }

    if (lexer->lookahead == ',' || lexer->lookahead == ')') {
      // At this point, a comma can only mean the end of an argument, and a
      // closing parenthesis can only mean the end of an argument list. (Any
      // false positives would've been encountered by `handle_delimiters`.) So
      // we can be certain we've reached the end of the parameter's default
      // value.
      PRINTF("Found a default value!\n");
      lexer->mark_end(lexer);
      lexer->result_symbol = PARAMETER_DEFAULT_VALUE;
      return true;
    } else if (lexer->lookahead == '}') {
      // A closing brace encountered here is either part of the ending
      // delimiter of a tag (`}}`) or some sort of strange typo. (Any other
      // valid closing braces would've been encountered by
      // `handle_delimiters`.)
      PRINTF("We found a } — this cannot be a default value!\n");
      // If `CODE` is a valid symbol in this context, we can recover by
      // reinterpreting this as a `code` node.
      if (code_allowed) {
        PRINTF("Instead, we'll interpret it as a `code` node\n");
        lexer->mark_end(lexer);
        lexer->result_symbol = CODE;
        return true;
      }
      return false;
    }
    lexer->advance(lexer, false);
  }
  return false;
}

// Identify most of the ways that tags can start. Call this function once the
// lookahead character is an opening curly brace.
//
// We handle this in an external scanner for a hacky reason: it's the first
// thing that worked in the quest to ensure that all sorts of tag nodes would
// omit leading whitespace before the `{{`.
//
// We could treat them all as the same kind of node, but we want this to be
// completely transparent, so we alias the different kinds of nodes as their
// literal anonymous-node equivalents. Hence we need to be able to tell them
// apart in `grammar.js`.
//
// This function accepts the `valid_symbols` table so that we can ensure the
// matched kind of delimiter is valid in the current context.
//
static bool scan_for_tag_start_delimiter(
  TSLexer *lexer,
  const bool *valid_symbols
) {
  PRINTF("scan_for_tag_start_delimiter col: %i\n", lexer->get_column(lexer));
  if (lexer->lookahead != '{') return false;
  lexer->advance(lexer, false);
  if (lexer->lookahead != '{') return false;
  lexer->advance(lexer, false);
  if (lexer->lookahead == '#') {
    // We've got `{{#`.
    lexer->advance(lexer, false);
    if (lexer->lookahead == '-') {
      // We've got `{{#-`.
      if (valid_symbols[TAG_START_DELIMITER_COMMENT_TRIM_WHITESPACE]) {
        lexer->advance(lexer, false);
        lexer->mark_end(lexer);
        PRINTF("Marking as {{#-\n");
        lexer->result_symbol = TAG_START_DELIMITER_COMMENT_TRIM_WHITESPACE;
      } else {
        return false;
      }
    } else {
      // We've got `{{#`.
      if (valid_symbols[TAG_START_DELIMITER_COMMENT]) {
        lexer->mark_end(lexer);
        PRINTF("Marking as {{#\n");
        lexer->result_symbol = TAG_START_DELIMITER_COMMENT;
      } else {
        return false;
      }
    }
  } else if (lexer->lookahead == '>') {
    // We've got `{{>`. Anything after this will be treated as JS, even if
    // there's no space afterwards.
    if (valid_symbols[TAG_START_DELIMITER_JAVASCRIPT]) {
      lexer->advance(lexer, false);
      lexer->mark_end(lexer);
      PRINTF("Marking as {{>\n");
      lexer->result_symbol = TAG_START_DELIMITER_JAVASCRIPT;
    } else {
      return false;
    }
  } else if (lexer->lookahead == '-') {
    // We've got `{{-` so far. This could be `{{- ` or `{{-> `.
    lexer->advance(lexer, false);
    if (lexer->lookahead == '>') {
      // We've got `{{->`. Anything after this will be treated as JS, even if
      // there's no space afterwards.
      if (valid_symbols[TAG_START_DELIMITER_JAVASCRIPT_TRIM_WHITESPACE]) {
        lexer->advance(lexer, false);
        lexer->mark_end(lexer);
        PRINTF("Marking as {{->\n");
        lexer->result_symbol = TAG_START_DELIMITER_JAVASCRIPT_TRIM_WHITESPACE;
      } else {
        return false;
      }
    } else {
      // We must have `{{-`.
      if (valid_symbols[TAG_START_DELIMITER_TRIM_WHITESPACE]) {
        lexer->mark_end(lexer);
        PRINTF("Marking as {{-\n");
        lexer->result_symbol = TAG_START_DELIMITER_TRIM_WHITESPACE;
      } else {
        return false;
      }
    }
  } else {
    // We've got `{{` without any of the special cases above.
    if (valid_symbols[TAG_START_DELIMITER_SIMPLE]) {
      lexer->mark_end(lexer);
      PRINTF("Marking as {{\n");
      lexer->result_symbol = TAG_START_DELIMITER_SIMPLE;
    } else {
      return false;
    }
  }
  PRINTF("Found a starting tag delimiter\n");
  return true;
}

bool tree_sitter_vento_external_scanner_scan(
  void *payload,
  TSLexer *lexer,
  const bool *valid_symbols
) {
  skip_whitespace(lexer);
  PRINTF(
    "In the external scanner with validity: %i %i %i %i %i %i %i\n",
    valid_symbols[CODE],
    valid_symbols[RAW_CODE],
    valid_symbols[PARAMETER_DEFAULT_VALUE],
    valid_symbols[TAG_START_DELIMITER_SIMPLE],
    valid_symbols[TAG_START_DELIMITER_TRIM_WHITESPACE],
    valid_symbols[TAG_START_DELIMITER_JAVASCRIPT],
    valid_symbols[TAG_START_DELIMITER_JAVASCRIPT_TRIM_WHITESPACE]
  );

  if (
    (
      valid_symbols[TAG_START_DELIMITER_SIMPLE] ||
      valid_symbols[TAG_START_DELIMITER_TRIM_WHITESPACE] ||
      valid_symbols[TAG_START_DELIMITER_JAVASCRIPT] ||
      valid_symbols[TAG_START_DELIMITER_JAVASCRIPT_TRIM_WHITESPACE]
    ) && lexer->lookahead == '{'
  ) {
    if (scan_for_tag_start_delimiter(lexer, valid_symbols)) {
      return true;
    }
  }

  if (valid_symbols[PARAMETER_DEFAULT_VALUE]) {
    // In cases where both `PARAMETER_DEFAULT_VALUE` and `CODE` are both valid,
    // we have to do some of `CODE`’s work for it, since we're acting ahead of
    // it and advancing past some characters it might care about.
    if (scan_for_default_value(lexer, valid_symbols[CODE])) {
      return true;
    }
  }

  // TODO: Extract into its own function?
  if (valid_symbols[CODE] || valid_symbols[RAW_CODE]) {
    int target_symbol = valid_symbols[CODE] ? CODE : RAW_CODE;
    if (lexer->eof(lexer) ||
        lexer->lookahead == '/' ||
        lexer->lookahead == '-' ||
        lexer->lookahead == '}') {
      return false;
    }

    if (iswalnum(lexer->lookahead) && valid_symbols[CODE]) {
      // Check if any keyword matches from the current position. If so, we want
      // this check to fail, because those keywords need to be handled as
      // anonymous nodes as part of the ordinary parsing process.
      if (matches_any_keyword(lexer, KEYWORDS)) {
        if (valid_symbols[RAW_CODE]) {
          // We can resume with the `RAW_CODE` check below if this fails…
          lexer->mark_end(lexer);
          target_symbol = RAW_CODE;
        } else {
          // …but if `RAW_CODE` isn't valid in this context, we must return
          // `false`.
          return false;
        }
      }
    }

    // We start in a code block, so we need to find the end of it.
    uint32_t depth = 1;

    while (depth > 0) {
      if (lexer->eof(lexer)) {
        return false;
      }

      if (lexer->lookahead == '{') {
        PRINTF("Encountered an opening brace at col %i; new depth will be %i\n", lexer->get_column(lexer), depth + 1);
        lexer->advance(lexer, false);
        depth++;

      } else if (lexer->lookahead == '}') {
        PRINTF("Encountered a closing brace at col %i; new depth will be %i\n", lexer->get_column(lexer), depth - 1);
        lexer->advance(lexer, false);

        if (depth > 1) {
          lexer->mark_end(lexer);
        }
        depth--;
      } else if (lexer->lookahead == '|') {
        lexer->mark_end(lexer);
        lexer->advance(lexer, false);

        if (lexer->lookahead == '>') {
          PRINTF("Reached a filter, hence identified a code block\n");
          lexer->advance(lexer, false);
          lexer->result_symbol = target_symbol;
          return true;
        }
      } else {
        const bool skip = iswspace(lexer->lookahead) || lexer->lookahead == '-';
        lexer->advance(lexer, false);
        if (!skip) {
          lexer->mark_end(lexer);
        }
      }

      if (depth == 0) {
        PRINTF("Identified a code block\n");
        lexer->result_symbol = target_symbol;
        return true;
      }
    }

    return false;
  }

  return false;
}
