//
// Created by Aditya Ved on 02/09/22.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a1[] = {10,20,30,40,50};
    int *ptr1 = a1;

    int i;

    for(i=0;i<5;i++)
    {
        printf("%d\n",ptr1[i]);
    }

    //
    // *(ptr1+i) = ptr1[i]

    printf("\n");
    return 0;
}