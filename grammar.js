module.exports = grammar({
  name: 'vento',
  externals: $ => [
    $.code,
    $.keyword,
  ],
  rules: {
    template: $ => repeat(choice(
      $.tag,
      alias($.comment_tag, $.tag),
      $.content
    )),

    content: $ => prec.right(/[^(\{\{)]+/),

    keyword: $ => /[^\/][a-zA-Z]+/,
    codeSnippet: $ => /[^\/][\s]+/,
    close_keyword: $ => /\/[a-zA-Z]+/,

    _expression: $ => choice(
      // "Solo keywords" aren't a valid expression,
      // but we need to handle them here to avoid
      // a conflict with the the sequence of a keyword
      // and a code block.
      alias(choice($.keyword, $.codeSnippet), $.code),
      alias($.close_keyword, $.keyword),
      seq(
        prec.left(1, $.keyword), 
        $.code
      ),
    ),

    tag: $ => seq(
      choice("{{", "{{-"),
      $._expression,
      optional($.filter),
      choice("}}", "-}}")
    ),

    filter: $ => repeat1(seq(
      "|>",
      $.code
    )),

    comment: $ => /#[^#]+#/,

    comment_tag: $ => seq(
      "{{",
      $.comment,
      "}}"
    ),
  }
});
