#include "codegen.hpp"
#include "../helpers/helpers.hpp"

std::string emitExp(const Exp& expression) {
    // can only emit int currently
    return std::to_string(expression.value);
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
    std::string assembly = emitProgram(program);
    writeAsm(assembly, output_name);
    return assembly;
}
