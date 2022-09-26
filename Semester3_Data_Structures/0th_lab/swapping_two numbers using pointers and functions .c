//
// Created by Aditya Ved on 18/08/22.
//
#include <stdio.h>

void swap(int *ptr1,int* ptr2)
{
    int temp;
    temp = *(ptr1);
    *ptr1 = *(ptr2);
    *(ptr2) = temp;

}


int main()
{
    printf("Hello World\n");

    int num1 = 15;
    int num2 = 25;

    int *ptr1 = &num1;
    int *ptr2 = &num2;

    swap(ptr1,ptr2);

    printf("Values after swapping are :\n 1 : %d\n",*ptr1);
    printf("2: %d\n",*ptr2);

    return 0;
}
