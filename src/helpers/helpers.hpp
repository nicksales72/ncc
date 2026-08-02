#pragma once 

#include <vector>
#include <string>

std::vector<char> readFile(const std::string&);
void writeAssm(std::string& assembly, std::string& output_name);
