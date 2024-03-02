#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 10
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 12
#define ALIAS_COUNT 0
#define TOKEN_COUNT 7
#define EXTERNAL_TOKEN_COUNT 2
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  sym_close_tag = 1,
  aux_sym_content_token1 = 2,
  aux_sym_tag_token1 = 3,
  aux_sym_tag_token2 = 4,
  sym_code = 5,
  sym_comment = 6,
  sym_template = 7,
  sym__node = 8,
  sym_content = 9,
  sym_tag = 10,
  aux_sym_template_repeat1 = 11,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_close_tag] = "close_tag",
  [aux_sym_content_token1] = "content_token1",
  [aux_sym_tag_token1] = "tag_token1",
  [aux_sym_tag_token2] = "tag_token2",
  [sym_code] = "code",
  [sym_comment] = "comment",
  [sym_template] = "template",
  [sym__node] = "_node",
  [sym_content] = "content",
  [sym_tag] = "tag",
  [aux_sym_template_repeat1] = "template_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_close_tag] = sym_close_tag,
  [aux_sym_content_token1] = aux_sym_content_token1,
  [aux_sym_tag_token1] = aux_sym_tag_token1,
  [aux_sym_tag_token2] = aux_sym_tag_token2,
  [sym_code] = sym_code,
  [sym_comment] = sym_comment,
  [sym_template] = sym_template,
  [sym__node] = sym__node,
  [sym_content] = sym_content,
  [sym_tag] = sym_tag,
  [aux_sym_template_repeat1] = aux_sym_template_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_close_tag] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_content_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_tag_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_tag_token2] = {
    .visible = false,
    .named = false,
  },
  [sym_code] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_template] = {
    .visible = true,
    .named = true,
  },
  [sym__node] = {
    .visible = false,
    .named = true,
  },
  [sym_content] = {
    .visible = true,
    .named = true,
  },
  [sym_tag] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_template_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(6);
      if (lookahead == '-') ADVANCE(4);
      if (lookahead == '/') ADVANCE(7);
      if (lookahead == '{') ADVANCE(2);
      if (lookahead == '}') ADVANCE(3);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(1);
      END_STATE();
    case 1:
      if (lookahead == '-') ADVANCE(4);
      if (lookahead == '/') ADVANCE(7);
      if (lookahead == '{') ADVANCE(2);
      if (lookahead == '}') ADVANCE(3);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(1);
      END_STATE();
    case 2:
      if (lookahead == '{') ADVANCE(10);
      END_STATE();
    case 3:
      if (lookahead == '}') ADVANCE(12);
      END_STATE();
    case 4:
      if (lookahead == '}') ADVANCE(3);
      END_STATE();
    case 5:
      if (eof) ADVANCE(6);
      if (lookahead == '{') ADVANCE(2);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(8);
      if (lookahead != 0 &&
          lookahead != '(' &&
          lookahead != ')') ADVANCE(9);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(sym_close_tag);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(aux_sym_content_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(8);
      if (lookahead != 0 &&
          lookahead != '(' &&
          lookahead != ')' &&
          lookahead != '{') ADVANCE(9);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(aux_sym_content_token1);
      if (lookahead != 0 &&
          lookahead != '(' &&
          lookahead != ')' &&
          lookahead != '{') ADVANCE(9);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(aux_sym_tag_token1);
      if (lookahead == '-') ADVANCE(11);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(11);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(aux_sym_tag_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(11);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(aux_sym_tag_token2);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 5},
  [2] = {.lex_state = 5},
  [3] = {.lex_state = 5},
  [4] = {.lex_state = 0, .external_lex_state = 1},
  [5] = {.lex_state = 5},
  [6] = {.lex_state = 5},
  [7] = {.lex_state = 5},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_close_tag] = ACTIONS(1),
    [aux_sym_tag_token1] = ACTIONS(1),
    [aux_sym_tag_token2] = ACTIONS(1),
    [sym_code] = ACTIONS(1),
    [sym_comment] = ACTIONS(1),
  },
  [1] = {
    [sym_template] = STATE(8),
    [sym_content] = STATE(2),
    [sym_tag] = STATE(2),
    [aux_sym_template_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(3),
    [aux_sym_content_token1] = ACTIONS(5),
    [aux_sym_tag_token1] = ACTIONS(7),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 4,
    ACTIONS(5), 1,
      aux_sym_content_token1,
    ACTIONS(7), 1,
      aux_sym_tag_token1,
    ACTIONS(9), 1,
      ts_builtin_sym_end,
    STATE(3), 3,
      sym_content,
      sym_tag,
      aux_sym_template_repeat1,
  [15] = 4,
    ACTIONS(11), 1,
      ts_builtin_sym_end,
    ACTIONS(13), 1,
      aux_sym_content_token1,
    ACTIONS(16), 1,
      aux_sym_tag_token1,
    STATE(3), 3,
      sym_content,
      sym_tag,
      aux_sym_template_repeat1,
  [30] = 3,
    ACTIONS(21), 1,
      aux_sym_tag_token2,
    STATE(9), 1,
      sym__node,
    ACTIONS(19), 3,
      sym_code,
      sym_comment,
      sym_close_tag,
  [42] = 2,
    ACTIONS(25), 1,
      aux_sym_tag_token1,
    ACTIONS(23), 2,
      ts_builtin_sym_end,
      aux_sym_content_token1,
  [50] = 2,
    ACTIONS(29), 1,
      aux_sym_tag_token1,
    ACTIONS(27), 2,
      ts_builtin_sym_end,
      aux_sym_content_token1,
  [58] = 2,
    ACTIONS(33), 1,
      aux_sym_tag_token1,
    ACTIONS(31), 2,
      ts_builtin_sym_end,
      aux_sym_content_token1,
  [66] = 1,
    ACTIONS(35), 1,
      ts_builtin_sym_end,
  [70] = 1,
    ACTIONS(37), 1,
      aux_sym_tag_token2,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 15,
  [SMALL_STATE(4)] = 30,
  [SMALL_STATE(5)] = 42,
  [SMALL_STATE(6)] = 50,
  [SMALL_STATE(7)] = 58,
  [SMALL_STATE(8)] = 66,
  [SMALL_STATE(9)] = 70,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_template, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [9] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_template, 1),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_template_repeat1, 2),
  [13] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_template_repeat1, 2), SHIFT_REPEAT(5),
  [16] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_template_repeat1, 2), SHIFT_REPEAT(4),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_content, 1),
  [25] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_content, 1),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tag, 2),
  [29] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tag, 2),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tag, 3),
  [33] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tag, 3),
  [35] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
};

enum ts_external_scanner_symbol_identifiers {
  ts_external_token_code = 0,
  ts_external_token_comment = 1,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token_code] = sym_code,
  [ts_external_token_comment] = sym_comment,
};

static const bool ts_external_scanner_states[2][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token_code] = true,
    [ts_external_token_comment] = true,
  },
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_vento_external_scanner_create(void);
void tree_sitter_vento_external_scanner_destroy(void *);
bool tree_sitter_vento_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_vento_external_scanner_serialize(void *, char *);
void tree_sitter_vento_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_vento(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .external_scanner = {
      &ts_external_scanner_states[0][0],
      ts_external_scanner_symbol_map,
      tree_sitter_vento_external_scanner_create,
      tree_sitter_vento_external_scanner_destroy,
      tree_sitter_vento_external_scanner_scan,
      tree_sitter_vento_external_scanner_serialize,
      tree_sitter_vento_external_scanner_deserialize,
    },
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
