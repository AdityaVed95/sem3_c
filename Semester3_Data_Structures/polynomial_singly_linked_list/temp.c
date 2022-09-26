//
// Created by Aditya Ved on 22/09/22.
//

struct Node
{
    int data;
    struct Node * ptr_next;
};

#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct Node * node1 = (struct Node *) malloc(sizeof (struct Node));
    node1->data = 16;
    node1->ptr_next= NULL;

    struct Node * node2 = (struct Node *) malloc(sizeof (struct Node));
    node2->data = 17;
    node2->ptr_next = NULL;

    node1->ptr_next = node2;

    printf("%d\n",node1->data);

    printf("\n");
    return 0;
}
