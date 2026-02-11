((front_matter_content) @injection.content
  (#set! injection.language "yaml"))

((content) @injection.content
  (#set! injection.language "html")
  (#set! injection.combined))

((code) @injection.content
  (#set! injection.language "javascript"))
