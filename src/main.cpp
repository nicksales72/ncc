#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class CCompiler {
    bool had_error;
    bool had_runtime_error;
    public:
        CCompiler();
        void runFile(std::string path);
    private:
        void run();
        std::vector<char> readFile(std::string path);
};

CCompiler::CCompiler() { }

void CCompiler::runFile(std::string path) {
    std::vector<char> bytes = readFile(path);
    for (char thing : bytes) {
        std::cout << thing;
    }
}

std::vector<char> CCompiler::readFile(std::string path) {
    std::ifstream input(path, std::ios::binary);
    std::vector<char> bytes((std::istreambuf_iterator<char>(input)), std::istreambuf_iterator<char>());
    return bytes;
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
