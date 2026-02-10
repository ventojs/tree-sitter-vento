# tree-sitter-vento

[![crates.io](https://img.shields.io/crates/v/tree-sitter-vento.svg)](https://crates.io/crates/tree-sitter-vento)
[![docs.rs](https://docs.rs/tree-sitter-vento/badge.svg)](https://docs.rs/tree-sitter-vento)

A [tree-sitter](https://tree-sitter.github.io/) grammar for [Vento](https://vento.js.org/), a template engine for Deno and Node.js.

## Installation

Add this to your `Cargo.toml`:

```toml
[dependencies]
tree-sitter = "0.26"
tree-sitter-vento = "0.21"
```

## Usage

### Basic Parsing

```rust
use tree_sitter::Parser;

fn main() {
    let code = r#"
---
title: Hello World
date: 2024-01-15
---
<h1>{{ title }}</h1>
{{ for item of items }}
  <p>{{ item }}</p>
{{ /for }}
"#;

    let mut parser = Parser::new();
    parser
        .set_language(&tree_sitter_vento::language())
        .expect("Error loading Vento grammar");

    let tree = parser.parse(code, None).expect("Error parsing code");
    let root_node = tree.root_node();

    println!("Parsed tree:\n{}", root_node.to_sexp());
}
```

### Using Queries

This crate provides pre-built query strings for syntax highlighting, injections, and local scoping:

```rust
use tree_sitter::{Parser, Query, QueryCursor};

fn highlight_vento(code: &str) {
    let mut parser = Parser::new();
    parser.set_language(&tree_sitter_vento::language()).unwrap();

    let tree = parser.parse(code, None).unwrap();
    let root_node = tree.root_node();

    // Use the built-in highlight query
    let query = Query::new(
        &tree_sitter_vento::language(),
        tree_sitter_vento::HIGHLIGHT_QUERY,
    ).unwrap();

    let mut cursor = QueryCursor::new();
    let captures = cursor.captures(&query, root_node, code.as_bytes());

    for (match_, _) in captures {
        for capture in match_.captures {
            let name = &query.capture_names()[capture.index as usize];
            let text = &code[capture.node.byte_range()];
            println!("{}: {}", name, text);
        }
    }
}
```

### Walking the Parse Tree

```rust
use tree_sitter::{Parser, TreeCursor};

fn walk_tree(code: &str) {
    let mut parser = Parser::new();
    parser.set_language(&tree_sitter_vento::language()).unwrap();

    let tree = parser.parse(code, None).unwrap();
    let mut cursor = tree.walk();

    visit_node(&mut cursor, code, 0);
}

fn visit_node(cursor: &mut TreeCursor, source: &str, depth: usize) {
    let node = cursor.node();
    let indent = "  ".repeat(depth);

    println!(
        "{}{}{}",
        indent,
        node.kind(),
        if node.is_named() { "" } else { " (anonymous)" }
    );

    if cursor.goto_first_child() {
        loop {
            visit_node(cursor, source, depth + 1);
            if !cursor.goto_next_sibling() {
                break;
            }
        }
        cursor.goto_parent();
    }
}
```

## Available Constants

This crate exports several useful constants:

- **`GRAMMAR`** - The grammar definition in JavaScript
- **`HIGHLIGHT_QUERY`** - Syntax highlighting query for editors
- **`INJECTION_QUERY`** - Language injection patterns for HTML, JavaScript, and YAML
- **`LOCALS_QUERY`** - Local scope and variable reference tracking
- **`NODE_TYPES`** - JSON schema of all node types in the grammar

```rust
// Access query files
println!("Highlights: {}", tree_sitter_vento::HIGHLIGHT_QUERY);
println!("Injections: {}", tree_sitter_vento::INJECTION_QUERY);
println!("Locals: {}", tree_sitter_vento::LOCALS_QUERY);
```

## About Vento

[Vento](https://vento.js.org/) is a modern template engine with a JavaScript-inspired syntax. Key features include:

- **Variables**: `{{ variable }}`
- **Expressions**: `{{ user.name }}`
- **Control flow**: `{{ if condition }}...{{ else }}...{{ /if }}`
- **Loops**: `{{ for item of items }}...{{ /for }}`
- **Filters**: `{{ value |> uppercase |> trim }}`
- **Keywords**: `set`, `include`, `layout`, `import`, `export`, `function`, `echo`, `slot`
- **YAML front matter**: Metadata sections at the top of templates
- **Comments**: `{{# This is a comment #}}`

## Grammar Features

This tree-sitter grammar provides:

### ✅ Full Syntax Support

Parse all Vento constructs including tags, keywords, filters, and code blocks.

### ✅ YAML Front Matter

Properly parse and scope YAML metadata sections:

```vento
---
title: My Page
tags: [vento, template]
---
```

### ✅ Language Injections

Automatic language detection for:

- **HTML** in content sections
- **JavaScript** in code blocks
- **YAML** in front matter

### ✅ Local Scoping

Track variable scopes, especially useful for loop variables:

```vento
{{ for i of pages }}
  <a href="/page/{{ i }}">Page {{ i }}</a>
{{ /for }}
```

### ✅ Single-Character Variables

Support for common loop variables like `i`, `x`, `n`, etc.

## Examples

### Parsing a Template with Front Matter

```rust
let template = r#"
---
layout: base.vto
title: My Blog Post
---
<article>
  <h1>{{ title }}</h1>
  {{ for tag of tags }}
    <span class="tag">{{ tag }}</span>
  {{ /for }}
</article>
"#;

let mut parser = Parser::new();
parser.set_language(&tree_sitter_vento::language()).unwrap();
let tree = parser.parse(template, None).unwrap();

// Check if front matter exists
let root = tree.root_node();
if root.child_count() > 0 {
    let first_child = root.child(0).unwrap();
    if first_child.kind() == "front_matter" {
        println!("Template has front matter!");
    }
}
```

### Finding All Variables

```rust
use tree_sitter::{Parser, Query, QueryCursor};

fn find_variables(code: &str) -> Vec<String> {
    let mut parser = Parser::new();
    parser.set_language(&tree_sitter_vento::language()).unwrap();
    let tree = parser.parse(code, None).unwrap();

    let query = Query::new(
        &tree_sitter_vento::language(),
        "(code) @variable",
    ).unwrap();

    let mut cursor = QueryCursor::new();
    let matches = cursor.matches(&query, tree.root_node(), code.as_bytes());

    matches
        .flat_map(|m| m.captures)
        .map(|c| code[c.node.byte_range()].to_string())
        .collect()
}
```

## Integration with Editors

This grammar is designed to integrate seamlessly with text editors that support tree-sitter:

- **Neovim** - Via nvim-treesitter
- **Helix** - Built-in tree-sitter support
- **Emacs** - Via tree-sitter mode
- **Zed** - Native tree-sitter integration

The included query files provide:

- Accurate syntax highlighting
- Code folding hints
- Indentation rules
- Symbol navigation

## Resources

- [Vento Documentation](https://vento.js.org/)
- [Vento Repository](https://github.com/ventojs/vento)
- [Tree-sitter Documentation](https://tree-sitter.github.io/)
- [Tree-sitter Discussions](https://github.com/tree-sitter/tree-sitter/discussions)

## Contributing

Contributions are welcome! Please feel free to submit issues or pull requests to the [tree-sitter-vento repository](https://github.com/ventojs/tree-sitter-vento).

## License

This project is licensed under the MIT License. See the LICENSE file for details.
