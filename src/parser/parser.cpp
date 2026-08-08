#include "parser.hpp"

Token consume(std::deque<Token>& tokens, TokenType expected) {
    if (tokens.empty()) {
        throw std::runtime_error("Expected " + tokenToString(expected) + ", reached end of input.");
    }
    
    const Token token = std::move(tokens.front());
    tokens.pop_front();

    if (token.type != expected) {
        throw std::runtime_error("Expected " + tokenToString(expected) + ", got " 
                                 + tokenToString(token.type) + " on line " + std::to_string(token.line));
    }

    return token;
}



Exp parseExp(std::deque<Token>& tokens) {
    /*
     <exp> ::= <int>
     */
    const Token token = consume(tokens, TOKEN_INT_LIT);
    return Exp{std::get<int>(token.value)};
}

Statement parseStatement(std::deque<Token>& tokens) {
    /*
     <statement> ::= "return" <exp> ";"
     */
    consume(tokens, TOKEN_RETURN);

    const Exp expression = parseExp(tokens);

    consume(tokens, TOKEN_SEMICOLON);
    
    return Statement{expression};
}

Function parseFunction(std::deque<Token>& tokens) {
    /*
     <function> ::= "int" <id> "(" ")" "{" <statement> "}"
     */
    consume(tokens, TOKEN_INT);

    const Token function_identifier = consume(tokens, TOKEN_IDENTIFIER);
    const std::string function_name = std::get<std::string>(function_identifier.value);

    consume(tokens, TOKEN_LEFT_PAREN);
    consume(tokens, TOKEN_RIGHT_PAREN);
    consume(tokens, TOKEN_LEFT_BRACE);

    const Statement function_statement = parseStatement(tokens);

    consume(tokens, TOKEN_RIGHT_BRACE);

    return Function{.function_name = function_name, .function_statement=std::move(function_statement)};
}

Program parseProgram(std::deque<Token>& tokens) {
    /* 
     <program> ::= <function>
     */
    return Program{parseFunction(tokens)};
}

Program parseTokens(std::deque<Token>& tokens) { 
    return parseProgram(tokens);
}
