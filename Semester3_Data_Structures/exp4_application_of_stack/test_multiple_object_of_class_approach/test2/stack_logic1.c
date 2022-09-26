//
// Created by Aditya Ved on 14/09/22.
//

//
// Created by Aditya Ved on 12/09/22.
//

//
// Created by Aditya Ved on 08/09/22.
//

// this program is giving bad access error
// my interpretation is that the stack2[100] might not be living in the memory
// thus through pointers we are trying to access a memory location which has not been allocated to us and thus this is giving a bad access error

#include <stdio.h>
#include <stdlib.h>

int *ptr_to_bos1;
int *ptr_to_tos_variable1;
int MAX1 = 100;
int stack1[100];
int top1;

void push_into_stack1(int);
int pop_from_stack1();

//int main_before_modularsing()
//{
//
//    int * ptr_to_bos1 = &(stack1[0]);
//    top1 = -1;
//    ptr_to_tos_variable1 = &top1;
//    return 0;
//}

void create_stack1()
{
    for(int i =0;i<100;i++)
    {
        stack1[i] = 0;
    }
    ptr_to_bos1 = &(stack1[0]);
    top1 = -1;
    ptr_to_tos_variable1 = &top1;

}



void push_into_stack1(int element)
{
    if(*(ptr_to_tos_variable1) == MAX1 - 1)
    {
        printf("The stack2 is full, cannot perform push operation\n");
        return;
    }

    *(ptr_to_tos_variable1) +=1;
    *(ptr_to_bos1 + *(ptr_to_tos_variable1) ) = element;
    printf("Successfully pushed %d to stack1\n",element);

}

int pop_from_stack1()
{
    if(*(ptr_to_tos_variable1) == -1)
    {
        printf("The stack1 is empty, pop operation cannot be performed\n");
        printf("Please push more items and then try to pop them later\n");
        return 0;
    }

    int element_to_be_popped = ptr_to_bos1[*(ptr_to_tos_variable1)];

    printf("Popping %d from the stack1\n",element_to_be_popped);
    ptr_to_bos1[*(ptr_to_tos_variable1)] = 0;
    *(ptr_to_tos_variable1) -= 1;
    printf("Successfully popped out %d from stack1\n",element_to_be_popped);
    return element_to_be_popped;
}


void display_tos_to_bos1()
{
    int i;
    printf("Displaying stack1 from top to bottom : \n");
    for(i=*(ptr_to_tos_variable1); i >= 0; i--)
    {
        printf("%d\n", ptr_to_bos1[i]);
    }
}


//void create_stack(int *, int *);
//
//void peek(int *, int *);
//void display_tos_to_bos(char *, int *);
//void display_bos_to_tos(int *, int *);
//void clear_stack(int *, int *);
//void destroy_stack_and_exit(int *, int *);


//void peek(int * ptr_to_bos1, int * ptr_to_tos_variable1)
//{
//    if(*(ptr_to_tos_variable1) == -1)
//    {
//        printf("The stack2 is empty, peek operation is invalid\n");
//        return;
//    }
//
//    int element_at_tos = ptr_to_bos1[*(ptr_to_tos_variable1)];
//    printf("The element at top1 of stack2 is : %d\n",element_at_tos);
//
//}
//
//void create_stack(int *ptr_to_bos1, int *ptr_to_tos_variable1)
//{
//    printf("Welcome to static stack2 program, enter the elements from bos to tos in order to create a stack2\n");
//    int dummy = 1;
//    int response;
//    int element;
//    int element_added_counter=0;
//
//
//    while(dummy == 1)
//    {
//        printf("Enter 1 to push new element to stack2\n");
//        printf("Enter 2 to exit the creation of stack2\n");
//        scanf("%d",&response);
//        fflush(stdin);
//
//        if(response == 1)
//        {
//            if(*(ptr_to_tos_variable1) == MAX1 -1)
//            {
//                printf("Sorry the stack2 is full, cant add more elements\n");
//                printf("Thus exiting the creation of stack2 and proceding to perform operations on stack2\n");
//                break;
//            }
//
//            printf("Enter the element to be pushed to stack2\n");
//            scanf("%d",&element);
//            fflush(stdin);
//            ptr_to_bos1[element_added_counter] = element;
//            element_added_counter++;
//            *(ptr_to_tos_variable1) += 1;
//            printf("Successfully pushed %d to stack2\n",element);
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
//void display_tos_to_bos(char * ptr_to_bos1, int * ptr_to_tos_variable1)
//{
//    int i;
//    printf("Displaying stack2 from top1 to bottom : \n");
//    for(i=*(ptr_to_tos_variable1);i>=0;i--)
//    {
//        printf("%d\n",ptr_to_bos1[i]);
//    }
//}
//
//void display_bos_to_tos(int * ptr_to_bos1, int * ptr_to_tos_variable1)
//{
//    int i;
//    printf("Displaying stack2 from bottom to top1 : \n");
//    for(i=0;i<=(*(ptr_to_tos_variable1));i++)
//    {
//        printf("%d\n",ptr_to_bos1[i]);
//    }
//
//}
//
//void clear_stack(int * ptr_to_bos1, int * ptr_to_tos_variable1)
//{
//    // here top1 is pointing to tos
//    // making all the elements of the array =0 and making the top1 = -1
//    printf("Clearing the stack2 :\n");
//    while (*(ptr_to_tos_variable1) > -1)
//    {
//        ptr_to_bos1[*(ptr_to_tos_variable1)] = 0;
//        *(ptr_to_tos_variable1) -= 1;
//    }
//}
//
//
//void destroy_stack_and_exit(int * ptr_to_bos1, int * ptr_to_tos_variable1)
//{
//    clear_stack(ptr_to_bos1,ptr_to_tos_variable1);
//
//    printf("The stack2 has been cleared, hope you enjoyed playing with stacks !!!!!!! \n");
//
//}
//
//
//int main1()
//{
//    int stack2[MAX1];
//    int dummy = 1;
//    int top1 = -1; // stack2 is empty
//    int *ptr_to_bos1 = &(stack2[0]);
//    // int number_of_elements_in_stack= top1+1 ====> always
//
//    create_stack(ptr_to_bos1, &top1);
//    int response;
//
//    while(dummy == 1)
//    {
//        printf("Enter 1 to perform push operation\n");
//        printf("Enter 2 to perform pop operation\n");
//        printf("Enter 3 to perform peek operation\n");
//        printf("Enter 4 to display stack2 from top1 of stack2 to bottom of stack2\n");
//        printf("Enter 5 to display stack2 from bottom of stack2 to top1 of stack2\n");
//        printf("Enter 6 to clear the stack2\n");
//        printf("Enter 7 to destroy/clear the stack2 and exit the program\n");
//
//        scanf("%d",&response);
//        fflush(stdin);
//
//        if(response == 1)
//        {
//            push(ptr_to_bos1,&top1);
//        }
//
//        else if(response == 2)
//        {
//            pop(ptr_to_bos1,&top1);
//        }
//
//        else if(response == 3)
//        {
//            peek(ptr_to_bos1,&top1);
//        }
//
//        else if(response == 4)
//        {
//            display_tos_to_bos(ptr_to_bos1,&top1);
//        }
//
//        else if(response == 5)
//        {
//            display_bos_to_tos(ptr_to_bos1,&top1);
//        }
//
//        else if (response == 6)
//        {
//            clear_stack(ptr_to_bos1,&top1);
//        }
//
//
//        else if(response == 7)
//        {
//            destroy_stack_and_exit(ptr_to_bos1, &top1);
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
