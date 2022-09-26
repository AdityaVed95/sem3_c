//
// Created by Aditya Ved on 18/08/22.
//

// some standard functions that can be created :
// calculating ptr_to_last_node when you know ptr_to_1st_node and the number of nodes

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data; // challenge : make this as a structure instead of int ,
    struct Node *ptr_forward;
    struct Node *ptr_backward; // when the algorithm is about searching thousands of nodes , and if the nodes are sorted in a particular order then ptr_backward can help to search in opposite direction with higher speed

};

// more functionalities to be added :
// searching for an element(whether it exist or not)
// deleting all the occurrences of a particular element

// if struct data instead of int data is used :
// searching based on a particular element of structure etc....


struct Node *linked_list_ptr;

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

}


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
            linked_list_ptr = ptr_to_1st_node->ptr_forward;
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

int delete_given_node(struct Node *ptr_to_1st_node,int number_of_nodes)
{
    printf("Enter the node number (1 based numbering) that needs to be deleted from the linked list\n");
    int node_to_be_deleted;
    scanf("%d",&node_to_be_deleted);

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
            linked_list_ptr = ptr_to_1st_node->ptr_forward;
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


int insert_node(struct Node *ptr_to_1st_node,int number_of_nodes)
{
    printf("Enter the position (1 based numbering) at which you want to enter a new node\n");
    fflush(stdout);
    int position_of_node_insertion;
    scanf("%d",&position_of_node_insertion);
    fflush(stdin);

    if(1<=position_of_node_insertion<=(number_of_nodes+1))
    {
        printf("Enter the data you want to insert at that node\n");
        int data_of_new_node;
        scanf("%d",&data_of_new_node);
        fflush(stdin);

        struct Node *ptr_to_new_node = (struct Node*) malloc(sizeof (struct Node));
        ptr_to_new_node->data = data_of_new_node;


        if(position_of_node_insertion==1)
        {
            linked_list_ptr->ptr_backward = ptr_to_new_node;

            ptr_to_new_node->ptr_backward = NULL;
            ptr_to_new_node->ptr_forward = linked_list_ptr;
            linked_list_ptr = ptr_to_new_node;

            number_of_nodes = number_of_nodes+1;
            return number_of_nodes;

        }

        else if(position_of_node_insertion == number_of_nodes+1)
        {
            ptr_to_new_node->ptr_forward = NULL;

            struct Node *ptr_next;
            int i;
            struct Node *ptr_to_last_node;
            ptr_next = ptr_to_1st_node;
            for(i=0;i<number_of_nodes-1;i++)
            {
                ptr_next = ptr_next->ptr_forward;
            }

            ptr_to_last_node = ptr_next;

            ptr_to_last_node->ptr_forward = ptr_to_new_node;
            ptr_to_new_node->ptr_backward = ptr_to_last_node;

            number_of_nodes = number_of_nodes+1;
            return number_of_nodes;


        }

        else
        {

            struct Node* ptr_to_node_before_new_node;
            struct Node* ptr_to_node_after_new_node;

            int i;

            struct Node *ptr_next;
            ptr_next = ptr_to_1st_node;
            for(i=0;i<(position_of_node_insertion-1);i++)
            {
                ptr_next = ptr_next->ptr_forward;
            }

            ptr_to_node_after_new_node = ptr_next;

            // i=0 ptr_next = 58b0
            // i =1  ptr_next =4080
            // i =2   ptr_next = 9782
            // i =3    ptr_next = 7467

            ptr_next = ptr_to_1st_node;
            for(i=0;i<(position_of_node_insertion-2);i++)
            {
                ptr_next = ptr_next->ptr_forward;
            }

            ptr_to_node_before_new_node = ptr_next;

            ptr_to_node_before_new_node->ptr_forward = ptr_to_new_node;
            ptr_to_node_after_new_node->ptr_backward = ptr_to_new_node;

            ptr_to_new_node->ptr_forward = ptr_to_node_after_new_node;
            ptr_to_new_node->ptr_backward=ptr_to_node_before_new_node;

            number_of_nodes = number_of_nodes+1;
            return number_of_nodes;

        }


    }

    else
    {
        printf("Cannot insert nodes beyond the boundary of linked list\n");
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
            linked_list_ptr = ptr_to_1st_node;
            ptr_to_previous_node = ptr_to_1st_node;
        }

            // we need to update the ptr_forward of node1



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
    int number_of_nodes = i-1;
    printf("Number of nodes are : %d\n",number_of_nodes);
    traverse_linked_list(linked_list_ptr);

    number_of_nodes = delete_given_element(linked_list_ptr,number_of_nodes);
    traverse_linked_list(linked_list_ptr);
    delete_given_node(linked_list_ptr,number_of_nodes);
    traverse_linked_list(linked_list_ptr);
    insert_node(linked_list_ptr,number_of_nodes);
    traverse_linked_list(linked_list_ptr);

    printf("\n");
    return 0;
}

