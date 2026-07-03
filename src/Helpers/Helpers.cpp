#include <fstream>

#include "Helpers.h"

std::vector<char> readFile(std::string path){
    std::ifstream input(path, std::ios::binary);
    std::vector<char> bytes((std::istreambuf_iterator<char>(input)), std::istreambuf_iterator<char>());
    return bytes;
}
