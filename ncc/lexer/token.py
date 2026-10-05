from enum import Enum, auto
from dataclasses import dataclass

class TokenType(Enum):
    TOKEN_LEFT_BRACE = auto()      # {
    TOKEN_RIGHT_BRACE = auto()     # }
    TOKEN_LEFT_PAREN = auto()      # (
    TOKEN_RIGHT_PAREN = auto()     # )
    TOKEN_SEMICOLON  = auto()      # ;
                           
    TOKEN_INT = auto()             # int
    TOKEN_RETURN = auto()          # return
    TOKEN_IDENTIFIER = auto()      # [a-zA-Z]\w*
    TOKEN_INT_LIT = auto()         # [0-9]+

    TOKEN_NEG = auto()             # - 
    TOKEN_COMPLEMENT = auto()      # ~
    TOKEN_LOG_NEG = auto()         # !
                           
    TOKEN_EOF = auto()

@dataclass
class Token: 
    token_type: TokenType
    token_value: int | str | None
    token_line: int

    def __eq__(self, other:Token) -> bool:
        return self.token_type == other.token_type and self.token_value == other.token_value and self.token_line == other.token_line

    def __repr__(self) -> str: 
        return f"Token Type: {token_to_string(self.token_type)}, Token Value: {self.token_value}, Token Line: {self.token_line}"
 
def token_to_string(t:TokenType) -> str:
    match t: 
        case TokenType.TOKEN_LEFT_BRACE: return "TOKEN_LEFT_BRACE";
        case TokenType.TOKEN_RIGHT_BRACE: return "TOKEN_RIGHT_BRACE";
        case TokenType.TOKEN_LEFT_PAREN: return "TOKEN_LEFT_PAREN";
        case TokenType.TOKEN_RIGHT_PAREN: return "TOKEN_RIGHT_PAREN";
        case TokenType.TOKEN_SEMICOLON: return "TOKEN_SEMICOLON";
        case TokenType.TOKEN_INT: return "TOKEN_INT";
        case TokenType.TOKEN_RETURN: return "TOKEN_RETURN";
        case TokenType.TOKEN_IDENTIFIER: return "TOKEN_IDENTIFIER";
        case TokenType.TOKEN_INT_LIT: return "TOKEN_INT_LIT";
        case TokenType.TOKEN_NEG: return "TOKEN_NEG";
        case TokenType.TOKEN_COMPLEMENT: return "TOKEN_COMPLEMENT";
        case TokenType.TOKEN_LOG_NEG: return "TOKEN_LOG_NEG";
        case TokenType.TOKEN_EOF: return "TOKEN_EOF";
    return "?"