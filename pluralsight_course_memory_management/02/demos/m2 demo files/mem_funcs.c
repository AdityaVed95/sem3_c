/**
 * This file endeavors to show working code examples of the following:
 * 1. Including the "stdlib.h" standard library header file
 * 2. Allocating memory using malloc
 * 3. Allocating and initializing memory using calloc
 * 4. Changing the size of an already allocated block of memory using realloc
 * 5. Freeing allocated memory
 */

// 1. Including <stdlib.h> ensures that we can use the core memory functions
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    int number_count = 4;

    // 2. Allocate a block of memory on the heap for four integer values using malloc
    int* my_numbers_ptr = (int*)malloc(number_count * sizeof(int));
    printf("Address of malloc'd block of memory: %p\n", my_numbers_ptr);

    for (int i = 0; i < number_count; i++) {
        *(my_numbers_ptr + i) = i;
        printf("Added value %d to address %p: \n ", i, my_numbers_ptr + i);
    }

    printf("\n\n");

    // 3. Allocate a block of memory on the heap and fill it with zeroes using calloc
    int* my_other_numbers_ptr =  (int*)calloc(number_count, sizeof(int));
    printf("Address of calloc'd block of memory: %p\n", my_other_numbers_ptr);

    for (int i = 0; i < number_count; i++) {
        printf("Value in calloc'd addresses should be 0: %d\n ", *(my_other_numbers_ptr + i));
        *(my_other_numbers_ptr + i) = i;
        printf("Added value %d to address %p: \n ", i, my_other_numbers_ptr + i);
    }

    printf("\n\n");

    // 4. Add/remove space to/from our malloc'd and calloc'd block of memories respectively
    my_numbers_ptr = (int*)realloc(my_numbers_ptr, (number_count + 2) * sizeof(int));

    printf("Show the values 0 through 5 for a total of 6 integers for this resized block of memory\n");

    for (int i = 0; i < number_count + 2; i++) {
        if (i == number_count || i == number_count + 1) {
            *(my_numbers_ptr + i) = i;
        }
        printf("Value in realloc'd block: %d\n ", *(my_numbers_ptr + i));
    }

    printf("\n\n");

    my_other_numbers_ptr = (int*)realloc(my_other_numbers_ptr, (number_count - 2) * sizeof(int)); 

    printf("The following code should only show the values 0 and 1 for this resized block of memory\n");

    for (int i = 0; i < number_count - 2; i++) {
        printf("Value in realloc'd block: %d\n ", *(my_other_numbers_ptr + i));

    }

    // 5. Free up our allocated memory in order to avoid memory leaks.
    free(my_numbers_ptr);
    free(my_other_numbers_ptr);
}
