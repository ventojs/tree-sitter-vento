package tree_sitter_vento_test

import (
	"testing"

	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	tree_sitter_vento "github.com/ventojs/tree-sitter-vento/bindings/go"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_vento.Language())
	if language == nil {
		t.Errorf("Error loading Vento grammar")
	}
}
