#pragma once 

#include "../parser/ast.hpp"

std::string emitAsm(const Program& program, const std::string& output_name);
