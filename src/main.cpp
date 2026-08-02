#include <iostream>

#include "lexer/lexer.hpp"
#include "codegen/codegen.hpp"
#include "parser/parser.hpp"

int main(int argc, char **argv) {
    if (argc == 4) {
        Lexer lexer(argv[1]);
        Program program_ast = parseTokens(lexer.tokenized_file);
        emitAssm(program_ast, std::string(argv[3]));
    } else {
        std::cerr << "Usage: ./ncc <file> -o <exec_name>\n";
        exit(64);
    }

    return 0;
}
