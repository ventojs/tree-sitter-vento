module.exports = grammar({
  name: 'vento',
  externals: $ => [
    $._code,
  ],
  extras: $ => [/\s/],
  rules: {
    template: $ => repeat(choice(
      $.tag,
      $.content
    )),

    content: $ => prec.right(/[^(\{\{)]+/),

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

    // General rule for keyword tags
    // It just tries to match the first word in a tag block,
    // plus any other special characters that might be present
    keyword: $ => /[a-z>][a-zA-Z]*? |if|for|include|set|import|export|layout|function/,
    code_snippet: $ => seq(/[a-zA-Z>\.\(\)\!_\?]/, $._code),
    close_keyword: $ => /\/([a-zA-Z]+|if|for|include|set|import|export|layout|function)/,

    filter: $ => repeat1(seq(
      "|>",
      alias($._code, $.code)
    )),

    comment: $ => /#[^#]+#/,
  }
});
