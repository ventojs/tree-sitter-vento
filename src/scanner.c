#include <tree_sitter/parser.h>
#include <wctype.h>
#include <stdio.h>

enum TokenType {
  CODE,
  KEYWORD,
};

void *tree_sitter_vento_external_scanner_create() { return NULL; }
void tree_sitter_vento_external_scanner_destroy(void *payload) {}
unsigned tree_sitter_vento_external_scanner_serialize( void *payload, char *buffer) { return 0; }
void tree_sitter_vento_external_scanner_deserialize( void *payload, const char *buffer, unsigned length) {}

bool is_trim_marker(char c) {
  switch (c) {
    case '-':
      return true;
    default:
      return false;
  };
}

void skip_whitespace(TSLexer *lexer) {
  while (iswspace(lexer->lookahead)) {
    lexer->advance(lexer, true);
  }
}

void skip(TSLexer *lexer) {
  lexer->advance(lexer, true);
}

void advance(TSLexer *lexer) {
  lexer->advance(lexer, false);
}

bool tree_sitter_vento_external_scanner_scan(
  void *payload,
  TSLexer *lexer,
  const bool *valid_symbols
) {
  skip_whitespace(lexer);

  if (valid_symbols[CODE]) {
    // if (iswalpha(lexer->lookahead)) {
    //   while (iswalpha(lexer->lookahead)) {
    //     advance(lexer);
    //   }
    //
    //   skip_whitespace(lexer);
    //
    //   if (lexer->lookahead != '}') {
    //     return false;
    //   }
    // }
    //
    // lexer->mark_end(lexer);

    if (lexer->lookahead == '\0' || lexer->lookahead == '/') {
      return false;
    }

    if (lexer->lookahead == '}') {
      return false;
    }

    // We start in a code block, so we need to find the end of it
    int depth = 1;

    while (depth > 0) {
      if (lexer->eof(lexer)) {
        return false;
      }

      if (lexer->lookahead == '{') {
        advance(lexer);

        if (lexer->lookahead == '{') {
          advance(lexer);
          depth++;
        }
      } else if (lexer->lookahead == '}') {
        lexer->mark_end(lexer);
        advance(lexer);

        if (lexer->lookahead == '}') {
          advance(lexer);
          depth--;

          if (depth == 0) {
            lexer->result_symbol = CODE;
            return true;
          }
        }
      } else {
        const bool skip = iswspace(lexer->lookahead) || is_trim_marker(lexer->lookahead);
        advance(lexer);
        if (!skip) {
          lexer->mark_end(lexer);
        }
      }
    }

    return false;
  }

  return false;
}
