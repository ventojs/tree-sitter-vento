#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 19
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 18
#define ALIAS_COUNT 0
#define TOKEN_COUNT 11
#define EXTERNAL_TOKEN_COUNT 1
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 2

enum {
  aux_sym_content_token1 = 1,
  anon_sym_LBRACE_LBRACE = 2,
  anon_sym_LBRACE_LBRACE_DASH = 3,
  anon_sym_RBRACE_RBRACE = 4,
  anon_sym_DASH_RBRACE_RBRACE = 5,
  sym_keyword = 6,
  sym_close_keyword = 7,
  anon_sym_PIPE_GT = 8,
  sym_comment = 9,
  sym_code = 10,
  sym_template = 11,
  sym_content = 12,
  sym_tag = 13,
  sym__expression = 14,
  sym_filter = 15,
  aux_sym_template_repeat1 = 16,
  aux_sym_filter_repeat1 = 17,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [aux_sym_content_token1] = "content_token1",
  [anon_sym_LBRACE_LBRACE] = "{{",
  [anon_sym_LBRACE_LBRACE_DASH] = "{{-",
  [anon_sym_RBRACE_RBRACE] = "}}",
  [anon_sym_DASH_RBRACE_RBRACE] = "-}}",
  [sym_keyword] = "keyword",
  [sym_close_keyword] = "keyword",
  [anon_sym_PIPE_GT] = "|>",
  [sym_comment] = "comment",
  [sym_code] = "code",
  [sym_template] = "template",
  [sym_content] = "content",
  [sym_tag] = "tag",
  [sym__expression] = "_expression",
  [sym_filter] = "filter",
  [aux_sym_template_repeat1] = "template_repeat1",
  [aux_sym_filter_repeat1] = "filter_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [aux_sym_content_token1] = aux_sym_content_token1,
  [anon_sym_LBRACE_LBRACE] = anon_sym_LBRACE_LBRACE,
  [anon_sym_LBRACE_LBRACE_DASH] = anon_sym_LBRACE_LBRACE_DASH,
  [anon_sym_RBRACE_RBRACE] = anon_sym_RBRACE_RBRACE,
  [anon_sym_DASH_RBRACE_RBRACE] = anon_sym_DASH_RBRACE_RBRACE,
  [sym_keyword] = sym_keyword,
  [sym_close_keyword] = sym_keyword,
  [anon_sym_PIPE_GT] = anon_sym_PIPE_GT,
  [sym_comment] = sym_comment,
  [sym_code] = sym_code,
  [sym_template] = sym_template,
  [sym_content] = sym_content,
  [sym_tag] = sym_tag,
  [sym__expression] = sym__expression,
  [sym_filter] = sym_filter,
  [aux_sym_template_repeat1] = aux_sym_template_repeat1,
  [aux_sym_filter_repeat1] = aux_sym_filter_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [aux_sym_content_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_LBRACE_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE_LBRACE_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_RBRACE_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [sym_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_close_keyword] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_PIPE_GT] = {
    .visible = true,
    .named = false,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_code] = {
    .visible = true,
    .named = true,
  },
  [sym_template] = {
    .visible = true,
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
  [sym__expression] = {
    .visible = false,
    .named = true,
  },
  [sym_filter] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_template_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_filter_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [1] = {
    [0] = sym_code,
  },
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
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(10);
      if (lookahead == '#') ADVANCE(8);
      if (lookahead == '-') ADVANCE(6);
      if (lookahead == '/') ADVANCE(7);
      if (lookahead == '{') ADVANCE(3);
      if (lookahead == '|') ADVANCE(2);
      if (lookahead == '}') ADVANCE(4);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (lookahead == '>' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(17);
      END_STATE();
    case 1:
      if (lookahead == '#') ADVANCE(20);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 2:
      if (lookahead == '>') ADVANCE(19);
      END_STATE();
    case 3:
      if (lookahead == '{') ADVANCE(13);
      END_STATE();
    case 4:
      if (lookahead == '}') ADVANCE(15);
      END_STATE();
    case 5:
      if (lookahead == '}') ADVANCE(16);
      END_STATE();
    case 6:
      if (lookahead == '}') ADVANCE(5);
      END_STATE();
    case 7:
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(18);
      END_STATE();
    case 8:
      if (lookahead != 0 &&
          lookahead != '#') ADVANCE(1);
      END_STATE();
    case 9:
      if (eof) ADVANCE(10);
      if (lookahead == '{') ADVANCE(3);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(11);
      if (lookahead != 0 &&
          lookahead != '(' &&
          lookahead != ')') ADVANCE(12);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(aux_sym_content_token1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(11);
      if (lookahead != 0 &&
          lookahead != '(' &&
          lookahead != ')' &&
          lookahead != '{') ADVANCE(12);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(aux_sym_content_token1);
      if (lookahead != 0 &&
          lookahead != '(' &&
          lookahead != ')' &&
          lookahead != '{') ADVANCE(12);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(anon_sym_LBRACE_LBRACE);
      if (lookahead == '-') ADVANCE(14);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(anon_sym_LBRACE_LBRACE_DASH);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(anon_sym_RBRACE_RBRACE);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(anon_sym_DASH_RBRACE_RBRACE);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(sym_keyword);
      if (lookahead == '>' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(17);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(sym_close_keyword);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(18);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_PIPE_GT);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(sym_comment);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 9},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 9},
  [4] = {.lex_state = 9},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 9},
  [7] = {.lex_state = 9},
  [8] = {.lex_state = 0, .external_lex_state = 1},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 9},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 9},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0, .external_lex_state = 1},
};

enum {
  ts_external_token_code = 0,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token_code] = sym_code,
};

static const bool ts_external_scanner_states[2][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token_code] = true,
  },
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_LBRACE_LBRACE] = ACTIONS(1),
    [anon_sym_LBRACE_LBRACE_DASH] = ACTIONS(1),
    [anon_sym_RBRACE_RBRACE] = ACTIONS(1),
    [anon_sym_DASH_RBRACE_RBRACE] = ACTIONS(1),
    [sym_keyword] = ACTIONS(1),
    [sym_close_keyword] = ACTIONS(1),
    [anon_sym_PIPE_GT] = ACTIONS(1),
    [sym_comment] = ACTIONS(1),
    [sym_code] = ACTIONS(1),
  },
  [1] = {
    [sym_template] = STATE(17),
    [sym_content] = STATE(3),
    [sym_tag] = STATE(3),
    [aux_sym_template_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(3),
    [aux_sym_content_token1] = ACTIONS(5),
    [anon_sym_LBRACE_LBRACE] = ACTIONS(7),
    [anon_sym_LBRACE_LBRACE_DASH] = ACTIONS(7),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 7,
    ACTIONS(11), 1,
      sym_keyword,
    ACTIONS(15), 1,
      anon_sym_PIPE_GT,
    STATE(5), 1,
      sym__expression,
    STATE(9), 1,
      aux_sym_filter_repeat1,
    STATE(15), 1,
      sym_filter,
    ACTIONS(9), 2,
      anon_sym_RBRACE_RBRACE,
      anon_sym_DASH_RBRACE_RBRACE,
    ACTIONS(13), 2,
      sym_close_keyword,
      sym_comment,
  [24] = 4,
    ACTIONS(5), 1,
      aux_sym_content_token1,
    ACTIONS(17), 1,
      ts_builtin_sym_end,
    ACTIONS(7), 2,
      anon_sym_LBRACE_LBRACE,
      anon_sym_LBRACE_LBRACE_DASH,
    STATE(4), 3,
      sym_content,
      sym_tag,
      aux_sym_template_repeat1,
  [40] = 4,
    ACTIONS(19), 1,
      ts_builtin_sym_end,
    ACTIONS(21), 1,
      aux_sym_content_token1,
    ACTIONS(24), 2,
      anon_sym_LBRACE_LBRACE,
      anon_sym_LBRACE_LBRACE_DASH,
    STATE(4), 3,
      sym_content,
      sym_tag,
      aux_sym_template_repeat1,
  [56] = 4,
    ACTIONS(15), 1,
      anon_sym_PIPE_GT,
    STATE(9), 1,
      aux_sym_filter_repeat1,
    STATE(16), 1,
      sym_filter,
    ACTIONS(27), 2,
      anon_sym_RBRACE_RBRACE,
      anon_sym_DASH_RBRACE_RBRACE,
  [70] = 2,
    ACTIONS(29), 2,
      ts_builtin_sym_end,
      aux_sym_content_token1,
    ACTIONS(31), 2,
      anon_sym_LBRACE_LBRACE,
      anon_sym_LBRACE_LBRACE_DASH,
  [79] = 2,
    ACTIONS(33), 2,
      ts_builtin_sym_end,
      aux_sym_content_token1,
    ACTIONS(35), 2,
      anon_sym_LBRACE_LBRACE,
      anon_sym_LBRACE_LBRACE_DASH,
  [88] = 2,
    ACTIONS(39), 1,
      sym_code,
    ACTIONS(37), 3,
      anon_sym_RBRACE_RBRACE,
      anon_sym_DASH_RBRACE_RBRACE,
      anon_sym_PIPE_GT,
  [97] = 3,
    ACTIONS(15), 1,
      anon_sym_PIPE_GT,
    STATE(11), 1,
      aux_sym_filter_repeat1,
    ACTIONS(41), 2,
      anon_sym_RBRACE_RBRACE,
      anon_sym_DASH_RBRACE_RBRACE,
  [108] = 2,
    ACTIONS(43), 2,
      ts_builtin_sym_end,
      aux_sym_content_token1,
    ACTIONS(45), 2,
      anon_sym_LBRACE_LBRACE,
      anon_sym_LBRACE_LBRACE_DASH,
  [117] = 3,
    ACTIONS(49), 1,
      anon_sym_PIPE_GT,
    STATE(11), 1,
      aux_sym_filter_repeat1,
    ACTIONS(47), 2,
      anon_sym_RBRACE_RBRACE,
      anon_sym_DASH_RBRACE_RBRACE,
  [128] = 2,
    ACTIONS(52), 2,
      ts_builtin_sym_end,
      aux_sym_content_token1,
    ACTIONS(54), 2,
      anon_sym_LBRACE_LBRACE,
      anon_sym_LBRACE_LBRACE_DASH,
  [137] = 1,
    ACTIONS(56), 3,
      anon_sym_RBRACE_RBRACE,
      anon_sym_DASH_RBRACE_RBRACE,
      anon_sym_PIPE_GT,
  [143] = 1,
    ACTIONS(47), 3,
      anon_sym_RBRACE_RBRACE,
      anon_sym_DASH_RBRACE_RBRACE,
      anon_sym_PIPE_GT,
  [149] = 1,
    ACTIONS(27), 2,
      anon_sym_RBRACE_RBRACE,
      anon_sym_DASH_RBRACE_RBRACE,
  [154] = 1,
    ACTIONS(58), 2,
      anon_sym_RBRACE_RBRACE,
      anon_sym_DASH_RBRACE_RBRACE,
  [159] = 1,
    ACTIONS(60), 1,
      ts_builtin_sym_end,
  [163] = 1,
    ACTIONS(62), 1,
      sym_code,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 24,
  [SMALL_STATE(4)] = 40,
  [SMALL_STATE(5)] = 56,
  [SMALL_STATE(6)] = 70,
  [SMALL_STATE(7)] = 79,
  [SMALL_STATE(8)] = 88,
  [SMALL_STATE(9)] = 97,
  [SMALL_STATE(10)] = 108,
  [SMALL_STATE(11)] = 117,
  [SMALL_STATE(12)] = 128,
  [SMALL_STATE(13)] = 137,
  [SMALL_STATE(14)] = 143,
  [SMALL_STATE(15)] = 149,
  [SMALL_STATE(16)] = 154,
  [SMALL_STATE(17)] = 159,
  [SMALL_STATE(18)] = 163,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_template, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_template, 1),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_template_repeat1, 2),
  [21] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_template_repeat1, 2), SHIFT_REPEAT(6),
  [24] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_template_repeat1, 2), SHIFT_REPEAT(2),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_content, 1),
  [31] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_content, 1),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tag, 2),
  [35] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tag, 2),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expression, 1, .production_id = 1),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_filter, 1),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tag, 3),
  [45] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tag, 3),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_filter_repeat1, 2),
  [49] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_filter_repeat1, 2), SHIFT_REPEAT(18),
  [52] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tag, 4),
  [54] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tag, 4),
  [56] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expression, 2),
  [58] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [60] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [62] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
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
