#include <stdio.h>
#include <stdlib.h>

typedef struct {
    
} Lox;

int main(int argc, char **argv) {
    if (argc > 2) {
        printf("Usage: ./jlox [script]\n");
        exit(64);
    } else if (argc == 2) {
        printf("runFile thing");
    } else {
        printf("runPrompt thing");
    }


    return 0;
}
