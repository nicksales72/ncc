import unittest
from collections import deque
from ncc.helpers.helpers import read_file
from ncc.lexer.lexer import Token, TokenType, Lexer

class TestLexer(unittest.TestCase):
    def test_tokenize_example(self):
        expected_deque = deque([
            Token(token_type=TokenType.TOKEN_INT, token_value=None, token_line=1),
            Token(token_type=TokenType.TOKEN_IDENTIFIER, token_value="main", token_line=1),
            Token(token_type=TokenType.TOKEN_LEFT_PAREN, token_value=None, token_line=1),
            Token(token_type=TokenType.TOKEN_RIGHT_PAREN, token_value=None, token_line=1),
            Token(token_type=TokenType.TOKEN_LEFT_BRACE, token_value=None, token_line=1),
            Token(token_type=TokenType.TOKEN_RETURN, token_value=None, token_line=2),
            Token(token_type=TokenType.TOKEN_INT_LIT, token_value=2, token_line=2),
            Token(token_type=TokenType.TOKEN_SEMICOLON, token_value=None, token_line=2),
            Token(token_type=TokenType.TOKEN_RIGHT_BRACE, token_value=None, token_line=3),
        ])        
        assert Lexer(file=read_file("examples/example.c")).get_tokens() == expected_deque

if __name__ == "__main__":
    unittest.main()