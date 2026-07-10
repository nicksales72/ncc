#include <gtest/gtest.h>
#include <pthread.h>

#include "../src/tokenizer/tokenizer.hpp"

TEST(TokenizerTest, TestExample) {
    std::vector<TokenType> expected_vector = {TOKEN_INT, TOKEN_IDENTIFIER, TOKEN_LEFT_PAREN, TOKEN_RIGHT_PAREN,
                                              TOKEN_LEFT_BRACE, TOKEN_RETURN, TOKEN_INT_LIT, TOKEN_SEMICOLON, TOKEN_RIGHT_BRACE};
    Tokenizer tokenizer("examples/example.c");
   
    EXPECT_EQ(tokenizer.tokenized_file, expected_vector);
}

TEST(TokenizerTest, TestExample1) {
    std::vector<TokenType> expected_vector = {TOKEN_INT, TOKEN_IDENTIFIER, TOKEN_LEFT_PAREN, TOKEN_RIGHT_PAREN,  
                                              TOKEN_LEFT_BRACE, TOKEN_IDENTIFIER, TOKEN_LEFT_PAREN, TOKEN_INT, 
                                              TOKEN_IDENTIFIER, TOKEN_RIGHT_PAREN, TOKEN_SEMICOLON, TOKEN_RETURN, 
                                              TOKEN_INT_LIT, TOKEN_SEMICOLON, TOKEN_RIGHT_BRACE};
    Tokenizer tokenizer("examples/example1.c");
   
    EXPECT_EQ(tokenizer.tokenized_file, expected_vector);
}


TEST(TokenizerTest, TestExample2) {
    std::vector<TokenType> expected_vector = {TOKEN_INT, TOKEN_IDENTIFIER, TOKEN_LEFT_PAREN, TOKEN_INT,
                                              TOKEN_IDENTIFIER, TOKEN_RIGHT_PAREN, TOKEN_LEFT_BRACE, 
                                              TOKEN_RETURN, TOKEN_IDENTIFIER, TOKEN_SEMICOLON, TOKEN_RIGHT_BRACE,
                                              TOKEN_INT, TOKEN_IDENTIFIER, TOKEN_LEFT_PAREN, TOKEN_RIGHT_PAREN,  
                                              TOKEN_LEFT_BRACE, TOKEN_INT, TOKEN_IDENTIFIER, TOKEN_SEMICOLON,
                                              TOKEN_IDENTIFIER, TOKEN_LEFT_PAREN, TOKEN_IDENTIFIER, TOKEN_RIGHT_PAREN,
                                              TOKEN_SEMICOLON, TOKEN_RETURN, TOKEN_INT_LIT, TOKEN_SEMICOLON, TOKEN_RIGHT_BRACE};
    Tokenizer tokenizer("examples/example2.c");
   
    EXPECT_EQ(tokenizer.tokenized_file, expected_vector);
}
