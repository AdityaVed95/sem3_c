//
// Created by Aditya Ved on 25/08/22.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr1 = (int *) malloc(2*sizeof (int ));
    *(ptr1) = 15;
    *(ptr1 + 1) = 25;

    ptr1 = (int *) realloc(ptr1,4*sizeof (int ));
    *(ptr1+2) = 35;
    *(ptr1+3) = 45;

    printf("values are:\n");
    printf("%d\n",*(ptr1));
    printf("%d\n",*(ptr1+1));
    printf("%d\n",*(ptr1+2));
    printf("%d\n",*(ptr1+3));

    printf("addresses are : \n");
    printf("%u\n",(ptr1));
    printf("%u\n",(ptr1+1));
    printf("%u\n",(ptr1+2));
    printf("%u\n",(ptr1+3));


    printf("\n");
    return 0;
}