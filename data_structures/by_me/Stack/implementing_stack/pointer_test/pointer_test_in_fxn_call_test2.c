//
// Created by Aditya Ved on 25/08/22.
//



#include <stdio.h>
#include <stdlib.h>

void fxn(int *);

int main()
{
    int *ptr1 = (int *) malloc(2*sizeof (int ));
    *(ptr1) = 15;
    *(ptr1+1) = 25;
    fxn(ptr1);
    free(ptr1);

    printf("\n");
    return 0;
}

void fxn(int *ptr1_in_fxn)
{

    free(ptr1_in_fxn);

}