//
// Created by Aditya Ved on 01/10/22.
//

#include <stdio.h>
#include <stdlib.h>
void insert(int * ptr_to_front, int * ptr_to_rear, int max, int * ptr_to_queue , int data);
void delete(int * ptr_to_front, int * ptr_to_rear, int max, int * ptr_to_queue);
void display(int * ptr_to_front, int * ptr_to_rear, int max, int * ptr_to_queue);

int main()
{
    int max = 10;
    int circular_queue1 [max];
    int front  = -1, rear = -1;
    insert(&front,&rear,max,circular_queue1,15);
    insert(&front,&rear,max,circular_queue1,25);
    insert(&front,&rear,max,circular_queue1,35);
    insert(&front,&rear,max,circular_queue1,45);
    display(&front,&rear,max,circular_queue1);
    delete(&front,&rear,max,circular_queue1);
    display(&front,&rear,max,circular_queue1);

    printf("\n");
    return 0;
}


void insert(int * ptr_to_front, int * ptr_to_rear, int max, int * ptr_to_queue , int data)
{
    if( (*(ptr_to_front) == 0 && *(ptr_to_rear) == max-1)  || (*(ptr_to_rear) == *(ptr_to_front) - 1))
    {
        printf("Overflow condition\n");
        return;
    }

    if(*(ptr_to_front) == -1 || *(ptr_to_rear) == -1)
    {
        // the queue is empty
        ptr_to_queue[0] = data;
        *(ptr_to_front) = 0;
        *(ptr_to_rear) = 0;
        return;
    }

    if ( *(ptr_to_rear) == max-1 )
    {
        // if rear = max -1 but front != 0 , thus the new element is added to the queue at the
        // 0th element of the array
        *(ptr_to_rear) = 0;
        ptr_to_queue[*(ptr_to_rear)] = data;
        return;
    }

    *(ptr_to_rear) +=1;
    ptr_to_queue[*(ptr_to_rear)] = data;

}

void delete(int * ptr_to_front, int * ptr_to_rear, int max, int * ptr_to_queue)
{
    if(*(ptr_to_front) == -1 || *(ptr_to_rear) == -1)
    {
        printf("Underflow condition, the queue is empty\n");
        return;
    }

    if(*(ptr_to_front) == *(ptr_to_rear))
    {
        ptr_to_queue[*(ptr_to_front)] = 0;
        *(ptr_to_front) = -1;
        *(ptr_to_rear) = -1;
        return;
    }

    if(*(ptr_to_front) == max-1)
    {
        ptr_to_queue[*(ptr_to_front)] = 0;
        *(ptr_to_front) = 0;
        return;
    }

    ptr_to_queue[*(ptr_to_front)] = 0;
    *(ptr_to_front) +=1;


}

void display(int * ptr_to_front, int * ptr_to_rear, int max, int * ptr_to_queue)
{
    if (*(ptr_to_front) > *(ptr_to_rear))
    {
        int i;
        for(i = *(ptr_to_front); i <= max-1; i++)
        {
            printf("%d\t",ptr_to_queue[i]);
        }

        for(i=0;i<=*(ptr_to_rear);i++)
        {
            printf("%d\t",ptr_to_queue[i]);
        }

        printf("\n");

    }

    else
    {
        int i;
        for(i= *(ptr_to_front) ; i<= *(ptr_to_rear) ; i++)
        {
            printf("%d\t",ptr_to_queue[i]);
        }

        printf("\n");
    }
}