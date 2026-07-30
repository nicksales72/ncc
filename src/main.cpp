#include <iostream>

#include "tokenizer/tokenizer.hpp"
#include "helpers/helpers.hpp"

int main(int argc, char **argv) {
    if (argc == 2) {
        const std::vector<char> bytes = readFile(argv[1]);
        Tokenizer tokenizer(bytes);
    } else {
        std::cerr << "Usage: ./ncc <file>\n";
        exit(64);
    }

    return 0;
}
