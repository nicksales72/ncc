#pragma once 

#include <vector>
#include <string>

std::vector<char> readFile(const std::string&);
void writeAsm(std::string& assembly, std::string& output_name);
