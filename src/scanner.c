#include <ctype.h>
#include "tree_sitter/parser.h"

enum TokenType {
  CODE,
  COMMENT,
};

void *tree_sitter_vento_external_scanner_create() {
  return NULL;
}

void tree_sitter_vento_external_scanner_destroy(void *payload) {
  // No memory to free
}

unsigned tree_sitter_vento_external_scanner_serialize(
  void *payload,
  char *buffer
) {
  // No state to serialize
  return 0;
}

void tree_sitter_vento_external_scanner_deserialize(
  void *payload,
  const char *buffer,
  unsigned length
) {
  // No state to deserialize
}

bool is_trim_marker(char c) {
  switch (c) {
    case '-':
      return true;
    default:
      return false;
  };
}

bool is_whitespace(char c) {
  switch (c) {
    case ' ':
    case '\t':
    case '\n':
    case '\r':
      return true;
    default:
      return false;
  };
}

bool tree_sitter_vento_external_scanner_scan(
  void *payload,
  TSLexer *lexer,
  const bool *valid_symbols
) {
  // code }}

  if (valid_symbols[CODE] || valid_symbols[COMMENT]) {
    TSSymbol symbol = CODE;

    if (lexer->lookahead == '#') {
      symbol = COMMENT;
    }

    // We start in a code block, so we need to find the end of it
    int depth = 1;

    while (depth > 0) {
      if (lexer->eof(lexer)) {
        lexer->result_symbol = symbol;
        return true;
      }

      if (lexer->lookahead == '{') {
        lexer->advance(lexer, false);

        if (lexer->lookahead == '{') {
          lexer->advance(lexer, false);
          depth++;
        }
      } else if (lexer->lookahead == '}') {
        lexer->advance(lexer, false);

        if (lexer->lookahead == '}') {
          lexer->advance(lexer, false);
          depth--;

          if (depth == 0) {
            lexer->result_symbol = symbol;
            return true;
          }
        }
      } else {
        const bool skip = is_whitespace(lexer) || is_trim_marker(lexer);
        lexer->advance(lexer, false);
        if (!skip) {
          lexer->mark_end(lexer);
        }
      }
    }
  }

  return false;
}
