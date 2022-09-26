//
// Created by Aditya Ved on 19/09/22.
//

#include <stdio.h>
#include <stdlib.h>
#include "binary_operations_library.c"

int main()
{
    int num1[] = {0,0,1,0};
    int left_shifted_num1[4];
    left_shift(num1,left_shifted_num1,4);
    int i;
    for(i=0;i<4;i++)
    {
        printf("%d",left_shifted_num1[i]);
    }

    printf("\n");
    return 0;
}