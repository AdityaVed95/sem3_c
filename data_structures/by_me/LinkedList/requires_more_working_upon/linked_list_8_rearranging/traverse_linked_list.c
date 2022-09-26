//
// Created by Aditya Ved on 19/08/22.
//

#include <stdio.h>


void traverse_linked_list(struct Node *ptr_to_1st_node)
{


    struct Node *ptr_next;
    ptr_next = ptr_to_1st_node;
    int i=1;

    while (ptr_next != NULL)
    {
        printf("Value at the %d th node is : %d\n",i,ptr_next->data);
        ptr_next = ptr_next -> ptr_forward;
        i++;
    }

    // (ptr_to_1st_node->ptr_forward) gives us a pointer which is pointing to the
    // second node : say name of that pointer is ptr2
    // thus ptr2->data will give us the value of the variable "data" of the 2nd node

}
