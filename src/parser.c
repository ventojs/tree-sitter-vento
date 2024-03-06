#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 21
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 20
#define ALIAS_COUNT 0
#define TOKEN_COUNT 12
#define EXTERNAL_TOKEN_COUNT 2
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 2

enum ts_symbol_identifiers {
  aux_sym_content_token1 = 1,
  sym_keyword = 2,
  sym_codeSnippet = 3,
  sym_close_keyword = 4,
  anon_sym_LBRACE_LBRACE = 5,
  anon_sym_LBRACE_LBRACE_DASH = 6,
  anon_sym_RBRACE_RBRACE = 7,
  anon_sym_DASH_RBRACE_RBRACE = 8,
  anon_sym_PIPE_GT = 9,
  sym_comment = 10,
  sym_code = 11,
  sym_template = 12,
  sym_content = 13,
  sym__expression = 14,
  sym_tag = 15,
  sym_filter = 16,
  sym_comment_tag = 17,
  aux_sym_template_repeat1 = 18,
  aux_sym_filter_repeat1 = 19,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [aux_sym_content_token1] = "content_token1",
  [sym_keyword] = "keyword",
  [sym_codeSnippet] = "code",
  [sym_close_keyword] = "keyword",
  [anon_sym_LBRACE_LBRACE] = "{{",
  [anon_sym_LBRACE_LBRACE_DASH] = "{{-",
  [anon_sym_RBRACE_RBRACE] = "}}",
  [anon_sym_DASH_RBRACE_RBRACE] = "-}}",
  [anon_sym_PIPE_GT] = "|>",
  [sym_comment] = "comment",
  [sym_code] = "code",
  [sym_template] = "template",
  [sym_content] = "content",
  [sym__expression] = "_expression",
  [sym_tag] = "tag",
  [sym_filter] = "filter",
  [sym_comment_tag] = "tag",
  [aux_sym_template_repeat1] = "template_repeat1",
  [aux_sym_filter_repeat1] = "filter_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [aux_sym_content_token1] = aux_sym_content_token1,
  [sym_keyword] = sym_keyword,
  [sym_codeSnippet] = sym_code,
  [sym_close_keyword] = sym_keyword,
  [anon_sym_LBRACE_LBRACE] = anon_sym_LBRACE_LBRACE,
  [anon_sym_LBRACE_LBRACE_DASH] = anon_sym_LBRACE_LBRACE_DASH,
  [anon_sym_RBRACE_RBRACE] = anon_sym_RBRACE_RBRACE,
  [anon_sym_DASH_RBRACE_RBRACE] = anon_sym_DASH_RBRACE_RBRACE,
  [anon_sym_PIPE_GT] = anon_sym_PIPE_GT,
  [sym_comment] = sym_comment,
  [sym_code] = sym_code,
  [sym_template] = sym_template,
  [sym_content] = sym_content,
  [sym__expression] = sym__expression,
  [sym_tag] = sym_tag,
  [sym_filter] = sym_filter,
  [sym_comment_tag] = sym_tag,
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
  [sym_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_codeSnippet] = {
    .visible = true,
    .named = true,
  },
  [sym_close_keyword] = {
    .visible = true,
    .named = true,
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
  [sym__expression] = {
    .visible = false,
    .named = true,
  },
  [sym_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_filter] = {
    .visible = true,
    .named = true,
  },
  [sym_comment_tag] = {
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
  [19] = 19,
  [20] = 20,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(19);
      if (lookahead == '#') ADVANCE(15);
      if (lookahead == '-') ADVANCE(10);
      if (lookahead == '/') ADVANCE(17);
      if (lookahead == '{') ADVANCE(9);
      if (lookahead == '|') ADVANCE(7);
      if (lookahead == '}') ADVANCE(11);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(1);
      if (lookahead != 0) ADVANCE(16);
      END_STATE();
    case 1:
      if (lookahead == '#') ADVANCE(15);
      if (lookahead == '-') ADVANCE(10);
      if (lookahead == '/') ADVANCE(17);
      if (lookahead == '{') ADVANCE(9);
      if (lookahead == '|') ADVANCE(7);
      if (lookahead == '}') ADVANCE(11);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(1);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(24);
      if (lookahead != 0) ADVANCE(16);
      END_STATE();
    case 2:
      if (lookahead == '#') ADVANCE(35);
      if (lookahead != 0) ADVANCE(2);
      END_STATE();
    case 3:
      if (lookahead == '#') ADVANCE(13);
      if (lookahead == '/') ADVANCE(17);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(4);
      if (lookahead != 0) ADVANCE(14);
      END_STATE();
    case 4:
      if (lookahead == '#') ADVANCE(13);
      if (lookahead == '/') ADVANCE(17);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(26);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(23);
      if (lookahead != 0) ADVANCE(14);
      END_STATE();
    case 5:
      if (lookahead == '/') ADVANCE(17);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(6);
      if (lookahead != 0) ADVANCE(14);
      END_STATE();
    case 6:
      if (lookahead == '/') ADVANCE(17);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(28);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(23);
      if (lookahead != 0) ADVANCE(14);
      END_STATE();
    case 7:
      if (lookahead == '>') ADVANCE(34);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(24);
      END_STATE();
    case 8:
      if (lookahead == '{') ADVANCE(30);
      END_STATE();
    case 9:
      if (lookahead == '{') ADVANCE(30);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(24);
      END_STATE();
    case 10:
      if (lookahead == '}') ADVANCE(12);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(24);
      END_STATE();
    case 11:
      if (lookahead == '}') ADVANCE(32);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(24);
      END_STATE();
    case 12:
      if (lookahead == '}') ADVANCE(33);
      END_STATE();
    case 13:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(25);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(22);
      if (lookahead != 0 &&
          lookahead != '#') ADVANCE(2);
      END_STATE();
    case 14:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(27);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(24);
      END_STATE();
    case 15:
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(22);
      if (lookahead != 0 &&
          lookahead != '#') ADVANCE(2);
      END_STATE();
    case 16:
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(24);
      END_STATE();
    case 17:
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(29);
      END_STATE();
    case 18:
      if (eof) ADVANCE(19);
      if (lookahead == '{') ADVANCE(8);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(20);
      if (lookahead != 0 &&
          lookahead != '(' &&
          lookahead != ')') ADVANCE(21);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(aux_sym_content_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(20);
      if (lookahead != 0 &&
          lookahead != '(' &&
          lookahead != ')' &&
          lookahead != '{') ADVANCE(21);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(aux_sym_content_token1);
      if (lookahead != 0 &&
          lookahead != '(' &&
          lookahead != ')' &&
          lookahead != '{') ADVANCE(21);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(sym_keyword);
      if (lookahead == '#') ADVANCE(35);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(22);
      if (lookahead != 0) ADVANCE(2);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(sym_keyword);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(27);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(24);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(sym_keyword);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(24);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(sym_codeSnippet);
      if (lookahead == '#') ADVANCE(35);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(25);
      if (lookahead != 0) ADVANCE(2);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(sym_codeSnippet);
      if (lookahead == '#') ADVANCE(13);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(26);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(23);
      if (lookahead != 0 &&
          lookahead != '/') ADVANCE(14);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(sym_codeSnippet);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(27);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(sym_codeSnippet);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(28);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(23);
      if (lookahead != 0 &&
          lookahead != '/') ADVANCE(14);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym_close_keyword);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(29);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_LBRACE_LBRACE);
      if (lookahead == '-') ADVANCE(31);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_LBRACE_LBRACE_DASH);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_RBRACE_RBRACE);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_DASH_RBRACE_RBRACE);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(anon_sym_PIPE_GT);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym_comment);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 18},
  [2] = {.lex_state = 18},
  [3] = {.lex_state = 18},
  [4] = {.lex_state = 3, .external_lex_state = 2},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 18},
  [7] = {.lex_state = 18},
  [8] = {.lex_state = 5, .external_lex_state = 2},
  [9] = {.lex_state = 0, .external_lex_state = 3},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 18},
  [12] = {.lex_state = 18},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0, .external_lex_state = 3},
  [20] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_keyword] = ACTIONS(1),
    [sym_close_keyword] = ACTIONS(1),
    [anon_sym_LBRACE_LBRACE] = ACTIONS(1),
    [anon_sym_LBRACE_LBRACE_DASH] = ACTIONS(1),
    [anon_sym_RBRACE_RBRACE] = ACTIONS(1),
    [anon_sym_DASH_RBRACE_RBRACE] = ACTIONS(1),
    [anon_sym_PIPE_GT] = ACTIONS(1),
    [sym_comment] = ACTIONS(1),
    [sym_code] = ACTIONS(1),
  },
  [1] = {
    [sym_template] = STATE(18),
    [sym_content] = STATE(2),
    [sym_tag] = STATE(2),
    [sym_comment_tag] = STATE(2),
    [aux_sym_template_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(3),
    [aux_sym_content_token1] = ACTIONS(5),
    [anon_sym_LBRACE_LBRACE] = ACTIONS(7),
    [anon_sym_LBRACE_LBRACE_DASH] = ACTIONS(9),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 5,
    ACTIONS(5), 1,
      aux_sym_content_token1,
    ACTIONS(7), 1,
      anon_sym_LBRACE_LBRACE,
    ACTIONS(9), 1,
      anon_sym_LBRACE_LBRACE_DASH,
    ACTIONS(11), 1,
      ts_builtin_sym_end,
    STATE(3), 4,
      sym_content,
      sym_tag,
      sym_comment_tag,
      aux_sym_template_repeat1,
  [19] = 5,
    ACTIONS(13), 1,
      ts_builtin_sym_end,
    ACTIONS(15), 1,
      aux_sym_content_token1,
    ACTIONS(18), 1,
      anon_sym_LBRACE_LBRACE,
    ACTIONS(21), 1,
      anon_sym_LBRACE_LBRACE_DASH,
    STATE(3), 4,
      sym_content,
      sym_tag,
      sym_comment_tag,
      aux_sym_template_repeat1,
  [38] = 5,
    ACTIONS(24), 1,
      sym_keyword,
    ACTIONS(26), 1,
      sym_codeSnippet,
    ACTIONS(28), 1,
      sym_close_keyword,
    ACTIONS(30), 1,
      sym_comment,
    STATE(5), 1,
      sym__expression,
  [54] = 4,
    ACTIONS(34), 1,
      anon_sym_PIPE_GT,
    STATE(13), 1,
      aux_sym_filter_repeat1,
    STATE(17), 1,
      sym_filter,
    ACTIONS(32), 2,
      anon_sym_RBRACE_RBRACE,
      anon_sym_DASH_RBRACE_RBRACE,
  [68] = 2,
    ACTIONS(36), 2,
      ts_builtin_sym_end,
      aux_sym_content_token1,
    ACTIONS(38), 2,
      anon_sym_LBRACE_LBRACE,
      anon_sym_LBRACE_LBRACE_DASH,
  [77] = 2,
    ACTIONS(40), 2,
      ts_builtin_sym_end,
      aux_sym_content_token1,
    ACTIONS(42), 2,
      anon_sym_LBRACE_LBRACE,
      anon_sym_LBRACE_LBRACE_DASH,
  [86] = 4,
    ACTIONS(24), 1,
      sym_keyword,
    ACTIONS(28), 1,
      sym_close_keyword,
    ACTIONS(44), 1,
      sym_codeSnippet,
    STATE(5), 1,
      sym__expression,
  [99] = 2,
    ACTIONS(48), 1,
      sym_code,
    ACTIONS(46), 3,
      anon_sym_RBRACE_RBRACE,
      anon_sym_DASH_RBRACE_RBRACE,
      anon_sym_PIPE_GT,
  [108] = 3,
    ACTIONS(52), 1,
      anon_sym_PIPE_GT,
    STATE(10), 1,
      aux_sym_filter_repeat1,
    ACTIONS(50), 2,
      anon_sym_RBRACE_RBRACE,
      anon_sym_DASH_RBRACE_RBRACE,
  [119] = 2,
    ACTIONS(55), 2,
      ts_builtin_sym_end,
      aux_sym_content_token1,
    ACTIONS(57), 2,
      anon_sym_LBRACE_LBRACE,
      anon_sym_LBRACE_LBRACE_DASH,
  [128] = 2,
    ACTIONS(59), 2,
      ts_builtin_sym_end,
      aux_sym_content_token1,
    ACTIONS(61), 2,
      anon_sym_LBRACE_LBRACE,
      anon_sym_LBRACE_LBRACE_DASH,
  [137] = 3,
    ACTIONS(34), 1,
      anon_sym_PIPE_GT,
    STATE(10), 1,
      aux_sym_filter_repeat1,
    ACTIONS(63), 2,
      anon_sym_RBRACE_RBRACE,
      anon_sym_DASH_RBRACE_RBRACE,
  [148] = 1,
    ACTIONS(46), 3,
      anon_sym_RBRACE_RBRACE,
      anon_sym_DASH_RBRACE_RBRACE,
      anon_sym_PIPE_GT,
  [154] = 1,
    ACTIONS(65), 3,
      anon_sym_RBRACE_RBRACE,
      anon_sym_DASH_RBRACE_RBRACE,
      anon_sym_PIPE_GT,
  [160] = 1,
    ACTIONS(50), 3,
      anon_sym_RBRACE_RBRACE,
      anon_sym_DASH_RBRACE_RBRACE,
      anon_sym_PIPE_GT,
  [166] = 1,
    ACTIONS(67), 2,
      anon_sym_RBRACE_RBRACE,
      anon_sym_DASH_RBRACE_RBRACE,
  [171] = 1,
    ACTIONS(69), 1,
      ts_builtin_sym_end,
  [175] = 1,
    ACTIONS(71), 1,
      sym_code,
  [179] = 1,
    ACTIONS(73), 1,
      anon_sym_RBRACE_RBRACE,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 19,
  [SMALL_STATE(4)] = 38,
  [SMALL_STATE(5)] = 54,
  [SMALL_STATE(6)] = 68,
  [SMALL_STATE(7)] = 77,
  [SMALL_STATE(8)] = 86,
  [SMALL_STATE(9)] = 99,
  [SMALL_STATE(10)] = 108,
  [SMALL_STATE(11)] = 119,
  [SMALL_STATE(12)] = 128,
  [SMALL_STATE(13)] = 137,
  [SMALL_STATE(14)] = 148,
  [SMALL_STATE(15)] = 154,
  [SMALL_STATE(16)] = 160,
  [SMALL_STATE(17)] = 166,
  [SMALL_STATE(18)] = 171,
  [SMALL_STATE(19)] = 175,
  [SMALL_STATE(20)] = 179,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_template, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_template, 1),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_template_repeat1, 2),
  [15] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_template_repeat1, 2), SHIFT_REPEAT(7),
  [18] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_template_repeat1, 2), SHIFT_REPEAT(4),
  [21] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_template_repeat1, 2), SHIFT_REPEAT(8),
  [24] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [26] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [28] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [30] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [32] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [34] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [36] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tag, 4),
  [38] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tag, 4),
  [40] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_content, 1),
  [42] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_content, 1),
  [44] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [46] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expression, 1, .production_id = 1),
  [48] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [50] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_filter_repeat1, 2),
  [52] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_filter_repeat1, 2), SHIFT_REPEAT(19),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment_tag, 3),
  [57] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_comment_tag, 3),
  [59] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tag, 3),
  [61] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tag, 3),
  [63] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_filter, 1),
  [65] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expression, 2),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [69] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [73] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
};

enum ts_external_scanner_symbol_identifiers {
  ts_external_token_code = 0,
  ts_external_token_keyword = 1,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token_code] = sym_code,
  [ts_external_token_keyword] = sym_keyword,
};

static const bool ts_external_scanner_states[4][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token_code] = true,
    [ts_external_token_keyword] = true,
  },
  [2] = {
    [ts_external_token_keyword] = true,
  },
  [3] = {
    [ts_external_token_code] = true,
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
