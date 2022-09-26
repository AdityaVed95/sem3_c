//
// Created by Aditya Ved on 19/08/22.
//

#include <stdio.h>
#include "main.c"


int delete_given_node(struct Node *ptr_to_1st_node,int number_of_nodes)
{
    printf("Enter the node number (1 based numbering) that needs to be deleted from the linked list\n");
    int node_to_be_deleted;
    scanf("%d",&node_to_be_deleted);

    // 45 in 15,25,35,45,55 is to be deleted
    // node_to_be_deleted = 4

    if (node_to_be_deleted>number_of_nodes || node_to_be_deleted<1)
    {
        printf("Sorry this many number of nodes does not exist, please try again later\n");
        return number_of_nodes;
    }

    else
    {
        int i;
        struct Node *ptr_to_be_deleted;
        struct Node *ptr_next;
        ptr_next = ptr_to_1st_node;


        for(i=0;i<node_to_be_deleted-1;i++)
        {
            ptr_next = ptr_next->ptr_forward;
        }

        // i=0 : ptr_next = 58b0
        // i=1 : ptr_next = 4080
        // i=2 : ptr_next = 9782
        // i=3 : ptr_next = 7467

        ptr_to_be_deleted = ptr_next;

        printf("Found data : %d at %dth node , deleting node now\n",ptr_to_be_deleted->data,node_to_be_deleted);


        struct Node *ptr_to_last_node;
        ptr_next = ptr_to_1st_node;
        for(i=0;i<number_of_nodes-1;i++)
        {
            ptr_next = ptr_next->ptr_forward;
        }

        ptr_to_last_node = ptr_next;


        if (ptr_to_be_deleted == ptr_to_1st_node)
        {
            ptr_to_1st_node->ptr_forward->ptr_backward = NULL;
            metadata1.linked_list_ptr = ptr_to_1st_node->ptr_forward;
            //free(ptr_to_be_deleted);

        }

        else if (ptr_to_be_deleted == ptr_to_last_node)
        {
            ptr_to_be_deleted->ptr_backward->ptr_forward = NULL;
            //free(ptr_to_be_deleted);

        }

        else
        {
            ptr_to_be_deleted->ptr_backward->ptr_forward = ptr_to_be_deleted->ptr_forward;
            ptr_to_be_deleted->ptr_forward->ptr_backward = ptr_to_be_deleted->ptr_backward;
            free(ptr_to_be_deleted);
        }


        number_of_nodes = number_of_nodes-1;
        return number_of_nodes;
    }



}