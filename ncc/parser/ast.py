from dataclasses import dataclass

@dataclass 
class Constant:
    value: int

    def __repr__(self):
        return f"Const({self.value})"

@dataclass 
class Exp:
    value: Constant

    def __repr__(self):
        return f"Exp({self.value})"

@dataclass 
class Statement:
    return_expression: Exp

    def __repr__(self):
        return f"Statement({self.return_expression})"

@dataclass 
class Function:
    function_name: str
    function_statement: Statement

    def __repr__(self):
        return f"Function(Name: {self.function_name}, {self.function_statement})"

@dataclass 
class Program:
    program_function: Function

    def __repr__(self):
        return f"Program({self.program_function})\n"