#include <regex>
#include <variant>
#include <iostream>

#include "lexer.hpp"

Lexer::Lexer(const std::vector<char>& bytes) {
    tokenized_file = tokenizeFile(bytes);

    // remove this
    std::cout << "-----TOKENS-----" << '\n';
    for (Token token : tokenized_file) {
        std::cout << token << '\n';
    }
    std::cout << '\n';
}

std::deque<Token> Lexer::tokenizeFile(const std::vector<char>& bytes) {
    std::string last_token = "";
    std::deque<Token> tokenize_queue = {};

    // remove this
    std::cout << "-----PROGRAM-----" << '\n';
    for (char temp : bytes) {
        std::cout << temp;
    }
    std::cout << '\n';

    int line_num = 1;
    for (char character : bytes) {
        if (character == ' ' || character == '{' || character == '}' || character == '(' 
            || character == ')' || character == ';' || character == '\n') { 
            if (character == '\n') {
                line_num++;
            }
            if (last_token == "int") {
                tokenize_queue.push_back(Token{.type=TOKEN_INT, .value = std::monostate{}, .line=line_num});
            } else if (last_token == "return") {
                tokenize_queue.push_back(Token{.type=TOKEN_RETURN, .value = std::monostate{}, .line=line_num});
            } else if (std::regex_match(last_token, std::regex("[a-zA-Z]\\w*"))) {
                tokenize_queue.push_back(Token{.type=TOKEN_IDENTIFIER, .value=last_token, .line=line_num});
            } else if (std::regex_match(last_token, std::regex("[0-9]+"))) {
                tokenize_queue.push_back(Token{.type=TOKEN_INT_LIT, .value=std::stoi(last_token), .line=line_num});
            }

            switch (character) {
                case '{': 
                    tokenize_queue.push_back(Token{.type=TOKEN_LEFT_BRACE, .value = std::monostate{}, .line=line_num});
                    break;
                case '}': 
                    tokenize_queue.push_back(Token{.type=TOKEN_RIGHT_BRACE, .value = std::monostate{}, .line=line_num});
                    break;
                case '(': 
                    tokenize_queue.push_back(Token{.type=TOKEN_LEFT_PAREN, .value = std::monostate{}, .line=line_num});
                    break;
                case ')': 
                    tokenize_queue.push_back(Token{.type=TOKEN_RIGHT_PAREN, .value = std::monostate{}, .line=line_num});
                    break;
                case ';': 
                    tokenize_queue.push_back(Token{.type=TOKEN_SEMICOLON, .value = std::monostate{}, .line=line_num});
                    break;
            }
            
            last_token = "";
            continue;
        } else if (std::isalnum(character) || character == '_') {
            last_token += character;
        } else {
            throw std::runtime_error("Unexpected character on line " + std::to_string(line_num));
        }
    } 
    return tokenize_queue;
}
