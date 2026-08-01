#include <regex>

#include "tokenizer.hpp"
#include "../helpers/helpers.hpp"

Tokenizer::Tokenizer(const std::string &path) {
    const std::vector<char> bytes = readFile(path);
    tokenized_file = tokenizeFile(bytes);
    parseTokens(tokenized_file);
}

std::deque<Token> Tokenizer::tokenizeFile(const std::vector<char> &bytes) {
    std::string last_token = "";
    std::deque<Token> tokenize_queue = {};

    // remove this
    for (char temp : bytes) {
        std::cout << temp;
    }
    std::cout << '\n';

    for (char token : bytes) {
        if (token == ' ' || token == '{' || token == '}' || token == '(' || token == ')' || token == ';') { 
            if (last_token == "int") {
                tokenize_queue.push_back(Token{.type=TOKEN_INT, .value = std::monostate{}});
            } else if (last_token == "return") {
                tokenize_queue.push_back(Token{.type=TOKEN_RETURN, .value = std::monostate{}});
            } else if (std::regex_match(last_token, std::regex("[a-zA-Z]\\w*"))) {
                tokenize_queue.push_back(Token{.type=TOKEN_IDENTIFIER, .value=last_token});
            } else if (std::regex_match(last_token, std::regex("[0-9]+"))) {
                tokenize_queue.push_back(Token{.type=TOKEN_INT_LIT, .value=std::stoi(last_token)});
            }

            switch (token) {
                case '{': 
                    tokenize_queue.push_back(Token{.type=TOKEN_LEFT_BRACE, .value = std::monostate{}});
                    break;
                case '}': 
                    tokenize_queue.push_back(Token{.type=TOKEN_RIGHT_BRACE, .value = std::monostate{}});
                    break;
                case '(': 
                    tokenize_queue.push_back(Token{.type=TOKEN_LEFT_PAREN, .value = std::monostate{}});
                    break;
                case ')': 
                    tokenize_queue.push_back(Token{.type=TOKEN_RIGHT_PAREN, .value = std::monostate{}});
                    break;
                case ';': 
                    tokenize_queue.push_back(Token{.type=TOKEN_SEMICOLON, .value = std::monostate{}});
                    break;
            }
            
            last_token = "";
            continue;
        } else if (std::isalnum(token)) {
            last_token += token;
        }
    } 
    return tokenize_queue;
}

struct Exp {
    int value{};   
};

struct Statement {
    Exp return_expression;
};

struct Function {
    Statement function_statement;
};

struct Program {
    Function program_function;
};

//Statement parseStatement(std::vector<Token> &tokenize_file) {
    /*
     <statement> ::= "return" <exp> ";"
     <exp> ::= <int>
    */
//}

void parseTokens(std::deque<Token> &tokenized_file) { 
    tokenPrint(tokenized_file);
    tokenized_file.pop_front();
    std::cout << '\n';
    tokenPrint(tokenized_file);
}

