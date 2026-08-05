#pragma once 

#include <vector>
#include <string>

std::vector<char> readFile(const std::string&);
void writeAsm(const std::string& assembly, const std::string& output_name);
