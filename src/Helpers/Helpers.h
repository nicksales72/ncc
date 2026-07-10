#ifndef HELPERS_H
#define HELPERS_H

#include <vector>
#include <string>

#include "../Tokenizer/Tokenizer.h"

std::vector<char> readFile(std::string path);
std::string tokenToString(TokenType t);

#endif
