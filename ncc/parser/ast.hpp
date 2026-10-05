#pragma once 

#include <ostream>
#include <variant>
#include <memory>

struct Exp;

struct Constant {
    int value{};

    friend std::ostream& operator<<(std::ostream& os, const Constant& constant) {
        return os << "Const(" << constant.value << ")";
    }
};

struct UnaryOp {
    char unary_operator; 
    std::shared_ptr<const Exp> unary_operand;

    friend std::ostream& operator<<(std::ostream&, const UnaryOp&);
};

struct Exp {
    std::variant<Constant, UnaryOp> value;

    friend std::ostream& operator<<(std::ostream& os, const Exp& exp) {
        if (std::holds_alternative<Constant>(exp.value)) {
            return os << "Exp(" << std::get<Constant>(exp.value) << ")";
        }
        return os << "Exp(" << std::get<UnaryOp>(exp.value) << ")";
    }
};

inline std::ostream& operator<<(std::ostream& os, const UnaryOp& unop) {
    return os << "UnaryOp(Operator: '" << unop.unary_operator << "', Operand: " << *unop.unary_operand << ")";
}

struct Statement {
    const Exp return_expression;

    friend std::ostream& operator<<(std::ostream& os, const Statement& statement) {
        return os << "Statement(" << statement.return_expression << ")";
    }
};

struct Function {
    const std::string function_name;
    const Statement function_statement;

    friend std::ostream& operator<<(std::ostream& os, const Function& function) {
        return os << "Function(Name: " << function.function_name << ", " << function.function_statement << ")";
    }
};

struct Program {
    const Function program_function;

    friend std::ostream& operator<<(std::ostream& os, const Program& program) {
        return os << "Program(" << program.program_function << ")" << '\n';
    }
};
