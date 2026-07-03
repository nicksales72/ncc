#include <iostream>
#include <string>
#include <vector>

#include "helpers.h"

class NccCompiler {
    public:
        NccCompiler();
        void runFile(std::string path);
        void error(std::string line, std::string message);
    private:
        bool had_error;
        void run(std::string source);
        void report(std::string line, std::string where, std::string message);
};

class Token {
    public: 
        Token();
};

class Scanner {
    public: 
        Scanner();
        std::vector<Token> scanTokens();
};

Scanner::Scanner() {
    // remove
    std::cout << "scanner\n";
}

NccCompiler::NccCompiler() { }

void NccCompiler::runFile(std::string path) {
    std::vector<char> bytes = readFile(path);
    std::string str(bytes.begin(), bytes.end());
    run(str);

    if (had_error) exit(65);
}

void NccCompiler::run(std::string source) {
    Scanner scanner;
    //std::vector<Token> tokens = scanner.scanTokens();

    /*
    for (Token token : tokens) {
        std::cout << token;
    }
    */
    
    // remove
    error("66:25", "cannot do stupid thing you did"); // Error --> src/temp.c:66:25
                                                      // cannot do stupid thing you did
}

void NccCompiler::error(std::string line, std::string message) {
    // format std::string line like "vertical_linenum:horizontal_linenum"
    report(line, "src/temp.c", message);
}

void NccCompiler::report(std::string line, std::string where, std::string message) {
    std::cerr << "Error --> " << where << ":" << line << '\n' << message << '\n';
    had_error = true;
}

int main(int argc, char **argv) {
    NccCompiler compiler;

    if (argc == 2) {
        compiler.runFile(argv[1]);
    } 
    else {
        std::cerr << "Usage: ./ncc <file>\n";
        exit(64);
    }

    return 0;
}
