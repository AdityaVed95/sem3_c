//
// Created by Aditya Ved on 17/08/22.
//
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int input;
    input = 1;

    while (input == 1)
    {
        printf("Enter 1 to add a node to the linked list\n");
        fflush(stdout);
        printf("Enter 2 to stop entering nodes to linked list\n");
        fflush(stdout);
        scanf("%d",&input);
        fflush(stdin);

    }

    printf("\n");
    return 0;
}