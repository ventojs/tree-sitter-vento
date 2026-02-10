module.exports = grammar({
  name: "vento",
  externals: ($) => [$._code, $._front_matter_content],
  extras: ($) => [/\s/],
  rules: {
    template: ($) =>
      seq(optional(prec(10, $.front_matter)), repeat(choice($.content, $.tag))),

    content: () => prec.right(repeat1(/[^\{]+|\{/)),

    tag: ($) =>
      seq(
        choice("{{", "{{-"),
        optional($._expression),
        optional($.filter),
        choice("}}", "-}}"),
      ),

    front_matter: ($) =>
      prec(
        10,
        seq(
          token(prec(10, "---")),
          alias($._front_matter_content, $.front_matter_content),
          token(prec(10, "---")),
        ),
      ),

    _expression: ($) =>
      choice(
        $.comment,
        alias($.close_keyword, $.keyword),
        prec(5, $.for_statement),
        prec(4, seq($.keyword, alias($._code, $.code))),
        prec(4, $.keyword),
        prec(1, alias($.code_snippet, $.code)),
      ),

    filter: ($) => repeat1(seq("|>", alias($._code, $.code))),

    for_statement: ($) =>
      seq(
        alias("for", $.keyword),
        alias($._code, $.code),
        alias($.of_keyword, $.keyword),
        alias($._code, $.code),
      ),

    of_keyword: () => token("of"),

    // Vento keywords
    keyword: () =>
      /if|else|for|include|set|import|export|layout|function|echo|slot|default/,

    code_snippet: ($) => seq(/[a-zA-Z>\.\(\)\!_\?]/, optional($._code)),

    close_keyword: () =>
      /\/(if|for|include|set|import|export|layout|function|echo|slot|default)/,

    comment: () => /#[^#]+#/,
  },
});
