#include <iostream>
#include <vector>

#include "Compiler.h"
#include "Helpers.h"
#include "Scanner.h"

Compiler::Compiler() { }

void Compiler::runFile(std::string path) {
    std::vector<char> bytes = readFile(path);
    std::string str(bytes.begin(), bytes.end());
    run(str);

    if (had_error) exit(65);
}

void Compiler::run(std::string source) {
    Scanner scanner(source);
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

void Compiler::error(std::string line, std::string message) {
    // format std::string line like "vertical_linenum:horizontal_linenum"
    report(line, "src/temp.c", message);
}

void Compiler::report(std::string line, std::string where, std::string message) {
    std::cerr << "Error --> " << where << ":" << line << '\n' << message << '\n';
    had_error = true;
}
