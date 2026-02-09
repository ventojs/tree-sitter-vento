; Scopes - for loops create local scopes
(for_statement) @local.scope

; Definitions - the loop variable in for statements
; In "for i of items", the first code node (i) is the definition
(for_statement
  (code) @local.definition.variable
  (keyword)
  (code))

; References - any code that could reference variables
(code) @local.reference
