#include <iostream>
#include <string>
#include <vector>

#include "helpers.h"

class CCompiler {
    bool had_error;
    bool had_runtime_error;
    public:
        CCompiler();
        void runFile(std::string path);
    private:
        void run();
};

CCompiler::CCompiler() { }

void CCompiler::runFile(std::string path) {
    std::vector<char> bytes = readFile(path);
    for (char thing : bytes) {
        std::cout << thing;
    }
}

int main(int argc, char **argv) {
    CCompiler compiler;

    if (argc == 2) {
        compiler.runFile(argv[1]);
    } else {
        fprintf(stderr, "Usage: ./ncc <file>\n");
        exit(64);
    }

    return 0;
}
