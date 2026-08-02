#pragma once 

#include <deque>

#include "ast.hpp"
#include "../lexer/token.hpp"

Program parseTokens(std::deque<Token>&);
