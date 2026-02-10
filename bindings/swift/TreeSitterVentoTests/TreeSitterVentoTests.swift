import XCTest
import SwiftTreeSitter
import TreeSitterVento

final class TreeSitterVentoTests: XCTestCase {
    func testCanLoadGrammar() throws {
        let parser = Parser()
        let language = Language(language: tree_sitter_vento())
        XCTAssertNoThrow(try parser.setLanguage(language),
                         "Error loading Vento grammar")
    }
}
