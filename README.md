# ncc 
This will be a fully functioning C compiler. The current goal is to successfully compile the code in `examples/example.c`, which is just the following simple C program: 
```c
int main() {
    return 2;
}
```
Right now the tokenizer and the parser for the AST are *mostly* working (besides some error handling), which can be seen by running the following:
```shell
make 
./ncc examples/example.c -o example
```
Which outputs:
```shell
-----PROGRAM-----
int main() {
    return 2;
}

-----TOKENS-----
Token Type: TOKEN_INT, Token Value: (none)
Token Type: TOKEN_IDENTIFIER, Token Value: main
Token Type: TOKEN_LEFT_PAREN, Token Value: (none)
Token Type: TOKEN_RIGHT_PAREN, Token Value: (none)
Token Type: TOKEN_LEFT_BRACE, Token Value: (none)
Token Type: TOKEN_RETURN, Token Value: (none)
Token Type: TOKEN_INT_LIT, Token Value: 2
Token Type: TOKEN_SEMICOLON, Token Value: (none)
Token Type: TOKEN_RIGHT_BRACE, Token Value: (none)

-----TOKENS AFTER AST CREATION (SHOULD BE EMPTY)-----

-----AST-----
Program(Function(Name: main, Statement(Exp(2))))
```
