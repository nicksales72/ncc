#pragma once

#include <iostream>
#include <deque>
#include <vector>

#include "token.hpp"
#include "../parser/ast.hpp"

class Tokenizer {
public: 
    Tokenizer(const std::string&);
    ~Tokenizer() = default;

    std::deque<Token> tokenized_file;

private:
    std::deque<Token> tokenizeFile(const std::vector<char>&);
};

void emitAssm(Program program, std::string output_name);
