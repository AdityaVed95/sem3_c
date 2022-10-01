//
// Created by Aditya Ved on 01/10/22.
//

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node * ptr_next;
};


void create_queue(int , struct Node ** , struct Node ** );
void enqueue (int data, struct Node ** ptr_to_ptr_to_front , struct Node ** ptr_to_ptr_to_rear);
void dequeue (struct Node ** ptr_to_ptr_to_front , struct Node ** ptr_to_ptr_to_rear);
void display (struct Node ** ptr_to_ptr_to_front);

int main()
{
    printf("For the creation of queue, enter data :\n");
    int data1;
    scanf("%d",&data1);
    struct Node * ptr_front = NULL;
    struct Node * ptr_rear = NULL;

    create_queue(data1,&ptr_front,&ptr_rear);
    enqueue(15,&ptr_front,&ptr_rear);
    enqueue(25,&ptr_front,&ptr_rear);
    enqueue(35,&ptr_front,&ptr_rear);
    enqueue(45,&ptr_front,&ptr_rear);
    display(&ptr_front);
    dequeue(&ptr_front,&ptr_rear);
    display(&ptr_front);

    printf("\n");
    return 0;
}

void create_queue(int data, struct Node ** ptr_to_ptr_to_front , struct Node ** ptr_to_ptr_to_rear)
{
    struct Node * ptr1 = (struct Node *) malloc(sizeof (struct Node));
    ptr1->data = data;
    ptr1->ptr_next = NULL;
    *(ptr_to_ptr_to_front) = ptr1;
    *(ptr_to_ptr_to_rear) = ptr1;

}

void enqueue (int data, struct Node ** ptr_to_ptr_to_front , struct Node ** ptr_to_ptr_to_rear)
{
    if(*(ptr_to_ptr_to_front) == NULL || *(ptr_to_ptr_to_rear) == NULL)
    {
        // no elements present in the queue
        struct Node * ptr = (struct Node *) malloc(sizeof (struct Node));
        ptr->data = data;
        ptr->ptr_next =NULL;
        *(ptr_to_ptr_to_rear) = ptr;
        *(ptr_to_ptr_to_front) = ptr;
        return;
    }

    struct Node * ptr = (struct Node *) malloc(sizeof (struct Node));
    ptr->data = data;
    ptr->ptr_next = NULL;

    (*(ptr_to_ptr_to_rear))->ptr_next = ptr;
    *(ptr_to_ptr_to_rear) = ptr;


}

void dequeue (struct Node ** ptr_to_ptr_to_front , struct Node ** ptr_to_ptr_to_rear)
{
    if(*(ptr_to_ptr_to_front) == NULL || *(ptr_to_ptr_to_rear) == NULL)
    {
        printf("The linked list is empty, underflow condition\n");
        return;
    }

    struct Node * temp = *(ptr_to_ptr_to_front);
    *(ptr_to_ptr_to_front) = (*(ptr_to_ptr_to_front))->ptr_next;
    printf("element with value %d has been deleted\n",temp->data);
    free(temp);

}

void display (struct Node ** ptr_to_ptr_to_front)
{
    struct Node * ptr_iterator = NULL;
    ptr_iterator = *(ptr_to_ptr_to_front);
    while (ptr_iterator!=NULL)
    {
        printf("%d\t",ptr_iterator->data);
        ptr_iterator = ptr_iterator->ptr_next;
    }

    printf("\n");

}
