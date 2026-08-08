#include "codegen.hpp"
#include "../helpers/helpers.hpp"
#include <variant>

std::string emitConst(const Constant& constant) {
    // can only emit int currently
    return std::to_string(constant.value);
}

std::string emitUnOp(const UnaryOp& unop) {
    if (unop.unary_operator == '-') { // just to avoid error for now
        return "not implemented";
    } 
    return "not implemented";
}

std::string emitExp(const Exp& expression) {
    if (std::holds_alternative<Constant>(expression.value)) {
        return emitConst(std::get<Constant>(expression.value));
    }
    return emitUnOp(std::get<UnaryOp>(expression.value));
}

std::string emitStatement(const Statement& statement) {
    return "\tmov $" + emitExp(statement.return_expression) + ", %rax\n\tret";
}

std::string emitFunction(const Function& function) {
    return ".global " + function.function_name + '\n' 
           + function.function_name + ":" + '\n'
           + emitStatement(function.function_statement);
}

std::string emitProgram(const Program& program) {
    return emitFunction(program.program_function) + "\n\0";
}

std::string emitAsm(const Program& program, const std::string& output_name) {
    const std::string assembly = emitProgram(program);
    writeAsm(assembly, output_name);
    return assembly;
}
