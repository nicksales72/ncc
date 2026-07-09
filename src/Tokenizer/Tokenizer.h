#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <iostream>

enum TokenType {
    TOKEN_LEFT_BRACE, TOKEN_RIGHT_BRACE,      // {  }
    TOKEN_LEFT_PAREN, TOKEN_RIGHT_PAREN,      // (  )
    TOKEN_SEMICOLON,                          // ;
    TOKEN_INT, TOKEN_RETURN,                  // int  return
    TOKEN_IDENTIFIER,                         // [a-zA-Z]\w*
    TOKEN_INT_LIT,                            // [0-9]+
    TOKEN_EOF
};

class Tokenizer {
    public: 
        Tokenizer(std::string path);
        ~Tokenizer() = default;
    private:
        //std::vector 
};


#endif
