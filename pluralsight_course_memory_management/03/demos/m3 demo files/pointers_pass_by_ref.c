#include <stdio.h>
#include <stdlib.h>

/**
 * Function declarations
 **/
void print_int_by_reference(int* number_ptr);
void print_int_by_value(int number);

void malloc_int_dangerous(int* number_ptr);
void malloc_int_safe(int** number_ptr);

int main(int argc, char* argv[]) {
    // Give example of passing an int via a pointer instead of by value
    int my_number = 10;

    print_int_by_value(my_number);

    print_int_by_reference(&my_number);

    printf("The addresses printed above should be different! ^^\n\n\n");


    int* number_ptr = &my_number;

    printf("'number_ptr' address before malloc: %p\n", number_ptr);

    // 1. Create function that takes in a pointer to an int, attempts to malloc memory for it and return the pointer -
    // this will not work (memory leak will occur... because the pointer passed in points to memory on the stack)
    malloc_int_dangerous(number_ptr);

    printf("Original 'number_ptr' address after dangerous malloc: %p\n", number_ptr);
    printf("The above address for 'number_ptr' does not change!\n");

    // 2. Create a function that takes in a double pointer to an int and malloc memory to the dereferenced double pointer
    malloc_int_safe(&number_ptr); // Pass the address of the 'number_ptr' pointer

    printf("'number_ptr' address after safe malloc: %p\n", number_ptr);

    free(number_ptr);

    number_ptr = NULL;

    return 0;
}

/**
 * Function definitions
 **/

// Takes in an integer and prints it to the console 
void print_int_by_reference(int* number_ptr) {
    printf("Printing Int =>> Address: %p | Value: %d\n", number_ptr, *number_ptr);
}

// The 'number' argument below is copied into the function scope.
void print_int_by_value(int number) {
    printf("Printing Int =>> Address: %p | Value: %d\n", &number, number);
}

// This will not work and will cause a memory leak because 'number_ptr' is passed by value.
void malloc_int_dangerous(int* number_ptr) {
    number_ptr = (int*)malloc(sizeof(int));
    printf("[malloc_int_dangerous] => 'number_ptr' address after dangerous malloc: %p\n", number_ptr);
    printf("[malloc_int_dangerous] => ^^ That address space marks a memory-leaked block!\n\n");
    // 'number_ptr' now goes out of scope and you have a memory leak...

    // here the address that the number_ptr stored is now changed and
    // points to an allocated block of memory
    // number_ptr was not freed : thus this block remains as it is with
    // no pointer pointing to it
    // when the control of the program goes back from this function to the main_before_modularsing function then
    // the value of the number_ptr will be the same as it was in the main_before_modularsing fxn because for this
    // function : the number_ptr is a local variable and changing its value will have effect only
    // within this function and will not reflect in the main_before_modularsing function



}

// This will work nicely and will not cause a memory leak as long as the caller of this function frees the memory.
void malloc_int_safe(int** number_ptr2) {
    *number_ptr2 = (int*)malloc(sizeof(int));
    // *number_ptr2 is equal to number_ptr is equal to the address of my_number stored in number_ptr
    // on changing the address of the my_number stored in number_ptr , the actual address of my_number
    // wont change
    // since my_number is not a block of memory , it is just a number
    // thus a pointer pointing to this number (number_ptr) need not be freed
    // thus even if we change the value of number_ptr, it wont cause any memory leak
    // that is there will not be any block of memory that is not pointed by a pointer


}
