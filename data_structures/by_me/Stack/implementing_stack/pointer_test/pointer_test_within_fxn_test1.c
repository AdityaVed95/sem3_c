//
// Created by Aditya Ved on 25/08/22.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr1 = (int *) malloc(2*sizeof (int ));
    *(ptr1) = 15;
    *(ptr1+1) = 25;

    int *ptr2;
    ptr2 = ptr1;
    free(ptr2);

    free(ptr1);
    printf("\n");
    return 0;
}

// it is not necessary that the same pointer that is pointing to the block of memory (using malloc)
// has to be free
// another pointer which is pointing to the same block of memory can also free that block of memory
// thus in the above example ptr2 actually free the memory block that was pointed by both ptr1 and ptr2

