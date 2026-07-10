#include <regex>

#include "Tokenizer.h"
#include "../Helpers/Helpers.h"

Tokenizer::Tokenizer(const std::string &path) {
    std::vector<char> bytes = readFile(path);
    std::vector<TokenType> tokenized_file = tokenizeFile(bytes);

    for (TokenType x : tokenized_file) {
        std::cout << tokenToString(x) << "\n";
    }
}

std::vector<TokenType> Tokenizer::tokenizeFile(const std::vector<char> &bytes) {
    std::string last_token = "";
    std::vector<TokenType> tokenize_vec = {};

    // remove this
    for (char temp : bytes) {
        std::cout << temp;
    }
    std::cout << '\n';

    for (char token : bytes) {
        //std::cout << last_token << '\n';
        if (token == ' ' || token == '{' || token == '}' || token == '(' || token == ')' || token == ';') {
            switch (token) {
                case '{': 
                    tokenize_vec.push_back(TOKEN_LEFT_BRACE);
                    break;
                case '}': 
                    tokenize_vec.push_back(TOKEN_RIGHT_BRACE);
                    break;
                case '(': 
                    tokenize_vec.push_back(TOKEN_LEFT_PAREN);
                    break;
                case ')': 
                    tokenize_vec.push_back(TOKEN_RIGHT_PAREN);
                    break;
                case ';': 
                    tokenize_vec.push_back(TOKEN_SEMICOLON);
                    break;
            }

            if (last_token == "int") {
                tokenize_vec.push_back(TOKEN_INT);
            } else if (last_token == "return") {
                tokenize_vec.push_back(TOKEN_RETURN);
            } else if (std::regex_match(last_token, std::regex("[a-zA-Z]\\w*"))) {
                tokenize_vec.push_back(TOKEN_IDENTIFIER);
            } else if (std::regex_match(last_token, std::regex("[0-9]+"))) {
                tokenize_vec.push_back(TOKEN_INT_LIT);
            }

            last_token = "";
            continue;
        } else if (std::isalnum(token)) {
            last_token += token;
        }
    } 
    return tokenize_vec;
}
