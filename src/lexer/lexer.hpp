#pragma once

#include <deque>
#include <vector>

#include "token.hpp"

class Lexer {
public: 
    Lexer(const std::vector<char>&);
    ~Lexer() = default;

    std::deque<Token> tokenized_file;

private:
    std::deque<Token> tokenizeFile(const std::vector<char>&);
};
