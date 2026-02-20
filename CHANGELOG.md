# Changelog

All notable changes to tree-sitter-vento will be documented in this file.

Version changes are relative to 0.20.0.

## 0.21.0

### Added

- `locals.scm` query file for local scope and variable reference tracking
- Support for single-character variable names (e.g., `{{ i }}`, `{{ x }}`)
- Example file `examples/for-loop-scoping.vto` demonstrating variable scoping in loops
- Example file `examples/with-frontmatter.vto` demonstrating YAML front matter with Vento
- Example file `examples/all-keywords.vto` demonstrating all supported Vento keywords
- `tree-sitter.json` configuration file
- **Front matter support**: YAML front matter delimited by `---` with proper YAML injection
- **New keywords**: `echo`, `slot`/`/slot`, and `default`/`/default` tags
- Grammar rules: `front_matter`, `echo_tag`, `slot_block`, `slot_tag_start`, `slot_tag_end`, `default_block`, `default_tag_start`, `default_tag_end`
- Syntax highlighting for front matter delimiters and all new keywords
- Test cases for front matter and new keyword tags

### Changed

- Modified `code_snippet` rule in `grammar.js` to make external code scanner optional
- This allows single-character variables to be parsed correctly
- Updated precedence levels for expression parsing to ensure correct keyword vs. variable resolution
- Improved external scanner to handle YAML front matter and `of` keyword detection

### Fixed

- YAML front matter is recognized and styled with proper language injection
- Single-character loop variables (like `i` in `for i of items`) are now properly recognized as code blocks
- Variable scoping now works correctly in for loops - variables like `i` in `aria-label="Page {{ i }}"` are properly scoped within their containing for loop
- Keywords (such as `layout`, `slot`, `echo`, and `default`) are now recognized as keywords rather than variable references
- `of` in `{{ for menu of site.menu }}` is recognized as a keyword rather than a variable reference
- **Scanner**: Added `echo`, `slot`, and `default` to the KEYWORDS array for proper keyword detection
