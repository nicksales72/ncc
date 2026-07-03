#include <iostream>

#include "Compiler/Compiler.h"


int main(int argc, char **argv) {
    Compiler compiler;

    if (argc == 2) {
        compiler.runFile(argv[1]);
    } 
    else {
        std::cerr << "Usage: ./ncc <file>\n";
        exit(64);
    }

    return 0;
}
