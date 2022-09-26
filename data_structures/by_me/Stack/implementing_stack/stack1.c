//
// Created by Aditya Ved on 25/08/22.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("1st Input values into the stack: \n");
    int *tos_ptr = (int *) malloc(0);
    int number_of_elements_in_stack=0;
    int dummy =1;
    int element;

    int response;
    while(dummy == 1)
    {
        printf("Enter 1 to push an element on stack and 2 to exit pushing elements\n");
        scanf("%d",&response);
        fflush(stdin);

        if (response == 1)
        {
            printf("Enter the element to be pushed to stack\n");

            scanf("%d",&element);
            fflush(stdin);
            number_of_elements_in_stack++;
            tos_ptr = (int *) realloc(tos_ptr,number_of_elements_in_stack);
            *(tos_ptr) = element;

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

    printf("the input from tos to bos is :\n");
    int *ptr_iterator;
    ptr_iterator = tos_ptr;
    int i;
    for(i=0;i<number_of_elements_in_stack;i++)
    {
        printf("%d\n",*(ptr_iterator));
        ptr_iterator--;
    }




    printf("\n");
    return 0;
}
