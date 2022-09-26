//
// Created by Aditya Ved on 13/08/22.
//
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number = 10;

    int *number_ptr1,*number_ptr2;
    number_ptr1 = &number;
    number_ptr2 = &number;

    *number_ptr1 = 20;
    printf("value at *number_ptr2 is: %d \n",*number_ptr2);






    printf("\n");
    return 0;
}