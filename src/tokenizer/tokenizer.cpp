#include <regex>

#include "tokenizer.hpp"
#include "../helpers/helpers.hpp"

Tokenizer::Tokenizer(const std::string &path) {
    const std::vector<char> bytes = readFile(path);
    tokenized_file = tokenizeFile(bytes);

    // remove this
    for (Token token : tokenized_file) {
        std::cout << token << '\n';
    }

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
    friend std::ostream& operator<<(std::ostream& os, const Exp& exp) {
        os << "Exp(" << exp.value;
        return os;
    }
};

struct Statement {
    Exp return_expression;
    friend std::ostream& operator<<(std::ostream& os, const Statement& statement) {
        os << "Statement(" << statement.return_expression;
        return os;
    }
};

struct Function {
    std::string function_name;
    Statement function_statement;
    friend std::ostream& operator<<(std::ostream& os, const Function& function) {
        os << "Function(Name: " << function.function_name << ", " << function.function_statement << ")";
        return os;
    }
};

struct Program {
    Function program_function;
    friend std::ostream& operator<<(std::ostream& os, const Program& program) {
        os << "Program(" << program.program_function << ")" << '\n';
        return os;
    }
};

Statement parseStatement(std::deque<Token> &tokenized_file) {
    /*
     <statement> ::= "return" <exp> ";"
     <exp> ::= <int>
     */

    if (tokenized_file[0].type != TOKEN_RETURN) {
        // fail or something
        std::cout << "we fail on statement";
    }

    int value;
    for (Token token : tokenized_file) {
        if (token.type == TOKEN_INT_LIT) value = 2;
        if (token.type != TOKEN_SEMICOLON) {
            tokenized_file.pop_front();
            continue;
        } else {
            tokenized_file.pop_front();
            break;
        }
    } 
    return Statement{value};
}

Function parseFunction(std::deque<Token> &tokenized_file) {
    /*
     <function> ::= "int" <id> "(" ")" "{" <statement> "}"
     */
    if (tokenized_file[0].type != TOKEN_INT) {
        // fail or something
        std::cout << "we fail on function";
    }

    std::string function_name;
    for (Token token : tokenized_file) {
        if (token.type == TOKEN_IDENTIFIER) function_name = "main"; // temp: need to make this the identifier name 
        if (token.type != TOKEN_LEFT_BRACE) {
            tokenized_file.pop_front();
            continue;
        } else {
            tokenized_file.pop_front();
            break;
        }
    } 
    return Function{.function_name = function_name, .function_statement=parseStatement(tokenized_file)};
}

Program parseProgram(std::deque<Token> &tokenized_file) {
    /* 
     <program> ::= <function>
     */
    return Program{parseFunction(tokenized_file)};
}

void parseTokens(std::deque<Token> &tokenized_file) { 
    Program program = parseProgram(tokenized_file);
    if (!tokenized_file.empty()) tokenized_file.pop_front();

    // remove this
    std::cout << '\n';
    for (Token token : tokenized_file) {
        std::cout << token << '\n';
    }
    std::cout << "AST: " << program;
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
