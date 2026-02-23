((front_matter_content) @injection.content
  (#set! injection.language "yaml"))

((content) @injection.content
  (#set! injection.language "html")
  (#set! injection.combined))

; Inject JavaScript into code nodes that are direct children of specific nodes
; We intentionally exclude (filter (code)) patterns so filter function names
; like 'slugify' and 'postDate' are highlighted as @function instead of JavaScript

(if_tag_start (code) @injection.content
  (#set! injection.language "javascript"))

(else_if_tag (code) @injection.content
  (#set! injection.language "javascript"))

(for_tag_start (code) @injection.content
  (#set! injection.language "javascript"))

(set_tag (code) @injection.content
  (#set! injection.language "javascript"))

(include_tag (code) @injection.content
  (#set! injection.language "javascript"))

(layout_tag_start (code) @injection.content
  (#set! injection.language "javascript"))

(import_tag (code) @injection.content
  (#set! injection.language "javascript"))

(export_tag (code) @injection.content
  (#set! injection.language "javascript"))

(echo_tag (code) @injection.content
  (#set! injection.language "javascript"))

(parameter (code) @injection.content
  (#set! injection.language "javascript"))

(javascript_tag (code) @injection.content
  (#set! injection.language "javascript"))

(tag (code) @injection.content
  (#set! injection.language "javascript"))
