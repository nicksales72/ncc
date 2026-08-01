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
./ncc examples/example.c
```
Which outputs:
```shell
int main() {
    return 2;
}

TOKEN_INT, (none)
TOKEN_IDENTIFIER, main
TOKEN_LEFT_PAREN, (none)
TOKEN_RIGHT_PAREN, (none)
TOKEN_LEFT_BRACE, (none)
TOKEN_RETURN, (none)
TOKEN_INT_LIT, 2
TOKEN_SEMICOLON, (none)
TOKEN_RIGHT_BRACE, (none)

AST: Program(Function(Name: main, Statement(Exp(2))))
```
