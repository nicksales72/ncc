import re
from collections import deque
from ncc.helpers.helpers import read_file
from ncc.lexer.token import Token, TokenType

class Lexer: 
    def __init__(self, file:str, tokens:deque[Token]=None):
        self.file = file
        self.tokens = self._tokenize_file()

    def _tokenize_file(self) -> deque[Token]:
        last_token = ""
        tokenize_queue = deque([])

        symbol_token_types = {
            '{': TokenType.TOKEN_LEFT_BRACE, 
            '}': TokenType.TOKEN_RIGHT_BRACE,
            '(': TokenType.TOKEN_LEFT_PAREN, 
            ')': TokenType.TOKEN_RIGHT_PAREN,
            ';': TokenType.TOKEN_SEMICOLON, 
            '-': TokenType.TOKEN_NEG,
            '!': TokenType.TOKEN_LOG_NEG, 
            '~': TokenType.TOKEN_COMPLEMENT,
        }

        keyword_token_types = {
            "int": TokenType.TOKEN_INT, 
            "return": TokenType.TOKEN_RETURN, 
        }

        line_num = 1 
        for character in self.file:
            if character in symbol_token_types or character in {'\n', ' '}:
                if character == '\n': line_num += 1

                if last_token in keyword_token_types: 
                    tokenize_queue.append(Token(token_type=keyword_token_types[last_token], token_value=None, token_line=line_num))
                elif re.fullmatch(r"[a-zA-Z]\w*", last_token):
                    tokenize_queue.append(Token(token_type=TokenType.TOKEN_IDENTIFIER, token_value=last_token, token_line=line_num))
                elif re.fullmatch(r"[0-9]+", last_token):
                    tokenize_queue.append(Token(token_type=TokenType.TOKEN_INT_LIT, token_value=int(last_token), token_line=line_num))

                if character in symbol_token_types:
                    tokenize_queue.append(Token(token_type=symbol_token_types[character], token_value=None, token_line=line_num))

                last_token = ""
                continue
            elif character.isalnum() or character in {'_'}:
                last_token += character
            else: 
                raise RuntimeError(f"Unexpected character '{character}' on line {line_num}")
        
        return tokenize_queue
                    
    def get_tokens(self) -> deque[Token]:
        return self.tokens