//
// Created by Aditya Ved on 19/08/22.
//
#include <stdio.h>
#include "main.c"



int delete_given_element(struct Node *ptr_to_1st_node,int number_of_nodes)
{
    printf("Enter the element that you want to delete\n");
    int remove_me;
    scanf("%d",&remove_me);
    printf("Removing the 1st occurrence of %d in Linked List\n",remove_me);

    struct Node *ptr_next;
    struct Node *ptr_to_last_node;
    ptr_next = ptr_to_1st_node;
    int flag1 = 0;

    struct Node *ptr_to_be_deleted;

    int i;
    //0 to 3
    for(i=0;i<number_of_nodes-1;i++)
    {
        ptr_next = ptr_next->ptr_forward;
    }

    ptr_to_last_node = ptr_next;

    ptr_next = ptr_to_1st_node;
    while(ptr_next != NULL)
    {
        if(ptr_next->data == remove_me)
        {
            flag1 = 1;
            break;
        }

        ptr_next = ptr_next->ptr_forward;
    }

    if(flag1 == 0)
    {
        printf("Sorry the element doesnt exist in the linked list\n");
        return number_of_nodes;
    }

    else
    {
        // change the forward pointer of previous node
        // change the backward pointer of then next node
        // free that node which is to be deleted
        ptr_to_be_deleted = ptr_next;

        if (ptr_to_be_deleted == ptr_to_1st_node)
        {
            ptr_to_1st_node->ptr_forward->ptr_backward = NULL;
            metadata1.linked_list_ptr = ptr_to_1st_node->ptr_forward;
            //doubt why the below line is excluded
            //free(ptr_to_be_deleted);
            // doubt solved :
            // since we have manually created the 1st node without using malloc, thus we dont have the need to free it
            // but now once we remove the 1st node then 2nd node becomes the 1st node
            // this 2nd node was created using malloc
            // now this time memory needs to be freed , hahahaha.....

            // so this problem is now solved by me
            // i have allocated the first node also using malloc now without manually creating a
            // structure and then creating a pointer to that structure

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


        number_of_nodes = number_of_nodes -1;
        return number_of_nodes;
    }
}