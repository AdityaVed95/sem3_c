//
// Created by Aditya Ved on 16/08/22.
//

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *ptr_forward;
    struct Node *ptr_backward;
};



void traverse_linked_list(struct Node *ptr_to_1st_node)
{
//    printf("Value of data at ptr (at 1st node) is : %d\n",ptr_to_1st_node->data);
//    printf("Value at the 2nd node is : %d\n",(ptr_to_1st_node->ptr_forward)->data);
//    printf("Value at the 3rd node %d\n",(((ptr_to_1st_node->ptr_forward)->ptr_forward)->data));

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


//    while(ptr_forward is not null)
//    {
//        keep on printing value at ptr using ->
//    }



}

int main()
{
    struct Node *linked_list_ptr;


    struct Node *ptr_to_previous_node;
    struct Node first_node;
    struct Node *ptr_to_1st_node;
//    struct Node node1;
//    struct Node *ptr_to_node1;
//    ptr_to_node1 = &node1;
//    ptr_to_node1->data = 15;
//    ptr_to_node1->ptr_forward = NULL;
//    ptr_to_node1->ptr_backward = NULL;
//
//    linked_list_ptr = &(node1);
//    // linked_list_ptr is a pointer pointing to the 1st node
//
//    struct Node node2;
//    struct Node *ptr_to_node2;
//    // we cant do this because we havent still updated  this : ptr_to_node1->ptr_forward    :: ptr_to_node2 = ptr_to_node1->ptr_forward;
//    ptr_to_node2 = &node2;
//    ptr_to_node2->data= 25;
//    ptr_to_node2->ptr_backward=&(node1);
//    ptr_to_node2->ptr_forward = NULL;
//
//    ptr_to_node1->ptr_forward = &(node2);
//
//
//    struct Node node3;
//    struct Node *ptr_to_node3;
//    ptr_to_node3 = &(node3);
//    ptr_to_node3->data = 35;
//    ptr_to_node3->ptr_forward = NULL;
//    ptr_to_node3->ptr_backward = &(node2);
//
//    ptr_to_node2->ptr_forward = &(node3);

    int choice_input,dummy=1;
    choice_input = 1;
    int data_input;
    int i=1;



    while (dummy == 1)
    {
        printf("Enter 1 to add a node to the linked list\n");
        fflush(stdout);
        printf("Enter 2 to stop entering nodes to linked list\n");
        fflush(stdout);
        scanf("%d",&choice_input);
        fflush(stdin);

        if (choice_input == 2)
        {
            break;
        }

        printf("Enter the data (int) to be added to the %d th node\n",(i));
        fflush(stdout);
        scanf("%d",&data_input);
        fflush(stdin);

        if (i==1)
        {
            ptr_to_1st_node = &(first_node);
            ptr_to_1st_node->data = data_input;
            ptr_to_1st_node->ptr_forward = NULL;
            ptr_to_1st_node->ptr_backward = NULL;
            linked_list_ptr = ptr_to_1st_node;

            ptr_to_previous_node = ptr_to_1st_node;
        }

        // we need to update the ptr_forward of node1



        else
        {
            struct Node node_only;
            struct Node *ptr_to_node_only;
            ptr_to_node_only = &(node_only);
            ptr_to_node_only->data = data_input;
            ptr_to_node_only->ptr_forward = NULL;
            ptr_to_node_only->ptr_backward = ptr_to_previous_node;


            ptr_to_previous_node->ptr_forward = ptr_to_node_only;

            ptr_to_previous_node = ptr_to_node_only;

            ptr_to_node_only = NULL;


        }



        i++;
    }


    traverse_linked_list(linked_list_ptr);

    printf("\n");
    return 0;
}

