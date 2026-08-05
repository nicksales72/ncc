#include <fstream>
#include <cstdlib>

#include "helpers.hpp"

std::vector<char> readFile(const std::string& path){
    std::ifstream input(path, std::ios::binary);
    const std::vector<char> bytes((std::istreambuf_iterator<char>(input)), std::istreambuf_iterator<char>());
    return bytes;
}

void writeAsm(const std::string& assembly, const std::string& output_name) {
    std::ofstream my_file("temp.s");
    my_file << assembly;
    my_file.close();

    const std::string cli_command = "gcc temp.s -o " + output_name + " && rm temp.s && ./" + output_name;
    if (!std::system(cli_command.c_str())) {
        throw std::runtime_error("Failed to write cli commands");
    } 
}
