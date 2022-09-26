//
// Created by Aditya Ved on 17/08/22.
//

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
};


int main()
{
    struct Node node1;
    struct Node *ptr_to_node1;
    ptr_to_node1 = &(node1);
    ptr_to_node1->data = 15;

    //ptr_to_block_containing_all_pointers_to_all_the_nodes = ptr_to_block

    int *ptr_to_int = (int*) malloc(sizeof(int ));

    struct Node *ptr_to_structure1 = (struct Node*) malloc(sizeof (struct Node));
    ptr_to_structure1 = &node1;

    printf("ptr_to_node1: %u\n",ptr_to_node1);
    printf("ptr_to_structure1 : %u\n",ptr_to_structure1);

    free(ptr_to_int);

    // dropping this approach cause it will get overly complex and will have higher :
    // computational, memory, time cost

    printf("\n");
    return 0;
}