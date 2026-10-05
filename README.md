# ncc 
This compiler can currently compile the following very basic C program in `examples/example.c` (directly to assembly):
```c
int main() {
    return 2;
}
```
This can be seen by running the following with `DEBUG=1`:
```shell
python3 -m ncc.main examples/example.c -o example DEBUG=1
```
```shell
-----PROGRAM-----
int main() {
    return 2;
}

-----TOKENS-----
Token Type: TOKEN_INT, Token Value: None, Token Line: 1
Token Type: TOKEN_IDENTIFIER, Token Value: main, Token Line: 1
Token Type: TOKEN_LEFT_PAREN, Token Value: None, Token Line: 1
Token Type: TOKEN_RIGHT_PAREN, Token Value: None, Token Line: 1
Token Type: TOKEN_LEFT_BRACE, Token Value: None, Token Line: 1
Token Type: TOKEN_RETURN, Token Value: None, Token Line: 2
Token Type: TOKEN_INT_LIT, Token Value: 2, Token Line: 2
Token Type: TOKEN_SEMICOLON, Token Value: None, Token Line: 2
Token Type: TOKEN_RIGHT_BRACE, Token Value: None, Token Line: 3

-----TOKENS AFTER AST CREATION (SHOULD BE EMPTY)-----

-----AST-----
Program(Function(Name: main, Statement(Exp(Const(2)))))

-----ASSEMBLY-----
.global main
main:
	mov $2, %rax
	ret
```
```shell
./example
echo $?
2
```
