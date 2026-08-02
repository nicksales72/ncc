#include <regex>
#include <variant>

#include "tokenizer.hpp"
#include "../helpers/helpers.hpp"

Tokenizer::Tokenizer(const std::string& path) {
    const std::vector<char> bytes = readFile(path);
    tokenized_file = tokenizeFile(bytes);

    // remove this
    std::cout << "-----TOKENS-----" << '\n';
    for (Token token : tokenized_file) {
        std::cout << token << '\n';
    }
    std::cout << '\n';
}

std::deque<Token> Tokenizer::tokenizeFile(const std::vector<char>& bytes) {
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
    Exp expression = Exp{std::get<int>(token.value)};

    return expression;
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

std::string tokenToString(TokenType t) {
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

std::string emitExp(Exp expression) {
    // can only emit int currently
    return std::to_string(expression.value);
}

std::string emitStatement(Statement statement) {
    return "\tmov $" + emitExp(statement.return_expression) + ", %rax\n\tret";
}

std::string emitFunction(Function function) {
    return ".global " + function.function_name + '\n' 
           + function.function_name + ":" + '\n'
           + emitStatement(function.function_statement);
}

std::string emitProgram(Program program) {
    return emitFunction(program.program_function) + "\n\0";
}

void emitAssm(Program program, std::string output_name) {
    std::string assembly = emitProgram(program);

    //remove
    std::cout << '\n';
    std::cout << "-----ASSEMBLY-----" << '\n';
    std::cout << assembly;

    writeAssm(assembly, output_name);
}
