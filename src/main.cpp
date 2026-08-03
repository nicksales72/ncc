#include <iostream>

#include "lexer/lexer.hpp"
#include "codegen/codegen.hpp"
#include "parser/parser.hpp"
#include "helpers/helpers.hpp"

int main(int argc, char **argv) {
    if (argc == 4) {
        Lexer lexer(readFile(argv[1]));

        std::deque<Token> tokens = lexer.getTokens();
        Program program_ast = parseTokens(tokens);

        emitAsm(program_ast, std::string(argv[3]));
    } else {
        std::cerr << "Usage: ./ncc <file> -o <exec_name>\n";
        exit(64);
    }
    return 0;
}
