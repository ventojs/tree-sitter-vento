module.exports = grammar({
  name: 'vento',
  externals: $ => [
    $._code,
  ],
  extras: $ => [/\s/],
  rules: {
    template: $ => repeat(choice(
      $.content,
      $.tag,
    )),

    content: () => prec.right(repeat1(/[^\{]+|\{/)),

    tag: $ => seq(
      choice("{{", "{{-"),
      optional($._expression),
      optional($.filter),
      choice("}}", "-}}")
    ),

    _expression: $ => choice(
      // "Solo keywords" are just code blocks
      alias($.code_snippet, $.code),
      alias($.keyword, $.code),
      alias($.close_keyword, $.keyword),
      seq(
        $.keyword,
        alias($._code, $.code),
      ),
      $.comment,
    ),

    filter: $ => repeat1(seq(
      "|>",
      alias($._code, $.code)
    )),

    // General rule for keyword tags
    // It just tries to match the first word in a tag block,
    // plus any other special characters that might be present
    keyword: () => /[a-z>][a-zA-Z]*? |if|for|include|set|import|export|layout|function/,

    code_snippet: $ => seq(/[a-zA-Z>\.\(\)\!_\?]/, $._code),

    close_keyword: () => /\/([a-zA-Z]+|if|for|include|set|import|export|layout|function)/,

    comment: () => /#[^#]+#/,
  }
});
