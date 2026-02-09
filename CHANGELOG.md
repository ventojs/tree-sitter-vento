# Changelog

All notable changes to tree-sitter-better-vento will be documented in this file.

Version changes are relative to 0.20.0.

## 0.21.0

### Added

- `locals.scm` query file for local scope and variable reference tracking
- Support for single-character variable names (e.g., `{{ i }}`, `{{ x }}`)
- Example file `examples/for-loop-scoping.vto` demonstrating variable scoping in loops

### Changed

- Modified `code_snippet` rule in `grammar.js` to make external code scanner optional
- This allows single-character variables to be parsed correctly
- Updated precedence levels for expression parsing to ensure correct keyword vs. variable resolution

### Fixed

- YAML front matter is recognized and styled
- Single-character loop variables (like `i` in `for i of items`) are now properly recognized as code blocks
- Variable scoping now works correctly in for loops - variables like `i` in `aria-label="Page {{ i }}"` are properly scoped within their containing for loop
- Keywords (such as `layout` and `slot`) are now recognized as keywords rather than variable references
- `of` in `{{ for menu of site.menu }}` is recognized as a keyword rather than a variable reference
