#ifndef HELPERS_H
#define HELPERS_H

#include <vector>
#include <string>

#include "../tokenizer/tokenizer.hpp"

std::vector<char> readFile(const std::string&);
std::string tokenToString(TokenType t);
void tokenPrint(std::deque<Token> tokenized_file);

#endif
