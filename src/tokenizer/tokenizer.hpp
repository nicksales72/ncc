#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <iostream>
#include <vector>
#include <variant>

enum TokenType {
    TOKEN_LEFT_BRACE, TOKEN_RIGHT_BRACE,      // {  }
    TOKEN_LEFT_PAREN, TOKEN_RIGHT_PAREN,      // (  )
    TOKEN_SEMICOLON,                          // ;
    TOKEN_INT, TOKEN_RETURN,                  // int  return
    TOKEN_IDENTIFIER,                         // [a-zA-Z]\w*
    TOKEN_INT_LIT,                            // [0-9]+
    TOKEN_EOF
};

struct Token {
    TokenType type; 
    std::variant<std::monostate, long, std::string> value;
    // need to add int line; later
    bool operator==(const Token &other) const {
        return type == other.type && value == other.value;
    }
};

class Tokenizer {
    public: 
        Tokenizer(const std::string&);
        ~Tokenizer() = default;
        std::vector<Token> tokenized_file;
    private:
        std::vector<Token> tokenizeFile(const std::vector<char>&);
};

#endif
