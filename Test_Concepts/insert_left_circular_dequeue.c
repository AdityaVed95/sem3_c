//
// Created by Aditya Ved on 10/10/22.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // insert left ka fxn :

    int MAX=5;
    int added_item;
    int circular_dequeue[MAX];

    int left,right;

    if((left == 0 && right == MAX - 1) || (left = right + 1))
    {
        printf("Queue is overflow\n");
        exit(-1);
    }

    else if(left == -1 && right == -1)
    {
        left = 0;
        right = 0;

    }

    else if(left == 0)
    {
        left = MAX - 1;
    }

    else
    {
        left = left - 1;

    }

    circular_dequeue[left] = added_item;

    printf("\n");
    return 0;
}


