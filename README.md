<h1>
<img align="left" width="40" src="https://raw.githubusercontent.com/ventojs/vento/main/docs/favicon.svg"></img>
tree-sitter-vento
</h1>

[![Tests](https://github.com/ventojs/tree-sitter-vento/actions/workflows/test.yml/badge.svg)](https://github.com/ventojs/tree-sitter-vento/actions/workflows/test.yml)
[![Discord](https://img.shields.io/badge/join-chat-blue?logo=discord&logoColor=white)](https://discord.gg/YbTmpACHWB)

A [tree-sitter](https://github.com/tree-sitter/tree-sitter) parser for the [Vento](https://vento.js.org/) templating language.

## Features

- Full support for Vento template syntax
- YAML front matter parsing with language injection
- JavaScript code injection for dynamic expressions
- HTML content injection for template markup
- Syntax highlighting for all Vento constructs

### Supported Keywords

All Vento keywords are properly parsed and highlighted:

#### Control Flow

- `{{ if }}` / `{{ /if }}` - Conditional blocks
- `{{ else if }}` - Else-if branches
- `{{ else }}` - Else branches
- `{{ for }}` / `{{ /for }}` - Loop blocks (with optional `await`)

#### Variables and Output

- `{{ set }}` / `{{ /set }}` - Variable assignment (tag and block forms)
- `{{ echo }}` - Output expressions

#### Layout and Composition

- `{{ layout }}` / `{{ /layout }}` - Layout blocks
- `{{ slot }}` / `{{ /slot }}` - Slot definitions
- `{{ default }}` / `{{ /default }}` - Default content blocks
- `{{ include }}` - Include other templates
- `{{ fragment }}` / `{{ /fragment }}` - Fragment blocks (plugin)

#### Functions and Modules

- `{{ function }}` / `{{ /function }}` - Function definitions (with optional `async` and `export`)
- `{{ import }}` - Import from other templates
- `{{ export }}` / `{{ /export }}` - Export variables (tag and block forms)

#### Special Tags

- `{{> }}` - JavaScript execution tag
- `{{# #}}` - Comment tag

### Front Matter Support

The parser supports YAML front matter at the beginning of Vento templates:

```vento
---
title: My Page
date: 2024-01-01
tags:
  - vento
  - template
---

<h1>{{ title }}</h1>
```

The YAML content within the front matter delimiters (`---`) will be properly injected and highlighted as YAML.
