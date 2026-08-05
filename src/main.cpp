#include <iostream>

#include "lexer/lexer.hpp"
#include "codegen/codegen.hpp"
#include "parser/parser.hpp"
#include "helpers/helpers.hpp"

int main(int argc, char** argv) {
    if (argc == 4) {
        std::vector<char> bytes = readFile(argv[1]);
        Lexer lexer(bytes);

        std::deque<Token> tokens = lexer.getTokens();
        Program program_ast = parseTokens(tokens);

        emitAsm(program_ast, std::string(argv[3]));
    } else if (argc == 5) { // DEBUG=1 or DEBUG=0
        const std::string_view debug_arg{argv[4]};

        if (debug_arg != "DEBUG=1" && debug_arg != "DEBUG=0") {     
            std::cerr << "Usage: ./ncc <file> -o <exec_name> [DEBUG=0|DEBUG=1]\n";
            return 2;
        }

        if (debug_arg == "DEBUG=1") {
            std::vector<char> bytes = readFile(argv[1]);
            std::cout << "-----PROGRAM-----" << '\n';
            for (char temp : bytes) {
                std::cout << temp;
            }
            std::cout << '\n';

            Lexer lexer(bytes);

            std::deque<Token> tokens = lexer.getTokens();
            std::cout << "-----TOKENS-----" << '\n';
            for (Token token : tokens) {
                std::cout << token << '\n';
            }
            std::cout << '\n';

            Program program_ast = parseTokens(tokens);
            std::cout << "-----TOKENS AFTER AST CREATION (SHOULD BE EMPTY)-----" << '\n';
            for (Token token : tokens) {
                std::cout << token << '\n';
            }
            std::cout << '\n';
            std::cout << "-----AST-----" << '\n';
            std::cout << program_ast;

            std::string assembly = emitAsm(program_ast, std::string(argv[3]));
            std::cout << '\n';
            std::cout << "-----ASSEMBLY-----" << '\n';
            std::cout << assembly;
        } else {
            std::vector<char> file = readFile(argv[1]);
            Lexer lexer(file);

            std::deque<Token> tokens = lexer.getTokens();
            Program program_ast = parseTokens(tokens);

            emitAsm(program_ast, std::string(argv[3]));
        }
    } else {
        std::cerr << "Usage: ./ncc <file> -o <exec_name> [DEBUG=0|DEBUG=1]\n";
        return 2;
    }
    return 0;
}
