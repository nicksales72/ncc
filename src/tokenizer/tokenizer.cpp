#include <regex>

#include "tokenizer.hpp"
#include "../helpers/helpers.hpp"

Tokenizer::Tokenizer(const std::string &path) {
    std::vector<char> bytes = readFile(path);
    tokenized_file = tokenizeFile(bytes);

    // remove this
    for (Token x : tokenized_file) {
        std::cout << tokenToString(x.type) << ", ";
        std::visit([](auto&& val) {
            using T = std::decay_t<decltype(val)>;
            if constexpr (std::is_same_v<T, std::monostate>)
                std::cout << "(none)";
            else
                std::cout << val;
        }, x.value);
        std::cout << "\n";
    }
}

std::vector<Token> Tokenizer::tokenizeFile(const std::vector<char> &bytes) {
    std::string last_token = "";
    std::vector<Token> tokenize_vec = {};

    // remove this
    for (char temp : bytes) {
        std::cout << temp;
    }
    std::cout << '\n';

    for (char token : bytes) {
        if (token == ' ' || token == '{' || token == '}' || token == '(' || token == ')' || token == ';') {
            if (last_token == "int") {
                tokenize_vec.push_back(Token{.type=TOKEN_INT, .value = std::monostate{}});
            } else if (last_token == "return") {
                tokenize_vec.push_back(Token{.type=TOKEN_RETURN, .value = std::monostate{}});
            } else if (std::regex_match(last_token, std::regex("[a-zA-Z]\\w*"))) {
                tokenize_vec.push_back(Token{.type=TOKEN_IDENTIFIER, .value=last_token});
            } else if (std::regex_match(last_token, std::regex("[0-9]+"))) {
                tokenize_vec.push_back(Token{.type=TOKEN_INT_LIT, .value=std::stoi(last_token)});
            }

            switch (token) {
                case '{': 
                    tokenize_vec.push_back(Token{.type=TOKEN_LEFT_BRACE, .value = std::monostate{}});
                    break;
                case '}': 
                    tokenize_vec.push_back(Token{.type=TOKEN_RIGHT_BRACE, .value = std::monostate{}});
                    break;
                case '(': 
                    tokenize_vec.push_back(Token{.type=TOKEN_LEFT_PAREN, .value = std::monostate{}});
                    break;
                case ')': 
                    tokenize_vec.push_back(Token{.type=TOKEN_RIGHT_PAREN, .value = std::monostate{}});
                    break;
                case ';': 
                    tokenize_vec.push_back(Token{.type=TOKEN_SEMICOLON, .value = std::monostate{}});
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

/**
class Node {

};

void parseTokens(std::vector<Token> tokenized_file) {

}

**/
