//
// Created by Aditya Ved on 12/09/22.
//

//
// Created by Aditya Ved on 08/09/22.
//

// this program is giving bad access error
// my interpretation is that the stack[100] might not be living in the memory
// thus through pointers we are trying to access a memory location which has not been allocated to us and thus this is giving a bad access error

#include <stdio.h>
#include <stdlib.h>

int *ptr_to_bos;
int *ptr_to_tos_variable;
int MAX = 100;
int stack[100];
int top;

void push_into_stack(int);
int pop_from_stack();

//int main_before_modularsing()
//{
//
//    int * ptr_to_bos = &(stack[0]);
//    top = -1;
//    ptr_to_tos_variable = &top;
//    return 0;
//}

void create_stack()
{
    for(int i =0;i<100;i++)
    {
        stack[i] = 0;
    }
    ptr_to_bos = &(stack[0]);
    top = -1;
    ptr_to_tos_variable = &top;

}



void push_into_stack(int element)
{
    if(*(ptr_to_tos_variable) == MAX-1)
    {
        printf("The stack is full, cannot perform push operation\n");
        return;
    }

    *(ptr_to_tos_variable) +=1;
    *( ptr_to_bos + *(ptr_to_tos_variable) ) = element;
    printf("Successfully pushed %d to stack\n",element);

}

int pop_from_stack()
{
    if(*(ptr_to_tos_variable) == -1)
    {
        printf("The stack is empty, pop operation cannot be performed\n");
        printf("Please push more items and then try to pop them later\n");
        return 0;
    }

    int element_to_be_popped = ptr_to_bos[*(ptr_to_tos_variable)];

    printf("Popping %d from the stack\n",element_to_be_popped);
    ptr_to_bos[*(ptr_to_tos_variable)] = 0;
    *(ptr_to_tos_variable) -= 1;
    printf("Successfully popped out %d from stack\n",element_to_be_popped);
    return element_to_be_popped;
}


//void create_stack(int *, int *);
//
//void peek(int *, int *);
//void display_tos_to_bos(char *, int *);
//void display_bos_to_tos(int *, int *);
//void clear_stack(int *, int *);
//void destroy_stack_and_exit(int *, int *);


//void peek(int * ptr_to_bos, int * ptr_to_tos_variable)
//{
//    if(*(ptr_to_tos_variable) == -1)
//    {
//        printf("The stack is empty, peek operation is invalid\n");
//        return;
//    }
//
//    int element_at_tos = ptr_to_bos[*(ptr_to_tos_variable)];
//    printf("The element at top of stack is : %d\n",element_at_tos);
//
//}
//
//void create_stack(int *ptr_to_bos, int *ptr_to_tos_variable)
//{
//    printf("Welcome to static stack program, enter the elements from bos to tos in order to create a stack\n");
//    int dummy = 1;
//    int response;
//    int element;
//    int element_added_counter=0;
//
//
//    while(dummy == 1)
//    {
//        printf("Enter 1 to push new element to stack\n");
//        printf("Enter 2 to exit the creation of stack\n");
//        scanf("%d",&response);
//        fflush(stdin);
//
//        if(response == 1)
//        {
//            if(*(ptr_to_tos_variable) == MAX -1)
//            {
//                printf("Sorry the stack is full, cant add more elements\n");
//                printf("Thus exiting the creation of stack and proceding to perform operations on stack\n");
//                break;
//            }
//
//            printf("Enter the element to be pushed to stack\n");
//            scanf("%d",&element);
//            fflush(stdin);
//            ptr_to_bos[element_added_counter] = element;
//            element_added_counter++;
//            *(ptr_to_tos_variable) += 1;
//            printf("Successfully pushed %d to stack\n",element);
//
//        }
//
//        else if(response == 2)
//        {
//            break;
//        }
//
//    }
//
//}
//
//void display_tos_to_bos(char * ptr_to_bos, int * ptr_to_tos_variable)
//{
//    int i;
//    printf("Displaying stack from top to bottom : \n");
//    for(i=*(ptr_to_tos_variable);i>=0;i--)
//    {
//        printf("%d\n",ptr_to_bos[i]);
//    }
//}
//
//void display_bos_to_tos(int * ptr_to_bos, int * ptr_to_tos_variable)
//{
//    int i;
//    printf("Displaying stack from bottom to top : \n");
//    for(i=0;i<=(*(ptr_to_tos_variable));i++)
//    {
//        printf("%d\n",ptr_to_bos[i]);
//    }
//
//}
//
//void clear_stack(int * ptr_to_bos, int * ptr_to_tos_variable)
//{
//    // here top is pointing to tos
//    // making all the elements of the array =0 and making the top = -1
//    printf("Clearing the stack :\n");
//    while (*(ptr_to_tos_variable) > -1)
//    {
//        ptr_to_bos[*(ptr_to_tos_variable)] = 0;
//        *(ptr_to_tos_variable) -= 1;
//    }
//}
//
//
//void destroy_stack_and_exit(int * ptr_to_bos, int * ptr_to_tos_variable)
//{
//    clear_stack(ptr_to_bos,ptr_to_tos_variable);
//
//    printf("The stack has been cleared, hope you enjoyed playing with stacks !!!!!!! \n");
//
//}
//
//
//int main1()
//{
//    int stack1[MAX];
//    int dummy = 1;
//    int top = -1; // stack is empty
//    int *ptr_to_bos = &(stack1[0]);
//    // int number_of_elements_in_stack= top+1 ====> always
//
//    create_stack(ptr_to_bos, &top);
//    int response;
//
//    while(dummy == 1)
//    {
//        printf("Enter 1 to perform push operation\n");
//        printf("Enter 2 to perform pop operation\n");
//        printf("Enter 3 to perform peek operation\n");
//        printf("Enter 4 to display stack from top of stack to bottom of stack\n");
//        printf("Enter 5 to display stack from bottom of stack to top of stack\n");
//        printf("Enter 6 to clear the stack\n");
//        printf("Enter 7 to destroy/clear the stack and exit the program\n");
//
//        scanf("%d",&response);
//        fflush(stdin);
//
//        if(response == 1)
//        {
//            push(ptr_to_bos,&top);
//        }
//
//        else if(response == 2)
//        {
//            pop(ptr_to_bos,&top);
//        }
//
//        else if(response == 3)
//        {
//            peek(ptr_to_bos,&top);
//        }
//
//        else if(response == 4)
//        {
//            display_tos_to_bos(ptr_to_bos,&top);
//        }
//
//        else if(response == 5)
//        {
//            display_bos_to_tos(ptr_to_bos,&top);
//        }
//
//        else if (response == 6)
//        {
//            clear_stack(ptr_to_bos,&top);
//        }
//
//
//        else if(response == 7)
//        {
//            destroy_stack_and_exit(ptr_to_bos, &top);
//            break;
//        }
//
//        else
//        {
//            printf("Invalid input please try again later");
//        }
//
//    }
//
//    printf("\n");
//    return 0;
//}
