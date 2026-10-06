from ncc.helpers.helpers import write_asm
from ncc.parser.ast import Program, Function, Statement, Exp, Constant

def emit_const(constant:Constant) -> int:
    return constant.value

def emit_exp(expression:Exp) -> str:
    return f"{emit_const(expression.value)}"

def emit_statement(statement:Statement) -> str:
    return f"\tmov ${emit_exp(statement.return_expression)}, %rax\n\tret"

def emit_function(function:Function) -> str:
    return (f".global {function.function_name}\n"
            f"{function.function_name}:\n"
            f"{emit_statement(function.function_statement)}"
    )

def emit_program(program:Program) -> str:
    return f"{emit_function(program.program_function)}\n"

def emit_asm(program:Program, output_name:str) -> str:
    assembly = emit_program(program)
    write_asm(assembly, output_name)
    return assembly