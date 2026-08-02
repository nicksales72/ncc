#pragma once 

#include <deque>

#include "ast.hpp"
#include "../tokenizer/token.hpp"

Program parseTokens(std::deque<Token>& tokenized_file);
