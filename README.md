# ncc 
This will be a fully functioning C compiler. The current goal is to successfully compile the code in `examples/example.c`, which is just the following simple C program: 
```c
int main() {
    return 2;
}
```
Right now the tokenizer is *mostly* working (besides some error handling), which can be seen by running the following:
```shell
make 
./ncc examples/example.c
int main() {
    return 2;
}

TOKEN_INT
TOKEN_IDENTIFIER
TOKEN_LEFT_PAREN
TOKEN_RIGHT_PAREN
TOKEN_LEFT_BRACE
TOKEN_RETURN
TOKEN_INT_LIT
TOKEN_SEMICOLON
TOKEN_RIGHT_BRACE
```
