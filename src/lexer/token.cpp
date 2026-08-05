#include "token.hpp"

std::string tokenToString(const TokenType t) {
    switch (t) {
        case TokenType::TOKEN_LEFT_BRACE: return "TOKEN_LEFT_BRACE";
        case TokenType::TOKEN_RIGHT_BRACE: return "TOKEN_RIGHT_BRACE";
        case TokenType::TOKEN_LEFT_PAREN: return "TOKEN_LEFT_PAREN";
        case TokenType::TOKEN_RIGHT_PAREN: return "TOKEN_RIGHT_PAREN";
        case TokenType::TOKEN_SEMICOLON: return "TOKEN_SEMICOLON";
        case TokenType::TOKEN_INT: return "TOKEN_INT";
        case TokenType::TOKEN_RETURN: return "TOKEN_RETURN";
        case TokenType::TOKEN_IDENTIFIER: return "TOKEN_IDENTIFIER";
        case TokenType::TOKEN_INT_LIT: return "TOKEN_INT_LIT";
        case TokenType::TOKEN_EOF: return "TOKEN_EOF";
    }
    return "?";
}
