#pragma once

#include <iostream>
#include <deque>
#include <vector>

#include "token.hpp"

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

void emitAssm(Program program, std::string output_name);
