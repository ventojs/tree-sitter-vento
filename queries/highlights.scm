(comment) @comment @spell

; Tag node types
(if_tag_start) @keyword
(if_tag_end) @keyword
(else_if_tag) @keyword
(else_tag) @keyword
(for_tag_start) @keyword
(for_tag_end) @keyword
(layout_tag_start) @keyword
(layout_tag_end) @keyword
(set_tag) @keyword
(set_tag_start) @keyword
(set_tag_end) @keyword
(import_tag) @keyword
(export_tag) @keyword
(export_tag_start) @keyword
(export_tag_end) @keyword
(include_tag) @keyword
(function_tag_start) @keyword
(function_tag_end) @keyword
(fragment_tag_start) @keyword
(fragment_tag_end) @keyword
(javascript_tag) @keyword

; Identifiers
(identifier) @variable

; Operators
"|>" @operator

; Code injections
(code) @embedded
