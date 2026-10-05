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

    def test_tokenize_example1(self):
        expected_deque = deque([
            Token(token_type=TokenType.TOKEN_INT, token_value=None, token_line=1),
            Token(token_type=TokenType.TOKEN_IDENTIFIER, token_value="main", token_line=1),
            Token(token_type=TokenType.TOKEN_LEFT_PAREN, token_value=None, token_line=1),
            Token(token_type=TokenType.TOKEN_RIGHT_PAREN, token_value=None, token_line=1),
            Token(token_type=TokenType.TOKEN_LEFT_BRACE, token_value=None, token_line=1),
            Token(token_type=TokenType.TOKEN_IDENTIFIER, token_value="my_func", token_line=2),
            Token(token_type=TokenType.TOKEN_LEFT_PAREN, token_value=None, token_line=2),
            Token(token_type=TokenType.TOKEN_INT, token_value=None, token_line=2),
            Token(token_type=TokenType.TOKEN_IDENTIFIER, token_value="my_var", token_line=2),
            Token(token_type=TokenType.TOKEN_RIGHT_PAREN, token_value=None, token_line=2),
            Token(token_type=TokenType.TOKEN_SEMICOLON, token_value=None, token_line=2),
            Token(token_type=TokenType.TOKEN_RETURN, token_value=None, token_line=3),
            Token(token_type=TokenType.TOKEN_INT_LIT, token_value=2, token_line=3),
            Token(token_type=TokenType.TOKEN_SEMICOLON, token_value=None, token_line=3),
            Token(token_type=TokenType.TOKEN_RIGHT_BRACE, token_value=None, token_line=4),
        ])        
        assert Lexer(file=read_file("examples/example1.c")).get_tokens() == expected_deque

    def test_tokenize_example2(self):
        expected_deque = deque([
            Token(token_type=TokenType.TOKEN_INT, token_value=None, token_line=1),
            Token(token_type=TokenType.TOKEN_IDENTIFIER, token_value="my_func", token_line=1),
            Token(token_type=TokenType.TOKEN_LEFT_PAREN, token_value=None, token_line=1),
            Token(token_type=TokenType.TOKEN_INT, token_value=None, token_line=1),
            Token(token_type=TokenType.TOKEN_IDENTIFIER, token_value="my_var", token_line=1),
            Token(token_type=TokenType.TOKEN_RIGHT_PAREN, token_value=None, token_line=1),
            Token(token_type=TokenType.TOKEN_LEFT_BRACE, token_value=None, token_line=1),
            Token(token_type=TokenType.TOKEN_RETURN, token_value=None, token_line=2),
            Token(token_type=TokenType.TOKEN_IDENTIFIER, token_value="my_var", token_line=2),
            Token(token_type=TokenType.TOKEN_SEMICOLON, token_value=None, token_line=2),
            Token(token_type=TokenType.TOKEN_RIGHT_BRACE, token_value=None, token_line=3),
            Token(token_type=TokenType.TOKEN_INT, token_value=None, token_line=5),
            Token(token_type=TokenType.TOKEN_IDENTIFIER, token_value="main", token_line=5),
            Token(token_type=TokenType.TOKEN_LEFT_PAREN, token_value=None, token_line=5),
            Token(token_type=TokenType.TOKEN_RIGHT_PAREN, token_value=None, token_line=5),
            Token(token_type=TokenType.TOKEN_LEFT_BRACE, token_value=None, token_line=5),
            Token(token_type=TokenType.TOKEN_INT, token_value=None, token_line=6),
            Token(token_type=TokenType.TOKEN_IDENTIFIER, token_value="my_var", token_line=6),
            Token(token_type=TokenType.TOKEN_SEMICOLON, token_value=None, token_line=6),
            Token(token_type=TokenType.TOKEN_IDENTIFIER, token_value="my_func", token_line=7),
            Token(token_type=TokenType.TOKEN_LEFT_PAREN, token_value=None, token_line=7),
            Token(token_type=TokenType.TOKEN_IDENTIFIER, token_value="my_var", token_line=7),
            Token(token_type=TokenType.TOKEN_RIGHT_PAREN, token_value=None, token_line=7),
            Token(token_type=TokenType.TOKEN_SEMICOLON, token_value=None, token_line=7),
            Token(token_type=TokenType.TOKEN_RETURN, token_value=None, token_line=8),
            Token(token_type=TokenType.TOKEN_INT_LIT, token_value=2, token_line=8),
            Token(token_type=TokenType.TOKEN_SEMICOLON, token_value=None, token_line=8),
            Token(token_type=TokenType.TOKEN_RIGHT_BRACE, token_value=None, token_line=9),
        ])
        assert Lexer(file=read_file("examples/example2.c")).get_tokens() == expected_deque

    def test_tokenize_example3(self):
        expected_deque = deque([
            Token(token_type=TokenType.TOKEN_INT, token_value=None, token_line=1),
            Token(token_type=TokenType.TOKEN_IDENTIFIER, token_value="main", token_line=1),
            Token(token_type=TokenType.TOKEN_LEFT_PAREN, token_value=None, token_line=1),
            Token(token_type=TokenType.TOKEN_RIGHT_PAREN, token_value=None, token_line=1),
            Token(token_type=TokenType.TOKEN_LEFT_BRACE, token_value=None, token_line=1),
            Token(token_type=TokenType.TOKEN_RETURN, token_value=None, token_line=2),
            Token(token_type=TokenType.TOKEN_LOG_NEG, token_value=None, token_line=2),
            Token(token_type=TokenType.TOKEN_COMPLEMENT, token_value=None, token_line=2),
            Token(token_type=TokenType.TOKEN_NEG, token_value=None, token_line=2),
            Token(token_type=TokenType.TOKEN_INT_LIT, token_value=2, token_line=2),
            Token(token_type=TokenType.TOKEN_SEMICOLON, token_value=None, token_line=2),
            Token(token_type=TokenType.TOKEN_RIGHT_BRACE, token_value=None, token_line=3),
        ])
        assert Lexer(file=read_file("examples/example3.c")).get_tokens() == expected_deque

if __name__ == "__main__":
    unittest.main()
