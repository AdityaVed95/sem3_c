#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]) {
    int my_number = 10;

    // Declare a pointer
    int *my_ptr;

    // Getting the address of my_number using the "address operator - &"
    printf("Address of 'my_number': %p\n", &my_number); 

    // Initialize a pointer using the "address operator - &"
    my_ptr = &my_number;


    // Initialize a pointer using malloc
    char *name = (char*)malloc(8 * sizeof(char));

    // Dereference a pointer to read a value at its address
    printf("Value of 'my_number': %d\n", *my_ptr);

    int my_copied_number = *my_ptr;

    printf("Value of 'my_copied_number': %d\n", my_copied_number);

    // Dereference a pointer to assign a value to its address
    *my_ptr = 20;

    printf("Value of 'my_number' after assigning a new value: %d\n", *my_ptr);


    free(name);
    return 0;
}
