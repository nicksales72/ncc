#pragma once

#include <iostream>
#include <deque>
#include <vector>

#include "token.hpp"

class Lexer {
public: 
    Lexer(const std::string&);
    ~Lexer() = default;

    std::deque<Token> tokenized_file;

private:
    std::deque<Token> tokenizeFile(const std::vector<char>&);
};
