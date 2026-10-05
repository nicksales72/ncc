#pragma once 

#include <ostream>
#include <variant> 

enum TokenType {
    TOKEN_LEFT_BRACE,      // {
    TOKEN_RIGHT_BRACE,     // }
    TOKEN_LEFT_PAREN,      // (
    TOKEN_RIGHT_PAREN,     // )
    TOKEN_SEMICOLON,       // ;
                           
    TOKEN_INT,             // int
    TOKEN_RETURN,          // return
    TOKEN_IDENTIFIER,      // [a-zA-Z]\w*
    TOKEN_INT_LIT,         // [0-9]+

    TOKEN_NEG,             // - 
    TOKEN_COMPLEMENT,      // ~
    TOKEN_LOG_NEG,         // !
                           
    TOKEN_EOF
};

std::string tokenToString(const TokenType t);

struct Token {
    TokenType type; 
    std::variant<std::monostate, int, std::string> value;
    int line;

    bool operator==(const Token& other) const {
        return type == other.type && value == other.value;
    }

    friend std::ostream& operator<<(std::ostream& os, const Token& token) {
        os << "Token Type: " << tokenToString(token.type) << ", " 
           << "Token Line: " << token.line << ", " << "Token Value: ";

        std::visit(
            [&os](const auto& val) {
                using T = std::decay_t<decltype(val)>;

                if constexpr (std::is_same_v<T, std::monostate>) {
                    os << "(none)";
                } else {
                    os << val;
                }
            },
            token.value
        );

        return os;
    }
};
