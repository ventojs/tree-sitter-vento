<h1>
<img align="left" width="40" src="https://raw.githubusercontent.com/ventojs/vento/main/docs/favicon.svg"></img>
tree-sitter-better-vento
</h1>

## Features

- **Syntax Parsing**: Full support for Vento template syntax including tags, keywords, filters, and code blocks
- **Language Injections**: Automatic language injection for:
  - HTML in content sections
  - JavaScript in code blocks
  - YAML in front matter
- **Local Scoping**: Proper variable scoping for loop variables (e.g., `for i of items`)
- **Single-Character Variables**: Support for single-character variable names like `{{ i }}`

## Queries

This parser includes the following query files:

- `highlights.scm` - Syntax highlighting rules
- `injections.scm` - Language injection rules for HTML, JavaScript, and YAML
- `locals.scm` - Local scope and variable reference tracking

### Local Scoping

The `locals.scm` query enables editors to track variable scopes, particularly useful for loop variables:

```vento
{{ for i of pages }}
  <a href="/page/{{ i }}" aria-label="Page {{ i }}">
    {{ i }}
  </a>
{{ /for }}
```
