#include <iostream>

#include "tokenizer/tokenizer.hpp"

int main(int argc, char **argv) {
    if (argc == 4) {
        Tokenizer tokenizer(argv[1]);
        Program program_ast = parseTokens(tokenizer.tokenized_file);
    } else {
        std::cerr << "Usage: ./ncc <file> -o <exec_name>\n";
        exit(64);
    }

    return 0;
}
