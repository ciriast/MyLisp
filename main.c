#include <stdio.h>
#include <stdlib.h>

static char userInput[2048];

int main(int argc, char** argv) {
    puts("Lisp version 0.1");
    puts("Press Ctrl+c to Exit");
    
    while(1) {
        fputs("lispy> ", stdout);

        fgets(userInput, 2048, stdin);

        printf("No you are a %s", userInput);

    }
    // I learned that the EXIT_SUCCESS statement is declared in stdlib
    return EXIT_SUCCESS;
}
