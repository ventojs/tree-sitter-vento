module.exports = grammar({
  name: 'vento',
  externals: $ => [
    $.code,
  ],
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
      alias($.keyword, $.code),
      alias($.close_keyword, $.keyword),
      seq(
        $.keyword,
        $.code
      ),
      $.comment,
    ),

    // General rule for keyword tags
    // It just tries to match the first word in a tag block,
    // plus any other special characters that might be present
    keyword: $ => /[a-zA-Z0-9\(\)\.>]+/,
    close_keyword: $ => /\/[a-zA-Z]+/,

    filter: $ => repeat1(seq(
      "|>",
      $.code
    )),

    comment: $ => /#[^#]+#/,
  }
});
