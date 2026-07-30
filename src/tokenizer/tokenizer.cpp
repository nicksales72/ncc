#include <regex>

#include "tokenizer.hpp"
#include "../helpers/helpers.hpp"

Tokenizer::Tokenizer(const std::vector<char> &bytes) {
    tokenized_file = tokenizeFile(bytes);

    // remove this
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
        if (token == ' ' || token == '{' || token == '}' || token == '(' || token == ')' || token == ';') {
            if (last_token == "int") {
                tokenize_vec.push_back(TOKEN_INT);
            } else if (last_token == "return") {
                tokenize_vec.push_back(TOKEN_RETURN);
            } else if (std::regex_match(last_token, std::regex("[a-zA-Z]\\w*"))) {
                tokenize_vec.push_back(TOKEN_IDENTIFIER);
            } else if (std::regex_match(last_token, std::regex("[0-9]+"))) {
                tokenize_vec.push_back(TOKEN_INT_LIT);
            }

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
            
            last_token = "";
            continue;
        } else if (std::isalnum(token)) {
            last_token += token;
        }
    } 
    return tokenize_vec;
}
