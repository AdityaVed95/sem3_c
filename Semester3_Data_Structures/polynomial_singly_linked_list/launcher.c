//
// Created by Aditya Ved on 22/09/22.
//
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int power;
    double coefficient;
    struct Node * ptr_next;

};

int main()
{
    struct Node * ptr1;
    ptr1 = NULL;
    printf("%d\n",ptr1->power);
    printf("\n");
    return 0;
}