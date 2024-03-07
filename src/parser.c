#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 23
#define LARGE_STATE_COUNT 3
#define SYMBOL_COUNT 21
#define ALIAS_COUNT 0
#define TOKEN_COUNT 12
#define EXTERNAL_TOKEN_COUNT 1
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 3

enum ts_symbol_identifiers {
  aux_sym_content_token1 = 1,
  anon_sym_LBRACE_LBRACE = 2,
  anon_sym_LBRACE_LBRACE_DASH = 3,
  anon_sym_RBRACE_RBRACE = 4,
  anon_sym_DASH_RBRACE_RBRACE = 5,
  sym_keyword = 6,
  aux_sym_code_snippet_token1 = 7,
  sym_close_keyword = 8,
  anon_sym_PIPE_GT = 9,
  sym_comment = 10,
  sym__code = 11,
  sym_template = 12,
  sym_content = 13,
  sym_tag = 14,
  sym__expression = 15,
  sym_code_snippet = 16,
  sym_filter = 17,
  aux_sym_template_repeat1 = 18,
  aux_sym_content_repeat1 = 19,
  aux_sym_filter_repeat1 = 20,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [aux_sym_content_token1] = "content_token1",
  [anon_sym_LBRACE_LBRACE] = "{{",
  [anon_sym_LBRACE_LBRACE_DASH] = "{{-",
  [anon_sym_RBRACE_RBRACE] = "}}",
  [anon_sym_DASH_RBRACE_RBRACE] = "-}}",
  [sym_keyword] = "keyword",
  [aux_sym_code_snippet_token1] = "code_snippet_token1",
  [sym_close_keyword] = "keyword",
  [anon_sym_PIPE_GT] = "|>",
  [sym_comment] = "comment",
  [sym__code] = "_code",
  [sym_template] = "template",
  [sym_content] = "content",
  [sym_tag] = "tag",
  [sym__expression] = "_expression",
  [sym_code_snippet] = "code",
  [sym_filter] = "filter",
  [aux_sym_template_repeat1] = "template_repeat1",
  [aux_sym_content_repeat1] = "content_repeat1",
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
  [aux_sym_code_snippet_token1] = aux_sym_code_snippet_token1,
  [sym_close_keyword] = sym_keyword,
  [anon_sym_PIPE_GT] = anon_sym_PIPE_GT,
  [sym_comment] = sym_comment,
  [sym__code] = sym__code,
  [sym_template] = sym_template,
  [sym_content] = sym_content,
  [sym_tag] = sym_tag,
  [sym__expression] = sym__expression,
  [sym_code_snippet] = sym_code_snippet,
  [sym_filter] = sym_filter,
  [aux_sym_template_repeat1] = aux_sym_template_repeat1,
  [aux_sym_content_repeat1] = aux_sym_content_repeat1,
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
  [aux_sym_code_snippet_token1] = {
    .visible = false,
    .named = false,
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
  [sym__code] = {
    .visible = false,
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
  [sym_code_snippet] = {
    .visible = true,
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
  [aux_sym_content_repeat1] = {
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
    [0] = sym_code_snippet,
  },
  [2] = {
    [1] = sym_code_snippet,
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
  [21] = 21,
  [22] = 22,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(30);
      if (lookahead == '#') ADVANCE(28);
      if (lookahead == '-') ADVANCE(27);
      if (lookahead == '/') ADVANCE(23);
      if (lookahead == 'e') ADVANCE(45);
      if (lookahead == 'f') ADVANCE(44);
      if (lookahead == 'i') ADVANCE(43);
      if (lookahead == 'l') ADVANCE(41);
      if (lookahead == 's') ADVANCE(42);
      if (lookahead == '{') ADVANCE(24);
      if (lookahead == '|') ADVANCE(22);
      if (lookahead == '}') ADVANCE(25);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0)
      if (lookahead == '>' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(46);
      if (lookahead == '!' ||
          lookahead == '(' ||
          lookahead == ')' ||
          lookahead == '.' ||
          lookahead == '?' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_') ADVANCE(40);
      END_STATE();
    case 1:
      if (lookahead == ' ') ADVANCE(38);
      if (lookahead == 'c') ADVANCE(6);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(20);
      END_STATE();
    case 2:
      if (lookahead == ' ') ADVANCE(38);
      if (lookahead == 'c') ADVANCE(16);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(20);
      END_STATE();
    case 3:
      if (lookahead == ' ') ADVANCE(38);
      if (lookahead == 'd') ADVANCE(4);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(20);
      END_STATE();
    case 4:
      if (lookahead == ' ') ADVANCE(38);
      if (lookahead == 'e') ADVANCE(39);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(20);
      END_STATE();
    case 5:
      if (lookahead == ' ') ADVANCE(38);
      if (lookahead == 'i') ADVANCE(10);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(20);
      END_STATE();
    case 6:
      if (lookahead == ' ') ADVANCE(38);
      if (lookahead == 'l') ADVANCE(18);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(20);
      END_STATE();
    case 7:
      if (lookahead == ' ') ADVANCE(38);
      if (lookahead == 'n') ADVANCE(39);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(20);
      END_STATE();
    case 8:
      if (lookahead == ' ') ADVANCE(38);
      if (lookahead == 'n') ADVANCE(2);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(20);
      END_STATE();
    case 9:
      if (lookahead == ' ') ADVANCE(38);
      if (lookahead == 'o') ADVANCE(14);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(20);
      END_STATE();
    case 10:
      if (lookahead == ' ') ADVANCE(38);
      if (lookahead == 'o') ADVANCE(7);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(20);
      END_STATE();
    case 11:
      if (lookahead == ' ') ADVANCE(38);
      if (lookahead == 'o') ADVANCE(17);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(20);
      END_STATE();
    case 12:
      if (lookahead == ' ') ADVANCE(38);
      if (lookahead == 'p') ADVANCE(9);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(20);
      END_STATE();
    case 13:
      if (lookahead == ' ') ADVANCE(38);
      if (lookahead == 'r') ADVANCE(39);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(20);
      END_STATE();
    case 14:
      if (lookahead == ' ') ADVANCE(38);
      if (lookahead == 'r') ADVANCE(15);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(20);
      END_STATE();
    case 15:
      if (lookahead == ' ') ADVANCE(38);
      if (lookahead == 't') ADVANCE(39);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(20);
      END_STATE();
    case 16:
      if (lookahead == ' ') ADVANCE(38);
      if (lookahead == 't') ADVANCE(5);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(20);
      END_STATE();
    case 17:
      if (lookahead == ' ') ADVANCE(38);
      if (lookahead == 'u') ADVANCE(15);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(20);
      END_STATE();
    case 18:
      if (lookahead == ' ') ADVANCE(38);
      if (lookahead == 'u') ADVANCE(3);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(20);
      END_STATE();
    case 19:
      if (lookahead == ' ') ADVANCE(38);
      if (lookahead == 'y') ADVANCE(11);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(20);
      END_STATE();
    case 20:
      if (lookahead == ' ') ADVANCE(38);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(20);
      END_STATE();
    case 21:
      if (lookahead == '#') ADVANCE(73);
      if (lookahead != 0) ADVANCE(21);
      END_STATE();
    case 22:
      if (lookahead == '>') ADVANCE(72);
      END_STATE();
    case 23:
      if (lookahead == 'e') ADVANCE(69);
      if (lookahead == 'f') ADVANCE(58);
      if (lookahead == 'i') ADVANCE(53);
      if (lookahead == 'l') ADVANCE(47);
      if (lookahead == 's') ADVANCE(52);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(71);
      END_STATE();
    case 24:
      if (lookahead == '{') ADVANCE(34);
      END_STATE();
    case 25:
      if (lookahead == '}') ADVANCE(36);
      END_STATE();
    case 26:
      if (lookahead == '}') ADVANCE(37);
      END_STATE();
    case 27:
      if (lookahead == '}') ADVANCE(26);
      END_STATE();
    case 28:
      if (lookahead != 0 &&
          lookahead != '#') ADVANCE(21);
      END_STATE();
    case 29:
      if (eof) ADVANCE(30);
      if (lookahead == '{') ADVANCE(31);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(32);
      if (lookahead != 0) ADVANCE(33);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(aux_sym_content_token1);
      if (lookahead == '{') ADVANCE(34);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(aux_sym_content_token1);
      if (lookahead == '{') ADVANCE(31);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(32);
      if (lookahead != 0) ADVANCE(33);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(aux_sym_content_token1);
      if (lookahead != 0 &&
          lookahead != '{') ADVANCE(33);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(anon_sym_LBRACE_LBRACE);
      if (lookahead == '-') ADVANCE(35);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_LBRACE_LBRACE_DASH);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_RBRACE_RBRACE);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_DASH_RBRACE_RBRACE);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym_keyword);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_keyword);
      if (lookahead == ' ') ADVANCE(38);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(20);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(aux_sym_code_snippet_token1);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(aux_sym_code_snippet_token1);
      if (lookahead == ' ') ADVANCE(38);
      if (lookahead == 'a') ADVANCE(19);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(20);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(aux_sym_code_snippet_token1);
      if (lookahead == ' ') ADVANCE(38);
      if (lookahead == 'e') ADVANCE(15);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(20);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(aux_sym_code_snippet_token1);
      if (lookahead == ' ') ADVANCE(38);
      if (lookahead == 'f') ADVANCE(39);
      if (lookahead == 'm') ADVANCE(12);
      if (lookahead == 'n') ADVANCE(1);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(20);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(aux_sym_code_snippet_token1);
      if (lookahead == ' ') ADVANCE(38);
      if (lookahead == 'o') ADVANCE(13);
      if (lookahead == 'u') ADVANCE(8);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(20);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(aux_sym_code_snippet_token1);
      if (lookahead == ' ') ADVANCE(38);
      if (lookahead == 'x') ADVANCE(12);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(20);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(aux_sym_code_snippet_token1);
      if (lookahead == ' ') ADVANCE(38);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(20);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_close_keyword);
      if (lookahead == 'a') ADVANCE(70);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(71);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym_close_keyword);
      if (lookahead == 'c') ADVANCE(55);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(71);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym_close_keyword);
      if (lookahead == 'c') ADVANCE(66);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(71);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym_close_keyword);
      if (lookahead == 'd') ADVANCE(51);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(71);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym_close_keyword);
      if (lookahead == 'e') ADVANCE(71);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(71);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym_close_keyword);
      if (lookahead == 'e') ADVANCE(65);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(71);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_close_keyword);
      if (lookahead == 'f') ADVANCE(71);
      if (lookahead == 'm') ADVANCE(62);
      if (lookahead == 'n') ADVANCE(48);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(71);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym_close_keyword);
      if (lookahead == 'i') ADVANCE(60);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(71);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(sym_close_keyword);
      if (lookahead == 'l') ADVANCE(68);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(71);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(sym_close_keyword);
      if (lookahead == 'n') ADVANCE(71);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(71);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym_close_keyword);
      if (lookahead == 'n') ADVANCE(49);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(71);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym_close_keyword);
      if (lookahead == 'o') ADVANCE(63);
      if (lookahead == 'u') ADVANCE(57);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(71);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(sym_close_keyword);
      if (lookahead == 'o') ADVANCE(64);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(71);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(sym_close_keyword);
      if (lookahead == 'o') ADVANCE(56);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(71);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_close_keyword);
      if (lookahead == 'o') ADVANCE(67);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(71);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_close_keyword);
      if (lookahead == 'p') ADVANCE(59);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(71);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym_close_keyword);
      if (lookahead == 'r') ADVANCE(71);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(71);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym_close_keyword);
      if (lookahead == 'r') ADVANCE(65);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(71);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_close_keyword);
      if (lookahead == 't') ADVANCE(71);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(71);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym_close_keyword);
      if (lookahead == 't') ADVANCE(54);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(71);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym_close_keyword);
      if (lookahead == 'u') ADVANCE(65);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(71);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym_close_keyword);
      if (lookahead == 'u') ADVANCE(50);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(71);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_close_keyword);
      if (lookahead == 'x') ADVANCE(62);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(71);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_close_keyword);
      if (lookahead == 'y') ADVANCE(61);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(71);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym_close_keyword);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(71);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_PIPE_GT);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym_comment);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 29},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 29},
  [4] = {.lex_state = 29},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 29},
  [7] = {.lex_state = 29},
  [8] = {.lex_state = 29},
  [9] = {.lex_state = 0, .external_lex_state = 1},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 29},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 29},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0, .external_lex_state = 1},
  [21] = {.lex_state = 0, .external_lex_state = 1},
  [22] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_LBRACE_LBRACE] = ACTIONS(1),
    [anon_sym_LBRACE_LBRACE_DASH] = ACTIONS(1),
    [anon_sym_RBRACE_RBRACE] = ACTIONS(1),
    [anon_sym_DASH_RBRACE_RBRACE] = ACTIONS(1),
    [sym_keyword] = ACTIONS(1),
    [aux_sym_code_snippet_token1] = ACTIONS(1),
    [sym_close_keyword] = ACTIONS(1),
    [anon_sym_PIPE_GT] = ACTIONS(1),
    [sym_comment] = ACTIONS(1),
    [sym__code] = ACTIONS(1),
  },
  [1] = {
    [sym_template] = STATE(22),
    [sym_content] = STATE(4),
    [sym_tag] = STATE(4),
    [aux_sym_template_repeat1] = STATE(4),
    [aux_sym_content_repeat1] = STATE(6),
    [ts_builtin_sym_end] = ACTIONS(3),
    [aux_sym_content_token1] = ACTIONS(5),
    [anon_sym_LBRACE_LBRACE] = ACTIONS(7),
    [anon_sym_LBRACE_LBRACE_DASH] = ACTIONS(7),
  },
  [2] = {
    [sym__expression] = STATE(5),
    [sym_code_snippet] = STATE(14),
    [sym_filter] = STATE(18),
    [aux_sym_filter_repeat1] = STATE(10),
    [anon_sym_RBRACE_RBRACE] = ACTIONS(9),
    [anon_sym_DASH_RBRACE_RBRACE] = ACTIONS(9),
    [sym_keyword] = ACTIONS(11),
    [aux_sym_code_snippet_token1] = ACTIONS(13),
    [sym_close_keyword] = ACTIONS(15),
    [anon_sym_PIPE_GT] = ACTIONS(17),
    [sym_comment] = ACTIONS(15),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 5,
    ACTIONS(19), 1,
      ts_builtin_sym_end,
    ACTIONS(21), 1,
      aux_sym_content_token1,
    STATE(6), 1,
      aux_sym_content_repeat1,
    ACTIONS(24), 2,
      anon_sym_LBRACE_LBRACE,
      anon_sym_LBRACE_LBRACE_DASH,
    STATE(3), 3,
      sym_content,
      sym_tag,
      aux_sym_template_repeat1,
  [19] = 5,
    ACTIONS(5), 1,
      aux_sym_content_token1,
    ACTIONS(27), 1,
      ts_builtin_sym_end,
    STATE(6), 1,
      aux_sym_content_repeat1,
    ACTIONS(7), 2,
      anon_sym_LBRACE_LBRACE,
      anon_sym_LBRACE_LBRACE_DASH,
    STATE(3), 3,
      sym_content,
      sym_tag,
      aux_sym_template_repeat1,
  [38] = 4,
    ACTIONS(17), 1,
      anon_sym_PIPE_GT,
    STATE(10), 1,
      aux_sym_filter_repeat1,
    STATE(19), 1,
      sym_filter,
    ACTIONS(29), 2,
      anon_sym_RBRACE_RBRACE,
      anon_sym_DASH_RBRACE_RBRACE,
  [52] = 4,
    ACTIONS(31), 1,
      ts_builtin_sym_end,
    ACTIONS(33), 1,
      aux_sym_content_token1,
    STATE(7), 1,
      aux_sym_content_repeat1,
    ACTIONS(35), 2,
      anon_sym_LBRACE_LBRACE,
      anon_sym_LBRACE_LBRACE_DASH,
  [66] = 4,
    ACTIONS(37), 1,
      ts_builtin_sym_end,
    ACTIONS(39), 1,
      aux_sym_content_token1,
    STATE(7), 1,
      aux_sym_content_repeat1,
    ACTIONS(42), 2,
      anon_sym_LBRACE_LBRACE,
      anon_sym_LBRACE_LBRACE_DASH,
  [80] = 2,
    ACTIONS(44), 1,
      ts_builtin_sym_end,
    ACTIONS(46), 3,
      aux_sym_content_token1,
      anon_sym_LBRACE_LBRACE,
      anon_sym_LBRACE_LBRACE_DASH,
  [89] = 2,
    ACTIONS(50), 1,
      sym__code,
    ACTIONS(48), 3,
      anon_sym_RBRACE_RBRACE,
      anon_sym_DASH_RBRACE_RBRACE,
      anon_sym_PIPE_GT,
  [98] = 3,
    ACTIONS(17), 1,
      anon_sym_PIPE_GT,
    STATE(12), 1,
      aux_sym_filter_repeat1,
    ACTIONS(52), 2,
      anon_sym_RBRACE_RBRACE,
      anon_sym_DASH_RBRACE_RBRACE,
  [109] = 2,
    ACTIONS(54), 1,
      ts_builtin_sym_end,
    ACTIONS(56), 3,
      aux_sym_content_token1,
      anon_sym_LBRACE_LBRACE,
      anon_sym_LBRACE_LBRACE_DASH,
  [118] = 3,
    ACTIONS(60), 1,
      anon_sym_PIPE_GT,
    STATE(12), 1,
      aux_sym_filter_repeat1,
    ACTIONS(58), 2,
      anon_sym_RBRACE_RBRACE,
      anon_sym_DASH_RBRACE_RBRACE,
  [129] = 2,
    ACTIONS(63), 1,
      ts_builtin_sym_end,
    ACTIONS(65), 3,
      aux_sym_content_token1,
      anon_sym_LBRACE_LBRACE,
      anon_sym_LBRACE_LBRACE_DASH,
  [138] = 1,
    ACTIONS(48), 3,
      anon_sym_RBRACE_RBRACE,
      anon_sym_DASH_RBRACE_RBRACE,
      anon_sym_PIPE_GT,
  [144] = 1,
    ACTIONS(67), 3,
      anon_sym_RBRACE_RBRACE,
      anon_sym_DASH_RBRACE_RBRACE,
      anon_sym_PIPE_GT,
  [150] = 1,
    ACTIONS(69), 3,
      anon_sym_RBRACE_RBRACE,
      anon_sym_DASH_RBRACE_RBRACE,
      anon_sym_PIPE_GT,
  [156] = 1,
    ACTIONS(71), 3,
      anon_sym_RBRACE_RBRACE,
      anon_sym_DASH_RBRACE_RBRACE,
      anon_sym_PIPE_GT,
  [162] = 1,
    ACTIONS(29), 2,
      anon_sym_RBRACE_RBRACE,
      anon_sym_DASH_RBRACE_RBRACE,
  [167] = 1,
    ACTIONS(73), 2,
      anon_sym_RBRACE_RBRACE,
      anon_sym_DASH_RBRACE_RBRACE,
  [172] = 1,
    ACTIONS(75), 1,
      sym__code,
  [176] = 1,
    ACTIONS(77), 1,
      sym__code,
  [180] = 1,
    ACTIONS(79), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(3)] = 0,
  [SMALL_STATE(4)] = 19,
  [SMALL_STATE(5)] = 38,
  [SMALL_STATE(6)] = 52,
  [SMALL_STATE(7)] = 66,
  [SMALL_STATE(8)] = 80,
  [SMALL_STATE(9)] = 89,
  [SMALL_STATE(10)] = 98,
  [SMALL_STATE(11)] = 109,
  [SMALL_STATE(12)] = 118,
  [SMALL_STATE(13)] = 129,
  [SMALL_STATE(14)] = 138,
  [SMALL_STATE(15)] = 144,
  [SMALL_STATE(16)] = 150,
  [SMALL_STATE(17)] = 156,
  [SMALL_STATE(18)] = 162,
  [SMALL_STATE(19)] = 167,
  [SMALL_STATE(20)] = 172,
  [SMALL_STATE(21)] = 176,
  [SMALL_STATE(22)] = 180,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_template, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_template_repeat1, 2),
  [21] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_template_repeat1, 2), SHIFT_REPEAT(6),
  [24] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_template_repeat1, 2), SHIFT_REPEAT(2),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_template, 1),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_content, 1),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [35] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_content, 1),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_content_repeat1, 2),
  [39] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_content_repeat1, 2), SHIFT_REPEAT(7),
  [42] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_content_repeat1, 2),
  [44] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tag, 2),
  [46] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tag, 2),
  [48] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expression, 1, .production_id = 1),
  [50] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [52] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_filter, 1),
  [54] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tag, 3),
  [56] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tag, 3),
  [58] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_filter_repeat1, 2),
  [60] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_filter_repeat1, 2), SHIFT_REPEAT(21),
  [63] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tag, 4),
  [65] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tag, 4),
  [67] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expression, 2, .production_id = 2),
  [69] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_code_snippet, 2),
  [71] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_filter_repeat1, 2, .production_id = 2),
  [73] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [75] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [77] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [79] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
};

enum ts_external_scanner_symbol_identifiers {
  ts_external_token__code = 0,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token__code] = sym__code,
};

static const bool ts_external_scanner_states[2][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token__code] = true,
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
