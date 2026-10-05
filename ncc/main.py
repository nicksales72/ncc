import sys
from ncc.helpers.helpers import read_file
from ncc.lexer.lexer import Lexer
from ncc.parser.parser import parse_program
from ncc.codegen.codegen import emit_asm

def compile_no_debug(file_path:str, output_name:str) -> None:
    file = read_file(file_path)
    lexer = Lexer(file)

    tokens = lexer.get_tokens()
    program_ast = parse_program(lexer)    

    emit_asm(program_ast, output_name)

def compile_debug(file_path:str, output_name:str) -> None:
    file = read_file(file_path)
    print("-----PROGRAM-----")
    for line in file.splitlines():
        print(line)

    lexer = Lexer(file)

    tokens = lexer.get_tokens()
    print("\n-----TOKENS-----")
    for token in tokens:
        print(token)

    program_ast = parse_program(lexer)    
    print("\n-----TOKENS AFTER AST CREATION (SHOULD BE EMPTY)-----")
    tokens = lexer.get_tokens()
    for token in tokens:
        print(token)

    print("\n-----AST-----")
    print(program_ast)

    assembly = emit_asm(program_ast, output_name)
    print("\n-----ASSEMBLY-----")
    print(assembly)

def main() -> None:
    argc, argv = len(sys.argv), sys.argv
    usage = "Usage: python -m ncc.main <file> -o <exec_name> [DEBUG=0|DEBUG=1]"

    if argc == 4: 
        compile_no_debug(argv[1], argv[3])
    elif argc == 5: 
        if argv[4] not in {"DEBUG=0", "DEBUG=1"}:
            sys.exit(usage)

        if argv[4] == "DEBUG=0":
            compile_no_debug(argv[1], argv[3])
        else: 
            compile_debug(argv[1], argv[3])
    else: 
        sys.exit(usage)

if __name__ == "__main__":
    main()