#include <gtest/gtest.h>

#include "../src/lexer/lexer.hpp"
#include "../src/helpers/helpers.hpp"

TEST(LexerTest, TokenizeExample) {
    const std::deque<Token> expected_vector = {
        Token{.type = TOKEN_INT, .value = std::monostate{}, .line = 1},
        Token{.type = TOKEN_IDENTIFIER, .value = std::string("main"), .line = 1},
        Token{.type = TOKEN_LEFT_PAREN, .value = std::monostate{}, .line = 1},
        Token{.type = TOKEN_RIGHT_PAREN, .value = std::monostate{}, .line = 1},
        Token{.type = TOKEN_LEFT_BRACE, .value = std::monostate{}, .line = 1},
        Token{.type = TOKEN_RETURN, .value = std::monostate{}, .line = 2},
        Token{.type = TOKEN_INT_LIT, .value = 2, .line = 2},
        Token{.type = TOKEN_SEMICOLON, .value = std::monostate{}, .line = 2},
        Token{.type = TOKEN_RIGHT_BRACE, .value = std::monostate{}, .line = 3},
    };
    const std::vector<char> bytes = readFile("examples/example.c");
    Lexer lexer(bytes);
   
    EXPECT_EQ(lexer.getTokens(), expected_vector);
}

TEST(LexerTest, TokenizeExample1) {
    const std::deque<Token> expected_vector = {
        Token{.type = TOKEN_INT, .value = std::monostate{}, .line = 1},
        Token{.type = TOKEN_IDENTIFIER, .value = std::string("main"), .line = 1},
        Token{.type = TOKEN_LEFT_PAREN, .value = std::monostate{}, .line = 1},
        Token{.type = TOKEN_RIGHT_PAREN, .value = std::monostate{}, .line = 1},
        Token{.type = TOKEN_LEFT_BRACE, .value = std::monostate{}, .line = 1},
        Token{.type = TOKEN_IDENTIFIER, .value = std::string("my_func"), .line = 2},
        Token{.type = TOKEN_LEFT_PAREN, .value = std::monostate{}, .line = 2},
        Token{.type = TOKEN_INT, .value = std::monostate{}, .line = 2},
        Token{.type = TOKEN_IDENTIFIER, .value = std::string("my_var"), .line = 2},
        Token{.type = TOKEN_RIGHT_PAREN, .value = std::monostate{}, .line = 2},
        Token{.type = TOKEN_SEMICOLON, .value = std::monostate{}, .line = 2},
        Token{.type = TOKEN_RETURN, .value = std::monostate{}, .line = 3},
        Token{.type = TOKEN_INT_LIT, .value = 2, .line = 3},
        Token{.type = TOKEN_SEMICOLON, .value = std::monostate{}, .line = 3},
        Token{.type = TOKEN_RIGHT_BRACE, .value = std::monostate{}, .line = 4},
    };
    const std::vector<char> bytes = readFile("examples/example1.c");
    Lexer lexer(bytes);
   
    EXPECT_EQ(lexer.getTokens(), expected_vector);
}


TEST(LexerTest, TokenizeExample2) {
    const std::deque<Token> expected_vector = {
        Token{.type = TOKEN_INT, .value = std::monostate{}, .line = 1},
        Token{.type = TOKEN_IDENTIFIER, .value = std::string("my_func"), .line = 1},
        Token{.type = TOKEN_LEFT_PAREN, .value = std::monostate{}, .line = 1},
        Token{.type = TOKEN_INT, .value = std::monostate{}, .line = 1},
        Token{.type = TOKEN_IDENTIFIER, .value = std::string("my_var"), .line = 1},
        Token{.type = TOKEN_RIGHT_PAREN, .value = std::monostate{}, .line = 1},
        Token{.type = TOKEN_LEFT_BRACE, .value = std::monostate{}, .line = 1},
        Token{.type = TOKEN_RETURN, .value = std::monostate{}, .line = 2},
        Token{.type = TOKEN_IDENTIFIER, .value = std::string("my_var"), .line = 2},
        Token{.type = TOKEN_SEMICOLON, .value = std::monostate{}, .line = 2},
        Token{.type = TOKEN_RIGHT_BRACE, .value = std::monostate{}, .line = 3},
        Token{.type = TOKEN_INT, .value = std::monostate{}, .line = 5},
        Token{.type = TOKEN_IDENTIFIER, .value = std::string("main"), .line = 5},
        Token{.type = TOKEN_LEFT_PAREN, .value = std::monostate{}, .line = 5},
        Token{.type = TOKEN_RIGHT_PAREN, .value = std::monostate{}, .line = 5},
        Token{.type = TOKEN_LEFT_BRACE, .value = std::monostate{}, .line = 5},
        Token{.type = TOKEN_INT, .value = std::monostate{}, .line = 6},
        Token{.type = TOKEN_IDENTIFIER, .value = std::string("my_var"), .line = 6},
        Token{.type = TOKEN_SEMICOLON, .value = std::monostate{}, .line = 6},
        Token{.type = TOKEN_IDENTIFIER, .value = std::string("my_func"), .line = 7},
        Token{.type = TOKEN_LEFT_PAREN, .value = std::monostate{}, .line = 7},
        Token{.type = TOKEN_IDENTIFIER, .value = std::string("my_var"), .line = 7},
        Token{.type = TOKEN_RIGHT_PAREN, .value = std::monostate{}, .line = 7},
        Token{.type = TOKEN_SEMICOLON, .value = std::monostate{}, .line = 7},
        Token{.type = TOKEN_RETURN, .value = std::monostate{}, .line = 8},
        Token{.type = TOKEN_INT_LIT, .value = 2, .line = 8},
        Token{.type = TOKEN_SEMICOLON, .value = std::monostate{}, .line = 8},
        Token{.type = TOKEN_RIGHT_BRACE, .value = std::monostate{}, .line = 9},
    };
    const std::vector<char> bytes = readFile("examples/example2.c");
    Lexer lexer(bytes);
   
    EXPECT_EQ(lexer.getTokens(), expected_vector);
}

TEST(LexerTest, TokenizeExample4) {
    const std::deque<Token> expected_vector = {
        Token{.type = TOKEN_INT, .value = std::monostate{}, .line = 1},
        Token{.type = TOKEN_IDENTIFIER, .value = std::string("main"), .line = 1},
        Token{.type = TOKEN_LEFT_PAREN, .value = std::monostate{}, .line = 1},
        Token{.type = TOKEN_RIGHT_PAREN, .value = std::monostate{}, .line = 1},
        Token{.type = TOKEN_LEFT_BRACE, .value = std::monostate{}, .line = 1},
        Token{.type = TOKEN_RETURN, .value = std::monostate{}, .line = 2},
        Token{.type = TOKEN_LOG_NEG, .value = std::monostate{}, .line = 2},
        Token{.type = TOKEN_COMPLEMENT, .value = std::monostate{}, .line = 2},
        Token{.type = TOKEN_NEG, .value = std::monostate{}, .line = 2},
        Token{.type = TOKEN_INT_LIT, .value = 2, .line = 2},
        Token{.type = TOKEN_SEMICOLON, .value = std::monostate{}, .line = 2},
        Token{.type = TOKEN_RIGHT_BRACE, .value = std::monostate{}, .line = 3},
    };
    const std::vector<char> bytes = readFile("examples/example4.c");
    Lexer lexer(bytes);
   
    EXPECT_EQ(lexer.getTokens(), expected_vector);
}
