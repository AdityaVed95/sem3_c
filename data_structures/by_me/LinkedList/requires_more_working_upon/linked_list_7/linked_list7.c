//
// Created by Aditya Ved on 19/08/22.
//


#include <stdio.h>
#include <stdlib.h>

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


int delete_element(struct Node *ptr_to_1st_node,int number_of_nodes)
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

int delete_element_approach2(struct Node *ptr_to_1st_node,int number_of_nodes)
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

    metadata1.number_of_nodes = delete_element(metadata1.linked_list_ptr,metadata1.number_of_nodes);
    traverse_linked_list(metadata1.linked_list_ptr);
    delete_element_approach2(metadata1.linked_list_ptr,metadata1.number_of_nodes);
    traverse_linked_list(metadata1.linked_list_ptr);

    printf("\n");
    return 0;
}

