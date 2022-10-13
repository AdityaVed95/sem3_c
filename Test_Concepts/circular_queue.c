//
// Created by Aditya Ved on 10/10/22.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int MAX = 5;

    int circular_queue [MAX];

    int front;
    int rear;

    if (front == -1 && rear == -1)
    {
        printf("Queue Underflow\n");
    }

    else if(front<=rear)
    {
        for(int i = front ;i<=rear ; i++)
        {
            printf("%d\n",circular_queue[i]);
        }

    }

    else if (front > rear)
    {
        for(int i=front ; i <= MAX-1; i++)
        {
            printf("%d\n",circular_queue[i]);
        }

        for(int i=0 ; i<=rear;i++)
        {
            printf("%d\n",circular_queue[i]);
        }
    }



    printf("\n");
    return 0;
}