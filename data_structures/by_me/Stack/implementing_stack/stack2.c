//
// Created by Aditya Ved on 25/08/22.
//
#include <stdio.h>
#include <stdlib.h>

void push_operation(int *,int *,int **);
void pop_operation(int *,int *,int **);
void peek(int *);
void display_from_bos_to_tos(int *, int);
void display_from_tos_to_bos(int *,int);

int main()
{
    printf("Please Input values from bos to tos \n");

    int dummy =1;
    int element;
    int response;

    printf("Enter the 1st element to be pushed to stack\n");
    int first_element;
    scanf("%d",&first_element);
    int *bos_ptr = (int *) malloc(sizeof (int)); // the purpose of bos_ptr is that we can
    // realloc with it anytime, so that new elements can be pushed to stack
    *(bos_ptr)= first_element;
    int number_of_elements_in_stack=1;


    while (dummy == 1)
    {
        printf("Enter 1 to push an element to the stack and 2 to exit pushing elements\n");
        scanf("%d",&response);
        fflush(stdin);

        if (response == 1)
        {
            printf("Enter the element to be pushed to stack\n");
            scanf("%d",&element);
            fflush(stdin);
            number_of_elements_in_stack++;
            bos_ptr = (int *) realloc(bos_ptr,number_of_elements_in_stack);
            *(bos_ptr + (number_of_elements_in_stack-1) ) = element;

        }

        else if (response == 2)
        {
            break;
        }

        else
        {
            printf("Invalid input, please try again\n");
        }
    }


    printf("the inputs from bos to tos are:\n");
    int i;

    for(i=0;i<(number_of_elements_in_stack);i++)
    {
        printf("%d\n",*(bos_ptr+i));
    }

    int * tos_ptr = bos_ptr+(number_of_elements_in_stack-1);

    push_operation(bos_ptr,&(number_of_elements_in_stack),&(tos_ptr));

    printf("After pushing, the elements from bos to tos are\n");
    for(i=0;i<(number_of_elements_in_stack);i++)
    {
        printf("%d\n",*(bos_ptr+i));
    }

    pop_operation(bos_ptr,&(number_of_elements_in_stack),&(tos_ptr));

    printf("After popping, the elements from bos to tos are\n");
    for(i=0;i<(number_of_elements_in_stack);i++)
    {
        printf("%d\n",*(bos_ptr+i));
    }

    peek(tos_ptr);

    printf("Using the display_from_bos_to_tos fxn :\n");
    display_from_bos_to_tos(bos_ptr,number_of_elements_in_stack);

    printf("Using the display_from_tos_to_bos fxn :\n");
    display_from_tos_to_bos(tos_ptr,number_of_elements_in_stack);

    free(bos_ptr);
    printf("\n");
    return 0;
}

void push_operation(int *bos_ptr_in_push_fxn,int* ptr_to_number_of_elements_in_stack, int **ptr_to_tos_ptr)
{
    printf("Enter the element to be pushed on top of stack\n");
    int push_me;
    scanf("%d",&push_me);
    fflush(stdin);
    *(ptr_to_number_of_elements_in_stack) = *(ptr_to_number_of_elements_in_stack) + 1;
    int temp_new_no_of_elements_in_stack = *(ptr_to_number_of_elements_in_stack);
    bos_ptr_in_push_fxn = (int *) realloc(bos_ptr_in_push_fxn,temp_new_no_of_elements_in_stack*sizeof (int ));
    *(ptr_to_tos_ptr) = *(ptr_to_tos_ptr) + 1;
    *(*(ptr_to_tos_ptr)) = push_me;

}

void pop_operation(int *bos_ptr_in_pop_fxn, int * ptr_to_number_of_elements_in_stack, int **ptr_to_tos_ptr)
{
    printf("The element to be popped out is : %d\n",*(*(ptr_to_tos_ptr)));
    *(ptr_to_number_of_elements_in_stack) =*(ptr_to_number_of_elements_in_stack) - 1;
    int temp_new_no_of_elements_in_stack = *(ptr_to_number_of_elements_in_stack);
    bos_ptr_in_pop_fxn = (int *) realloc(bos_ptr_in_pop_fxn , temp_new_no_of_elements_in_stack * sizeof (int));
    *(ptr_to_tos_ptr) = *(ptr_to_tos_ptr) - 1;

}

void peek(int *tos_ptr)
{
    printf("The value at Top of stack is : %d\n",*(tos_ptr));
}

void display_from_bos_to_tos(int *bos_ptr,int number_of_elements_in_stack)
{
    int i;
    for(i=0;i<number_of_elements_in_stack;i++)
    {
        printf("%d\n",*(bos_ptr+i));
    }
}

void display_from_tos_to_bos(int *tos_ptr,int number_of_elements_in_stack)
{
    int i;
    for(i=0;i<number_of_elements_in_stack;i++)
    {
        printf("%d\n",*(tos_ptr-i));
    }
}