//
// Created by Aditya Ved on 01/10/22.
//

#include <stdio.h>
#include <stdlib.h>
void delete(int * ptr_to_queue , int * ptr_to_front ,int * ptr_to_rear, int MAX );
void insert(int * ptr_to_queue , int * ptr_to_front , int * ptr_to_rear , int MAX , int element_to_be_inserted);
void display(int * ptr_to_queue, int * ptr_to_front ,  int * ptr_to_rear);

int main()
{
    // array implementation of simple queue
    int front=-1,rear=-1;
    int max = 10;
    int queue1 [max];
    insert(queue1,&front,&rear,max,15);
    insert(queue1,&front,&rear,max,25);
    insert(queue1,&front,&rear,max,35);
    insert(queue1,&front,&rear,max,45);
    display(queue1,&front,&rear);
    delete(queue1,&front,&rear,max);
    display(queue1,&front,&rear);

    printf("\n");
    return 0;
}

void insert(int * ptr_to_queue , int * ptr_to_front , int * ptr_to_rear , int MAX , int element_to_be_inserted)
{
    // MAX is the size of the array
    if(*(ptr_to_front) == -1 && *(ptr_to_rear) == -1)
    {
        *(ptr_to_front) = 0;
        *(ptr_to_rear) = 0;
    }

    else if(*(ptr_to_rear) == MAX-1)
    {
        printf("Overflow condition\n");
        return;
    }

    else
    {
        *(ptr_to_rear) +=1;
    }

    ptr_to_queue[*(ptr_to_rear)] = element_to_be_inserted;

}

void delete(int * ptr_to_queue , int * ptr_to_front ,int * ptr_to_rear, int MAX )
{
    int element_to_be_deleted;

    if(*(ptr_to_front) == -1 || *(ptr_to_front) > *(ptr_to_rear))
    {
        printf("Underflow condition\n");
        return;
    }

    else
    {
        element_to_be_deleted = ptr_to_queue[*(ptr_to_front)];
        printf("Deleting this element : %d\n",element_to_be_deleted);
        ptr_to_queue[*(ptr_to_front)] = 0;
        *(ptr_to_front) +=1;
    }

}

void display(int * ptr_to_queue, int * ptr_to_front ,  int * ptr_to_rear)
{
    if(*(ptr_to_front) == -1 || *(ptr_to_front) > *(ptr_to_rear))
    {
        printf("Queue is empty\n");
        return;
    }

    for(int  i = *(ptr_to_front) ; i <= *(ptr_to_rear) ; i++)
    {
        printf("%d ,\t",ptr_to_queue[i]);
    }
    printf("\n");
}
