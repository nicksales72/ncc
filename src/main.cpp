#include <iostream>

#include "lexer/lexer.hpp"
#include "codegen/codegen.hpp"
#include "parser/parser.hpp"
#include "helpers/helpers.hpp"

int main(int argc, char **argv) {
    if (argc == 4) {
        const std::vector<char> bytes = readFile(argv[1]);
        Lexer lexer(bytes);
        Program program_ast = parseTokens(lexer.tokenized_file);
        emitAsm(program_ast, std::string(argv[3]));
    } else {
        std::cerr << "Usage: ./ncc <file> -o <exec_name>\n";
        exit(64);
    }

    return 0;
}
