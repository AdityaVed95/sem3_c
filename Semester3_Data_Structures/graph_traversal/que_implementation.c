//
// Created by Aditya Ved on 03/12/22.
//


#include <stdio.h>
#include <stdlib.h>
void delete(int * ptr_to_queue , int * ptr_to_front ,int * ptr_to_rear );
void insert(int * ptr_to_queue , int * ptr_to_front , int * ptr_to_rear , int MAX , int element_to_be_inserted);
void display(int * ptr_to_queue, int * ptr_to_front ,  int * ptr_to_rear);
int is_que_empty(int * ptr_to_front ,  int * ptr_to_rear);

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

void delete(int * ptr_to_queue , int * ptr_to_front ,int * ptr_to_rear)
{
    int element_to_be_deleted;

    if(*(ptr_to_front) == -1 )
    {
        printf("Underflow condition\n");
        return;
    }

    element_to_be_deleted = ptr_to_queue[*(ptr_to_front)];
    printf("Dequeueing this vertex : %d\n",element_to_be_deleted);
    ptr_to_queue[*(ptr_to_front)] = 0;

    if(*(ptr_to_front) == *(ptr_to_rear))
    {
        *(ptr_to_front) = -1;
        *(ptr_to_rear) = -1;
    }
    else
    {
        *(ptr_to_front) +=1;
    }

}

void display(int * ptr_to_queue, int * ptr_to_front ,  int * ptr_to_rear)
{
    if(*(ptr_to_front) == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    for(int  i = *(ptr_to_front) ; i <= *(ptr_to_rear) ; i++)
    {
        if(i == *(ptr_to_rear))
        {
            printf("%d",ptr_to_queue[i]);
        }
        else
        {
            printf("%d \t,\t",ptr_to_queue[i]);
        }

    }
    printf("\n");
}


int is_que_empty(int * ptr_to_front ,  int * ptr_to_rear)
{
    if(*(ptr_to_front) == -1 && *(ptr_to_rear) == -1)
    {
        return 1;
    }

    return 0;
}