# Changelog

All notable changes to tree-sitter-vento will be documented in this file.

Version changes are relative to 0.20.0.

## 0.21.0

### Added

- `locals.scm` query file for local scope and variable reference tracking
- Support for single-character variable names (e.g., `{{ i }}`, `{{ x }}`)
- Example file `examples/for-loop-scoping.vto` demonstrating variable scoping in loops
- Example file `examples/with-frontmatter.vto` demonstrating YAML front matter with Vento
- Comprehensive Rust bindings documentation with 7 code examples
- `INJECTION_QUERY` and `LOCALS_QUERY` constants in Rust bindings
- `tree-sitter.json` configuration file

### Changed

- Modified `code_snippet` rule in `grammar.js` to make external code scanner optional
- This allows single-character variables to be parsed correctly
- Updated precedence levels for expression parsing to ensure correct keyword vs. variable resolution
- **Rust bindings**: Complete rewrite of `bindings/rust/lib.rs` to properly reference Vento
- **Rust bindings**: Comprehensive rewrite of `bindings/rust/README.md` with usage examples
- Updated `Cargo.toml` metadata (version, authors format, repository URL)
- Updated `package.json` metadata (name, keywords)
- Improved external scanner to handle YAML front matter and `of` keyword detection

### Fixed

- YAML front matter is recognized and styled
- Single-character loop variables (like `i` in `for i of items`) are now properly recognized as code blocks
- Variable scoping now works correctly in for loops - variables like `i` in `aria-label="Page {{ i }}"` are properly scoped within their containing for loop
- Keywords (such as `layout` and `slot`) are now recognized as keywords rather than variable references
- `of` in `{{ for menu of site.menu }}` is recognized as a keyword rather than a variable reference
- **Rust bindings**: Fixed function name from `tree_sitter_embedded_template()` to `tree_sitter_vento()`
- **Rust bindings**: Fixed `set_language()` calls to use references
- **Rust bindings**: Corrected all documentation from ERB/EJS to Vento
- Package name consistency across `package.json` and `Cargo.toml`
- LICENSE file copyright year and formatting
