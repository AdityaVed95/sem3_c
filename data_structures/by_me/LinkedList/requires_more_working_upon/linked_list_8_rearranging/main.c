//
// Created by Aditya Ved on 19/08/22.
//

//
// Created by Aditya Ved on 19/08/22.
//


#include <stdio.h>
#include <stdlib.h>
#include "traverse_linked_list.c"
#include "delete_given_element.c"
#include "delete_given_node.c"

struct Node
{
    int data;
    struct Node *ptr_forward;
    struct Node *ptr_backward;
};



struct MetaData
{
    struct Node *linked_list_ptr;
    int number_of_nodes;
};

struct MetaData metadata1;



int main()
{
    struct Node *ptr_to_previous_node;




    struct Node *ptr_to_1st_node = (struct Node *) malloc(sizeof (struct Node));

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
            ptr_to_1st_node->data = data_input;
            ptr_to_1st_node->ptr_forward = NULL;
            ptr_to_1st_node->ptr_backward = NULL;
            metadata1.linked_list_ptr = ptr_to_1st_node;
            ptr_to_previous_node = ptr_to_1st_node;
        }

        else
        {
            struct Node *ptr_to_node_only = malloc(sizeof(struct Node)); // this
            // is another way of creating pointer to a structure


            ptr_to_node_only->data = data_input;
            ptr_to_node_only->ptr_forward = NULL;
            ptr_to_node_only->ptr_backward = ptr_to_previous_node;


            ptr_to_previous_node->ptr_forward = ptr_to_node_only;

            ptr_to_previous_node = ptr_to_node_only;

            //free(ptr_to_node_only);

            // creating an instance of a structure every time in the loop will actually create
            // the same structure in every iteration of the loop and thus the pointer to the
            // structure will be the same in each iteration of the loop , due to this the
            // ptr_forward = ptr_backward != NULL and thus list_traversal loop will become
            // an infinite loop

            // this is not like C++, in C++ a new object of the class is created for the every
            // iteration
            // of the loop, thus no need to use malloc in case of C++




        }



        i++;
    }

    // from now on linked list pointer is the pointer to the 1st node
    // so now when we are dealing inside the main_before_modularsing function, then we will not use pointer to 1st node
    // we will only use linked list pointer as a rule of thumb
    metadata1.number_of_nodes = i-1;
    printf("Number of nodes are : %d\n",metadata1.number_of_nodes);
    traverse_linked_list(metadata1.linked_list_ptr);

    metadata1.number_of_nodes = delete_given_element(metadata1.linked_list_ptr,metadata1.number_of_nodes);
    traverse_linked_list(metadata1.linked_list_ptr);
    delete_given_node(metadata1.linked_list_ptr,metadata1.number_of_nodes);
    traverse_linked_list(metadata1.linked_list_ptr);

    printf("\n");
    return 0;
}

