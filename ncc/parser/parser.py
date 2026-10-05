from ncc.parser.ast import Program, Function, Statement, Exp, Constant, UOp
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
    <exp> ::= <unary_op> <exp> | <int>
    <unary_op> ::= "!" | "~" | "-"
    """
    next_token = lexer.get_tokens()[0]

    assert next_token.token_type in {TokenType.TOKEN_INT_LIT, TokenType.TOKEN_NEG, TokenType.TOKEN_COMPLEMENT, TokenType.TOKEN_LOG_NEG}

    if next_token.token_type == TokenType.TOKEN_INT_LIT:
        return Exp(parse_const(lexer))
    else:
        operator = consume(lexer.tokens, next_token.token_type)
        operand = parse_exp(lexer)
        return UOp(operator, operand)

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