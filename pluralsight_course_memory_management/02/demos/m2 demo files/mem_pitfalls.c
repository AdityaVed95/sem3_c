/**
 * This file shows some common pitfalls with dynamic memory management. Included:
 * 1. Dangling pointers
 * 2. Double frees
 * 3. Forgetting to use "sizeof"
 * 4. Not checking whether or not a NULL pointer is returned from malloc, calloc or realloc
 */

#include <stdlib.h>
#include <stdio.h>

typedef struct Person {
    int age;
    char* name;
} Person;

int main(int argc, char* argv[]) {

    // #1. Dangling pointers
    Person *person1 = (Person*)malloc(sizeof(Person));

    person1 = NULL;

    // #2. Double frees
    Person *person2 = (Person*)malloc(sizeof(Person));

    free(person2);
    free(person2);
    
    // #3. Forgetting to use "sizeof"
    int *int_ptr = (int*)malloc(2);
    free(int_ptr);

    // #4. NULL pointer returned from malloc, calloc or realloc
    char *name = (char*)malloc(100000000);
    *name = 'A'; // We could be dereferencing an invalid pointer here!


    return 0;
}

