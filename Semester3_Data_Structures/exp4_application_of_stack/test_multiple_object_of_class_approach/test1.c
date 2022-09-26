//
// Created by Aditya Ved on 12/09/22.
//

#include <stdio.h>
#include <stdlib.h>
#include "stack_logic.c"

int main()
{
    create_stack();
    push_into_stack(10);
    push_into_stack(20);
    push_into_stack(30);
    display_tos_to_bos();


    create_stack();
    push_into_stack(40);
    push_into_stack(50);
    push_into_stack(60);
    display_tos_to_bos();

    pop_from_stack();
    display_tos_to_bos();

    printf("\n");
    return 0;
}