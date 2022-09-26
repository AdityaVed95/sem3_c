//
// Created by Aditya Ved on 08/09/22.
//

#include "ll_call_me.c"
#include <stdio.h>
#include <stdlib.h>

int main()
{


    struct Node * ll_ptr_in_main = NULL;
    printf("Enter the element to be inserted in the 1st node:\n");
    char first_element_in_main;
    scanf("%c",&first_element_in_main);
    fflush(stdin);

    ll_ptr_in_main = create_linked_list_and_insert_1st_node(first_element_in_main);
    int number_of_nodes_in_main = 1;

    number_of_nodes_in_main = insert_node(ll_ptr_in_main,number_of_nodes_in_main);
    number_of_nodes_in_main = insert_node(ll_ptr_in_main,number_of_nodes_in_main);
    number_of_nodes_in_main = insert_node(ll_ptr_in_main,number_of_nodes_in_main);

    traverse_linked_list(ll_ptr_in_main);




    printf("\n");
    return 0;
}


