#include <iostream>

#include "tokenizer/tokenizer.hpp"

int main(int argc, char **argv) {
    if (argc == 2) {
        Tokenizer tokenizer(argv[1]);
    } else {
        std::cerr << "Usage: ./ncc <file>\n";
        exit(64);
    }

    return 0;
}
