#include "codegen.hpp"
#include "../helpers/helpers.hpp"

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

std::string emitAsm(Program program, std::string output_name) {
    std::string assembly = emitProgram(program);
    writeAsm(assembly, output_name);
    return assembly;
}
