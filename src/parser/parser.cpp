#include "parser.hpp"

Token consume(std::deque<Token>& tokenized_file, TokenType expected) {
    if (tokenized_file.empty()) {
        throw std::runtime_error("Expected " + tokenToString(expected) + ", reached end of input.");
    }
    
    Token token = std::move(tokenized_file.front());
    tokenized_file.pop_front();

    if (token.type != expected) {
        throw std::runtime_error("Expected " + tokenToString(expected) + ", got " 
                                 + tokenToString(token.type) + " on line " + std::to_string(token.line));
    }

    return token;
}

Exp parseExp(std::deque<Token>& tokenized_file) {
    /*
     <exp> ::= <int>
     */
    Token token = consume(tokenized_file, TOKEN_INT_LIT);
    return Exp{std::get<int>(token.value)};
}

Statement parseStatement(std::deque<Token>& tokenized_file) {
    /*
     <statement> ::= "return" <exp> ";"
     */
    consume(tokenized_file, TOKEN_RETURN);

    Exp expression = parseExp(tokenized_file);

    consume(tokenized_file, TOKEN_SEMICOLON);
    
    return Statement{expression};
}

Function parseFunction(std::deque<Token>& tokenized_file) {
    /*
     <function> ::= "int" <id> "(" ")" "{" <statement> "}"
     */
    consume(tokenized_file, TOKEN_INT);

    Token function_identifier = consume(tokenized_file, TOKEN_IDENTIFIER);
    std::string function_name = std::get<std::string>(function_identifier.value);

    consume(tokenized_file, TOKEN_LEFT_PAREN);
    consume(tokenized_file, TOKEN_RIGHT_PAREN);
    consume(tokenized_file, TOKEN_LEFT_BRACE);

    Statement function_statement = parseStatement(tokenized_file);

    consume(tokenized_file, TOKEN_RIGHT_BRACE);

    return Function{.function_name = function_name, .function_statement=std::move(function_statement)};
}

Program parseProgram(std::deque<Token>& tokenized_file) {
    /* 
     <program> ::= <function>
     */
    return Program{parseFunction(tokenized_file)};
}

Program parseTokens(std::deque<Token>& tokenized_file) { 
    Program program = parseProgram(tokenized_file);

    // remove this
    std::cout << "-----TOKENS AFTER AST CREATION (SHOULD BE EMPTY)-----" << '\n';
    for (Token token : tokenized_file) {
        std::cout << token << '\n';
    }
    std::cout << '\n';
    std::cout << "-----AST-----" << '\n';
    std::cout << program;

    return program;
}
