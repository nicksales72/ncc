#include <gtest/gtest.h>
#include <pthread.h>

#include "../src/tokenizer/tokenizer.hpp"

TEST(TokenizerTest, TestExample) {
    std::vector<Token> expected_vector = {
        Token{.type = TOKEN_INT, .value = std::monostate{}},
        Token{.type = TOKEN_IDENTIFIER, .value = std::string("main")},
        Token{.type = TOKEN_LEFT_PAREN, .value = std::monostate{}},
        Token{.type = TOKEN_RIGHT_PAREN, .value = std::monostate{}},
        Token{.type = TOKEN_LEFT_BRACE, .value = std::monostate{}},
        Token{.type = TOKEN_RETURN, .value = std::monostate{}},
        Token{.type = TOKEN_INT_LIT, .value = 2L},
        Token{.type = TOKEN_SEMICOLON, .value = std::monostate{}},
        Token{.type = TOKEN_RIGHT_BRACE, .value = std::monostate{}},
    };
    Tokenizer tokenizer("examples/example.c");
   
    EXPECT_EQ(tokenizer.tokenized_file, expected_vector);
}

TEST(TokenizerTest, TestExample1) {
    std::vector<Token> expected_vector = {
        Token{.type = TOKEN_INT, .value = std::monostate{}},
        Token{.type = TOKEN_IDENTIFIER, .value = std::string("main")},
        Token{.type = TOKEN_LEFT_PAREN, .value = std::monostate{}},
        Token{.type = TOKEN_RIGHT_PAREN, .value = std::monostate{}},
        Token{.type = TOKEN_LEFT_BRACE, .value = std::monostate{}},
        Token{.type = TOKEN_IDENTIFIER, .value = std::string("myfunc")},
        Token{.type = TOKEN_LEFT_PAREN, .value = std::monostate{}},
        Token{.type = TOKEN_INT, .value = std::monostate{}},
        Token{.type = TOKEN_IDENTIFIER, .value = std::string("myvar")},
        Token{.type = TOKEN_RIGHT_PAREN, .value = std::monostate{}},
        Token{.type = TOKEN_SEMICOLON, .value = std::monostate{}},
        Token{.type = TOKEN_RETURN, .value = std::monostate{}},
        Token{.type = TOKEN_INT_LIT, .value = 2L},
        Token{.type = TOKEN_SEMICOLON, .value = std::monostate{}},
        Token{.type = TOKEN_RIGHT_BRACE, .value = std::monostate{}},
    };
    Tokenizer tokenizer("examples/example1.c");
   
    EXPECT_EQ(tokenizer.tokenized_file, expected_vector);
}


TEST(TokenizerTest, TestExample2) {
    std::vector<Token> expected_vector = {
        Token{.type = TOKEN_INT, .value = std::monostate{}},
        Token{.type = TOKEN_IDENTIFIER, .value = std::string("myfunc")},
        Token{.type = TOKEN_LEFT_PAREN, .value = std::monostate{}},
        Token{.type = TOKEN_INT, .value = std::monostate{}},
        Token{.type = TOKEN_IDENTIFIER, .value = std::string("myvar")},
        Token{.type = TOKEN_RIGHT_PAREN, .value = std::monostate{}},
        Token{.type = TOKEN_LEFT_BRACE, .value = std::monostate{}},
        Token{.type = TOKEN_RETURN, .value = std::monostate{}},
        Token{.type = TOKEN_IDENTIFIER, .value = std::string("myvar")},
        Token{.type = TOKEN_SEMICOLON, .value = std::monostate{}},
        Token{.type = TOKEN_RIGHT_BRACE, .value = std::monostate{}},
        Token{.type = TOKEN_INT, .value = std::monostate{}},
        Token{.type = TOKEN_IDENTIFIER, .value = std::string("main")},
        Token{.type = TOKEN_LEFT_PAREN, .value = std::monostate{}},
        Token{.type = TOKEN_RIGHT_PAREN, .value = std::monostate{}},
        Token{.type = TOKEN_LEFT_BRACE, .value = std::monostate{}},
        Token{.type = TOKEN_INT, .value = std::monostate{}},
        Token{.type = TOKEN_IDENTIFIER, .value = std::string("myvar")},
        Token{.type = TOKEN_SEMICOLON, .value = std::monostate{}},
        Token{.type = TOKEN_IDENTIFIER, .value = std::string("myfunc")},
        Token{.type = TOKEN_LEFT_PAREN, .value = std::monostate{}},
        Token{.type = TOKEN_IDENTIFIER, .value = std::string("myvar")},
        Token{.type = TOKEN_RIGHT_PAREN, .value = std::monostate{}},
        Token{.type = TOKEN_SEMICOLON, .value = std::monostate{}},
        Token{.type = TOKEN_RETURN, .value = std::monostate{}},
        Token{.type = TOKEN_INT_LIT, .value = 2L},
        Token{.type = TOKEN_SEMICOLON, .value = std::monostate{}},
        Token{.type = TOKEN_RIGHT_BRACE, .value = std::monostate{}},
    };
    Tokenizer tokenizer("examples/example2.c");
   
    EXPECT_EQ(tokenizer.tokenized_file, expected_vector);
}
