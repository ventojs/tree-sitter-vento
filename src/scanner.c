#include "tree_sitter/parser.h"
#include <wctype.h>
#include <stdio.h>

enum TokenType {
  CODE,
  FRONT_MATTER_CONTENT,
};

void *tree_sitter_vento_external_scanner_create() { return NULL; }
void tree_sitter_vento_external_scanner_destroy(void *payload) {}
unsigned tree_sitter_vento_external_scanner_serialize( void *payload, char *buffer) { return 0; }
void tree_sitter_vento_external_scanner_deserialize( void *payload, const char *buffer, unsigned length) {}

static void skip_whitespace(TSLexer *lexer) {
  while (iswspace(lexer->lookahead)) {
    lexer->advance(lexer, true);
  }
}

bool tree_sitter_vento_external_scanner_scan(
  void *payload,
  TSLexer *lexer,
  const bool *valid_symbols
) {
  
  if (valid_symbols[FRONT_MATTER_CONTENT]) {
    // Match everything until we hit \n--- (closing front matter delimiter)
    // This should match content between opening --- and closing ---
    
    while (!lexer->eof(lexer)) {
      if (lexer->lookahead == '\n') {
        // Mark end before the newline in case this is before closing ---
        lexer->mark_end(lexer);
        lexer->advance(lexer, false);
        
        // Check if next line starts with ---
        if (lexer->lookahead == '-') {
          lexer->advance(lexer, false);
          if (lexer->lookahead == '-') {
            lexer->advance(lexer, false);
            if (lexer->lookahead == '-') {
              // Found closing ---, return the content we've collected
              lexer->result_symbol = FRONT_MATTER_CONTENT;
              return true;
            }
          }
        }
      } else {
        lexer->advance(lexer, false);
      }
    }
    
    // Reached EOF without finding closing ---, not valid front matter
    return false;
  }
  
  skip_whitespace(lexer);

  if (valid_symbols[CODE]) {

    if (lexer->eof(lexer) ||
        lexer->lookahead == '/' ||
        lexer->lookahead == '-' ||
        lexer->lookahead == '}') {
      return false;
    }

    // We start in a code block, so we need to find the end of it
    uint32_t depth = 1;

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
      } else if (iswspace(lexer->lookahead)) {
        // Check for ' of ' keyword pattern
        lexer->advance(lexer, false);
        
        if (lexer->lookahead == 'o') {
          lexer->mark_end(lexer);
          lexer->advance(lexer, false);
          
          if (lexer->lookahead == 'f') {
            lexer->advance(lexer, false);
            
            if (iswspace(lexer->lookahead)) {
              // Found ' of ' pattern, stop here
              lexer->result_symbol = CODE;
              return true;
            }
          }
        }
      } else {
        const bool skip = lexer->lookahead == '-';
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
