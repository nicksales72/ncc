#pragma once

#include <iostream>
#include <deque>
#include <vector>
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
                           
    TOKEN_EOF
};

std::string tokenToString(TokenType t);

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

class Tokenizer {
public: 
    Tokenizer(const std::string&);
    ~Tokenizer() = default;

    std::deque<Token> tokenized_file;

private:
    std::deque<Token> tokenizeFile(const std::vector<char>&);
};

struct Exp {
    int value{};   

    friend std::ostream& operator<<(std::ostream& os, const Exp& exp) {
        return os << "Exp(" << exp.value << ")";
    }
};

struct Statement {
    Exp return_expression;

    friend std::ostream& operator<<(std::ostream& os, const Statement& statement) {
        return os << "Statement(" << statement.return_expression << ")";
    }
};

struct Function {
    std::string function_name;
    Statement function_statement;

    friend std::ostream& operator<<(std::ostream& os, const Function& function) {
        return os << "Function(Name: " << function.function_name << ", " << function.function_statement << ")";
    }
};

struct Program {
    Function program_function;

    friend std::ostream& operator<<(std::ostream& os, const Program& program) {
        return os << "Program(" << program.program_function << ")" << '\n';
    }
};

Program parseTokens(std::deque<Token>& tokenized_file);
