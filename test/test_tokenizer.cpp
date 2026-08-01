#include <gtest/gtest.h>
#include <pthread.h>

#include "../src/tokenizer/tokenizer.hpp"

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
    Tokenizer tokenizer("examples/example.c");
   
    EXPECT_EQ(tokenizer.tokenized_file, expected_vector);
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
    Tokenizer tokenizer("examples/example1.c");
   
    EXPECT_EQ(tokenizer.tokenized_file, expected_vector);
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
    Tokenizer tokenizer("examples/example2.c");
   
    EXPECT_EQ(tokenizer.tokenized_file, expected_vector);
}
