//
// Created by Aditya Ved on 17/08/22.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dummy = 1;
    char response;

    while (dummy == 1)
    {

        printf("Enter y to add a node to the linked list\n");
        fflush(stdout);
        printf("Enter n to stop entering nodes to linked list\n");
        fflush(stdout);
        scanf("%c",&response);
        fflush(stdin);

        if (response == "n")
        {
            printf("Exiting input\n");
            break;
        }


    }


    printf("\n");
    return 0;
}