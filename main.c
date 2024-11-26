#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

/* If we are compiling on windows compile these functions */
#ifdef _WIN32 
#include <string.h>

static char buffer[2048];

/* Fake readline function */
char* readline(char* prompt) {
    fputs(prompt, stdout);
    fgets(buffer, 2048, stdin);

    char* cpy = malloc(strlen(buffer) + 1);

    strcpy(cpy, buffer);
    cpy[strlen(cpy)-1] = '\0';

    return cpy;
}

/* Fake add_history function */
void add_history(char* unused) {}

/* Otherwhise include the editline headers */
#else
#include <editline/readline.h>
#include <editline/history.h>
#endif

void intHandler(int a) {
    if (a == SIGINT)
        printf("Have a nice day! \n");

    exit(0);
 }

int main(int argc, char** argv) {
    puts("Lisp version 0.1-this is just me chilling");
    puts("Press Ctrl+c to Exit");
    
    signal(SIGINT, intHandler);

    while(1) {

        char* userInput = readline("lispyc> ");
        
        add_history(userInput);

        printf("Your prompt: %s\n", userInput);

        free(userInput);
    }
    
    // I learned that the EXIT_SUCCESS statement is declared in stdlib
    return EXIT_SUCCESS;
}
