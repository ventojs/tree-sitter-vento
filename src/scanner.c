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
  PARAMETER_DEFAULT_VALUE,
  TAG_START_DELIMITER_SIMPLE,
  TAG_START_DELIMITER_TRIM_WHITESPACE
};

typedef struct {
  const char **keywords;
  int count;
} KeywordSet;

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

static bool matches_any_keyword(TSLexer *lexer, const char **keywords) {
  PRINTF("matches any keyword? %i\n", lexer->get_column(lexer));
  // Count active keywords
  int keyword_count = 0;
  while (keywords[keyword_count] != NULL) {
    keyword_count++;
  }

  // Track which keywords are still possible matches
  bool *active = malloc(keyword_count * sizeof(bool));
  for (int i = 0; i < keyword_count; i++) {
    active[i] = true;
  }

  int pos = 0;
  int32_t current_char = lexer->lookahead;

  while (current_char != 0) {
    bool any_active = false;

    // Check each keyword at current position
    for (int i = 0; i < keyword_count; i++) {
      if (!active[i]) continue;

      // If this keyword is shorter than current position, deactivate
      if (keywords[i][pos] == '\0') {
        active[i] = false;
        continue;
      }

      // If character doesn't match, deactivate this keyword
      if (keywords[i][pos] != current_char) {
        active[i] = false;
        continue;
      }

      any_active = true;
    }

    // If no keywords are still possible, we're done
    if (!any_active) {
      break;
    }

    // Check if any keyword is complete at this position
    for (int i = 0; i < keyword_count; i++) {
      if (active[i] && keywords[i][pos] == current_char && keywords[i][pos + 1] == '\0') {
        // Complete keyword found; ensure it is followed by a space or
        // delimiter.
        lexer->advance(lexer, false);
        bool is_complete_keyword = (lexer->lookahead == ' ' || lexer->lookahead == '}' || lexer->eof(lexer));
        free(active);
        if (is_complete_keyword) {
          PRINTF("YUP!\n");
        }
        return is_complete_keyword;
      }
    }

    // Advance to next character
    lexer->advance(lexer, false);
    current_char = lexer->lookahead;
    pos++;
  }

  free(active);
  PRINTF("NAH!\n");
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
  NULL  // sentinel value to mark end of array
};

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

static bool scan_for_default_value(TSLexer *lexer, bool code_allowed) {
  PRINTF("scan_for_default_value! %c %i\n", lexer->lookahead, lexer->get_column(lexer));
  while (!lexer->eof(lexer)) {
    PRINTF("CONSIDERING: %c AT %i\n", lexer->lookahead, lexer->get_column(lexer));
    if (!handle_delimiters(lexer, '\0')) {
      PRINTF("nah! %i\n", lexer->get_column(lexer));
      return false;
    }
    if (lexer->lookahead == ',' || lexer->lookahead == ')') {
      PRINTF("Found a default value!");
      lexer->mark_end(lexer);
      lexer->result_symbol = PARAMETER_DEFAULT_VALUE;
      return true;
    } else if (lexer->lookahead == '}') {
      PRINTF("We found a } — this cannot be a default value!\n");
      if (code_allowed) {
        PRINTF("We can recover as a CODE node!\n");
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

static bool scan_for_tag_start_delimiter(TSLexer *lexer) {
  if (lexer->lookahead != '{') return false;
  lexer->advance(lexer, false);
  if (lexer->lookahead != '{') return false;
  lexer->advance(lexer, false);
  // Don't claim comment start syntax.
  if (lexer->lookahead == '#') return false;
  // Don't claim JavaScript block syntax.
  if (lexer->lookahead == '>') return false;
  if (lexer->lookahead == '-') {
    lexer->advance(lexer, false);
    // Don't claim JavaScript block syntax.
    if (lexer->lookahead == '>') return false;
    lexer->mark_end(lexer);
    lexer->result_symbol = TAG_START_DELIMITER_TRIM_WHITESPACE;
  } else {
    lexer->mark_end(lexer);
    lexer->result_symbol = TAG_START_DELIMITER_SIMPLE;
  }
  PRINTF("TAG START! %i\n", lexer->get_column(lexer));
  return true;
}

bool tree_sitter_vento_external_scanner_scan(
  void *payload,
  TSLexer *lexer,
  const bool *valid_symbols
) {
  skip_whitespace(lexer);

  if (valid_symbols[TAG_START_DELIMITER_SIMPLE] && lexer->lookahead == '{') {
    if (scan_for_tag_start_delimiter(lexer)) {
      return true;
    }
  }

  if (valid_symbols[PARAMETER_DEFAULT_VALUE]) {
    if (scan_for_default_value(lexer, valid_symbols[CODE])) {
      return true;
    }
  }

  if (valid_symbols[CODE]) {

    if (lexer->eof(lexer) ||
        lexer->lookahead == '/' ||
        lexer->lookahead == '-' ||
        lexer->lookahead == '}') {
      return false;
    }

    // Check if any keyword matches from current position
    if (matches_any_keyword(lexer, KEYWORDS)) {
      // Found a keyword - rule should NOT match
      return false;
    }

    // We start in a code block, so we need to find the end of it
    uint32_t depth = 1;

    PRINTF("SO WE CONTINUE!\n");

    while (depth > 0) {
      if (lexer->eof(lexer)) {
        return false;
      }

      if (lexer->lookahead == '{') {
        lexer->advance(lexer, false);
        depth++;

      } else if (lexer->lookahead == '}') {
        lexer->advance(lexer, false);

        if (depth > 1) {
          lexer->mark_end(lexer);
        }
        depth--;

      } else if (lexer->lookahead == '|') {
        lexer->mark_end(lexer);
        lexer->advance(lexer, false);

        if (lexer->lookahead == '>') {
          lexer->advance(lexer, false);

          lexer->result_symbol = CODE;
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
        lexer->result_symbol = CODE;
        return true;
      }
    }

    return false;
  }

  return false;
}
