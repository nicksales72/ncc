#include <gtest/gtest.h>
#include <pthread.h>

#include "../src/lexer/lexer.hpp"
#include "../src/helpers/helpers.hpp"

TEST(TokenizerTest, TestExample) {
    std::deque<Token> expected_vector = {
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
   
    EXPECT_EQ(lexer.tokenized_file, expected_vector);
}

TEST(TokenizerTest, TestExample1) {
    std::deque<Token> expected_vector = {
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
   
    EXPECT_EQ(lexer.tokenized_file, expected_vector);
}


TEST(TokenizerTest, TestExample2) {
    std::deque<Token> expected_vector = {
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
   
    EXPECT_EQ(lexer.tokenized_file, expected_vector);
}
