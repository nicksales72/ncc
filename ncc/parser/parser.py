from ncc.parser.ast import Program, Function, Statement, Exp, Constant
from ncc.lexer.token import Token, TokenType, token_to_string
from ncc.lexer.lexer import Lexer
from collections import deque

def consume(tokens:deque[Tokens], expected:TokenType) -> Token:
    if not tokens:
        raise RuntimeError(f"Expected {token_to_string(expected)}, reached end of input.")

    token = tokens[0]    

    if token.token_type != expected:
        raise RuntimeError(
            f"Expected {token_to_string(expected)}, got "
            f"{token_to_string(token.token_type)} on line {token.token_line}"
        )
    
    tokens.popleft()

    return token

def parse_const(lexer:Lexer) -> Constant:
    """
    <constant> ::= <int> 
    """
    token = consume(lexer.tokens, TokenType.TOKEN_INT_LIT)
    return Constant(token.token_value)

def parse_exp(lexer:Lexer) -> Exp:
    """
    <exp> ::= <constant>
    """
    return Exp(parse_const(lexer))

def parse_statement(lexer:Lexer) -> Statement:
    """
    <statement> ::= "return" <exp> ";"
    """
    consume(lexer.tokens, TokenType.TOKEN_RETURN)

    expression = parse_exp(lexer)

    consume(lexer.tokens, TokenType.TOKEN_SEMICOLON)

    return Statement(expression)

def parse_function(lexer:Lexer) -> Function:
    """
    <function> ::= "int" <id> "(" ")" "{" <statement> "}"
    """
    consume(lexer.tokens, TokenType.TOKEN_INT)

    function_identifier = consume(lexer.tokens, TokenType.TOKEN_IDENTIFIER)
    function_name = function_identifier.token_value

    consume(lexer.tokens, TokenType.TOKEN_LEFT_PAREN)
    consume(lexer.tokens, TokenType.TOKEN_RIGHT_PAREN)
    consume(lexer.tokens, TokenType.TOKEN_LEFT_BRACE)

    function_statement = parse_statement(lexer)

    consume(lexer.tokens, TokenType.TOKEN_RIGHT_BRACE)

    return Function(function_name=function_name, function_statement=function_statement)

def parse_program(lexer:Lexer) -> Program:
    """
    <program> ::= <function>
    """
    return Program(parse_function(lexer))