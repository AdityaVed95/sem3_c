//
// Created by Aditya Ved on 16/08/22.
//
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
    printf("Value of data at ptr (at 1st node) is : %d\n",ptr_to_1st_node->data);
    printf("Value at the 2nd node is : %d\n",(ptr_to_1st_node->ptr_forward)->data);
    printf("Value at the 3rd node %d\n",(((ptr_to_1st_node->ptr_forward)->ptr_forward)->data));

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

    struct Node node1;
    node1.data = 15;
    node1.ptr_forward = NULL;
    node1.ptr_backward = NULL;

    linked_list_ptr = &(node1);
    // linked_list_ptr is a pointer pointing to the 1st node
    // pointer to an instance of the structure

    struct Node node2;
    node2.data = 25;
    node2.ptr_backward=&(node1);
    node2.ptr_forward = NULL;

    node1.ptr_forward = &(node2);

    struct Node node3;
    node3.data = 35;
    node3.ptr_forward=NULL;
    node3.ptr_backward = &(node2);

    node2.ptr_forward = &(node3);

    traverse_linked_list(linked_list_ptr);

    printf("\n");
    return 0;
}

