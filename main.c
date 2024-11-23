#include <stdio.h>
#include <stdlib.h>
#include <editline/readline.h>
#include <editline/history.h>

int main(int argc, char** argv) {
    puts("Lisp version 0.1");
    puts("Press Ctrl+c to Exit");
    
    while(1) {

        char* userInput = readline("lispy> ");
        
        add_history(userInput);

        printf("No you are a %s\n", userInput);

        free(userInput);
    }
    // I learned that the EXIT_SUCCESS statement is declared in stdlib
    return EXIT_SUCCESS;
}
