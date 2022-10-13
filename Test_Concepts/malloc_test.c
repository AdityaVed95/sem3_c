//
// Created by Aditya Ved on 10/10/22.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int * ptr1 = (int *) malloc(10*sizeof(int ));
    int * ptr2 = (int *) calloc(10,sizeof (int));

    printf("%d",*(ptr1+8));

    printf("\n");
    return 0;
}