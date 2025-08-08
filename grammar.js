/**
 * Shorthand for generating a `{{ tag }}` along with other content after the
 * keyword.
 */
function tag ($, name, ...optional) {
  let tokens = [
    $._tag_start_delimiter,
    name
  ];

  if (optional.length > 0) {
    tokens.push(...optional);
  }
  tokens.push(choice("}}", "-}}"));
  return prec(2, seq(...tokens));
}

module.exports = grammar({
  name: 'vento',
  externals: $ => [
    $.code,
    $._raw_code,
    $._parameter_default_value,

    // TODO: Treating these as externals isn't pretty, but it's the first
    // method I found to guarantee that leading whitespace is never counted as
    // belonging to any sort of tag node.
    //
    // The boundaries of tags need to be accurate so that the
    // `meta.embedded.line` and `meta.embedded.block` scopes are assigned
    // correctly in editors.
    //
    // Also, from a correctness standpoint, whitespace is best to describe as
    // being in a quantum state where it belongs to neither content nor tags —
    // at least until the next opening tag tells Vento how to handle the
    // previous whitespace.
    $._tag_start_delimiter_simple,
    $._tag_start_delimiter_trim_whitespace,
    $._tag_start_delimiter_javascript_simple,
    $._tag_start_delimiter_javascript_trim_whitespace,
    $._tag_start_delimiter_comment_simple,
    $._tag_start_delimiter_comment_trim_whitespace
  ],
  conflicts: $ => [
    [$.conditional_block]
  ],
  extras: _ => [/\s+/],
  rules: {
    template: $ => repeat($._any),

    _any: $ => choice(
      $.content,
      $.if_block,
      $.for_block,
      $.set_tag,
      $.set_block,
      $.layout_block,
      $.javascript_tag,
      $.include_tag,
      $.comment_tag,
      $.import_tag,
      $.export_block,
      $.export_tag,
      $.function_block,
      // Plugin, but easy to support.
      $.fragment_block,
      $.tag,
      alias($._empty_tag, $.tag),
    ),

    content: _ => prec.right(repeat1(/[^\{]+|\{/)),

    _tag_start_delimiter: $ => choice(
      alias($._tag_start_delimiter_simple, "{{"),
      alias($._tag_start_delimiter_trim_whitespace, "{{-")
    ),

    _tag_start_delimiter_javascript: $ => choice(
      choice(
        alias($._tag_start_delimiter_javascript_simple, "{{>"),
        alias($._tag_start_delimiter_javascript_trim_whitespace, "{{->")
      )
    ),

    _tag_start_delimiter_comment: $ => choice(
      alias($._tag_start_delimiter_comment_simple, "{{#"),
      alias($._tag_start_delimiter_comment_trim_whitespace, "{{#-")
    ),

    _empty_tag: $ => seq(
      $._tag_start_delimiter,
      choice("}}", "-}}")
    ),

    tag: $ => seq(
      $._tag_start_delimiter,
      $._expression,
      optional($.filter),
      choice("}}", "-}}")
    ),

    javascript_tag: $ => seq(
      $._tag_start_delimiter_javascript,
      alias($._raw_code, $.code),
      choice("}}", "-}}")
    ),

    _expression: $ => prec.left(9, seq(
      $.code,
      optional($.filter)
    )),

    filter: $ => prec.left(10, repeat1(seq(
      "|>",
      $.code,
    ))),

    if_block: $ => seq(
      $.if_tag_start,
      optional($.conditional_block),
      repeat($.else_if_block),
      optional($.else_block),
      $.if_tag_end
    ),

    if_tag_start: $ => tag($,
      "if",
      $.code
    ),

    if_tag_end: $ => tag($, "/if"),

    // TODO: Wrapping all conditional blocks in this node seems to prevent
    // precedence hell. Ideally we'd be able to make this `_conditional_block`
    // instead of putting it into the tree, but it stops working its magic when
    // we do that.
    conditional_block: $ => repeat1($._any),

    set_tag: $ => tag($,
      "set",
      $.identifier,
      "=",
      $._expression
    ),

    set_tag_start: $ => tag($,
      "set",
      $.identifier,
      optional($.filter)
    ),

    set_tag_end: $ => tag($, "/set"),

    set_block: $ => seq(
      $.set_tag_start,
      repeat($._any),
      $.set_tag_end
    ),

    for_block: $ => seq(
      $.for_tag_start,
      repeat($._any),
      $.for_tag_end
    ),

    for_tag_start: $ => tag($,
      "for",
      optional("await"),
      choice(
        field('value', $.identifier),
        seq(
          field('key', $.identifier),
          ",",
          field('value', $.identifier)
        )
      ),
      "of",
      $._expression
    ),

    for_tag_end: $ => tag($, "/for"),

    else_if_tag: $ => tag($, "else", "if", $.code),
    else_if_block: $ => prec.right(6, seq(
      $.else_if_tag,
      optional($.conditional_block)
    )),

    else_tag: $ => tag($, "else"),
    else_block: $ => prec.right(6, seq(
      $.else_tag,
      optional($.conditional_block)
    )),

    include_tag: $ => tag($,
      "include",
      // TODO: Separation of string and object is possibly not syntactically
      // valid in JS, as in the following example from the Vento web site:
      //
      // {{ include "./filename.vto" { name: "Óscar" } }}
      //
      // If so, we can put them in separate `code` nodes (and therefore
      // separate injections) via a special scanner rule.
      $.code,
      optional($.filter)
    ),

    layout_tag_start: $ => tag($,
      "layout",
      $._expression
    ),

    layout_tag_end: $ => tag($, "/layout"),

    layout_block: $ => seq(
      $.layout_tag_start,
      repeat($._any),
      $.layout_tag_end
    ),

    import_specifier: $ => choice(
      $.identifier,
      seq(
        "{",
        $.identifier,
        repeat(
          seq(
            ",",
            $.identifier
          )
        ),
        "}"
      )
    ),

    import_tag: $ => tag($,
      "import",
      $.import_specifier,
      "from",
      $.code
    ),

    export_tag: $ => tag($,
      "export",
      $.identifier,
      "=",
      $._expression
    ),

    export_tag_start: $ => tag($,
      "export",
      $.identifier,
      optional($.filter)
    ),

    export_tag_end: $ => tag($, "/export"),

    export_block: $ => seq(
      $.export_tag_start,
      repeat($._any),
      $.export_tag_end
    ),

    parameter: $ => choice(
      field('name', $.identifier),
      seq(
        field('name', $.identifier),
        "=",
        field('value', alias($._parameter_default_value, $.code))
      )
    ),

    parameters: $ => seq(
      "(",
      optional(
        seq(
          $.parameter,
          repeat(seq(",", $.parameter))
        )
      ),
      ")"
    ),

    function_tag_start: $ => tag($,
      optional("export"),
      optional("async"),
      "function",
      $.identifier,
      optional($.parameters)
    ),

    function_tag_end: $ => tag($, "/function"),

    function_block: $ => seq(
      $.function_tag_start,
      repeat($._any),
      $.function_tag_end
    ),

    fragment_tag_start: $ => tag($,
      "fragment",
      $.identifier
    ),

    fragment_tag_end: $ => tag($, "/fragment"),

    fragment_block: $ => seq(
      $.fragment_tag_start,
      repeat($._any),
      $.fragment_tag_end
    ),

    identifier: () => /[A-Za-z_$][a-zA-Z0-9_$]*/,
    comment_tag: $ => seq(
      $._tag_start_delimiter_comment,
      alias(/[^#]*/, $.comment),
      choice("#}}", "-#}}")
    )
  }
});
