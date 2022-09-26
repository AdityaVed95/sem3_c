//
// Created by Aditya Ved on 14/09/22.
//

//
// Created by Aditya Ved on 12/09/22.
//

#include <stdio.h>
#include <stdlib.h>
#include "stack_logic1.c"
#include "../test3/stack_logic2.c"

int main()
{
    create_stack1();
    push_into_stack1(10);
    push_into_stack1(20);
    push_into_stack1(30);
    display_tos_to_bos1();


    create_stack2();
    display_tos_to_bos1();

    push_into_stack2(40);
    push_into_stack2(50);
    push_into_stack2(60);
    display_tos_to_bos2();

    pop_from_stack2();
    display_tos_to_bos2();
    display_tos_to_bos1();

    printf("\n");
    return 0;
}