#pragma once 

#include "../parser/ast.hpp"

std::string emitAsm(Program program, std::string output_name);
