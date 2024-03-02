module.exports = grammar({
  name: 'vento',
  externals: $ => [
    $.code,
    $.comment,
  ],
  rules: {
    template: $ => repeat(choice(
      $.tag,
      $.content
    )),

    _node: $ => choice(
      $.code,
      $.close_tag,
      $.comment,
    ),

    close_tag: $ => "/",

    content: $ => prec.right(/[^(\{\{)]+/),

    tag: $ => seq(
      /\{\{[-]?\s*/,
      optional(seq(
        $._node
      )),
      /\s*[-]?\}\}/
    ),
  }
});
