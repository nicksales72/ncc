#ifndef HELPERS_H
#define HELPERS_H

#include <vector>
#include <string>

#include "../Tokenizer/Tokenizer.hpp"

std::vector<char> readFile(const std::string&);
std::string tokenToString(TokenType t);

#endif
