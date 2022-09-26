#include <stdio.h>
#include <string.h>

/**
 * Types
 * */

typedef struct Person {
    char* name;
    int age;
    void (*greeting)();
} Person;

/**
 * Function declarations
 **/
void say_english_greeting();
void say_spanish_greeting();

int main(int argc, char *argv[]) {

    // char *argv[] is an array of pointer to characters
    // check note below

    // 1. Function pointer declaration
    void (*greeting1)();
    // above void is the return type of the function to which the greeting pointer is going to point to


    printf("Value of argc is the number of command line arguments is : %d\n",argc);

    int i ;

    for (i=0;i<argc;i++)
    {
        printf("for %d th element : %c\n",i,*argv[i]);
    }

    // 2. Function pointer initialization
    if (argc > 1) {
        greeting1 = !strcmp("spanish", argv[1]) ? &say_spanish_greeting : &say_english_greeting;
    } else {
        printf("Please pass a 'greeting' argument!\n");
        return 1;
    }

    // 3. Function pointers inside of structures
    Person fred = { "Fred", 27, greeting1 };

    // 4. Determining function calls at runtime
    fred.greeting();

    return 0;
}


/**
 * Function definitions
 **/
void say_english_greeting() {
    printf("Hello!\n");
}

void say_spanish_greeting() {
    printf("Hola!\n");
}

//  https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/

// on the terminal :

//  gcc -o function_pointers function_pointers.c
//  ./function_pointers Aditya Ved ===> Hello
//  ./function_pointers spanish  ===> Hola


