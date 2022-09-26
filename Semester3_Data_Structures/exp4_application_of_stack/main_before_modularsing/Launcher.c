//
// Created by Aditya Ved on 08/09/22.
//

// Semester3_Data_Structures/exp4_application_of_stack/main_before_modularsing/Launcher.c

#include <stdio.h>
#include <stdlib.h>
#include "stack_logic.c"
#include <ctype.h>



int main()
{
    printf("Enter the Postfix expression to be evaluated\n");
    char input_string [MAX];

    gets(input_string);
    printf("You have inputted this : \n");
    puts(input_string);
    fflush(stdin);
    fflush(stdout);
    int top = -1;
    int stack [MAX];

    int * ptr_to_bos = &(stack[0]);

    int i=0;
    int number_of_elements_in_input_string_excluding_nullTerminator;
    for(i=0;i<MAX;i++)
    {
        if(input_string[i] == '\0')
        {
            number_of_elements_in_input_string_excluding_nullTerminator = i;
            break;
        }
    }
    printf("number_of_elements_in_input_string_excluding_nullTerminator is : %d\n", number_of_elements_in_input_string_excluding_nullTerminator);

    // hello123 $% : 11 elements exclusing \0

    int num;
    int result;
    int temp1,temp2;

    for(i=0;i<number_of_elements_in_input_string_excluding_nullTerminator;i++) // going from h to % in above example
    {
        if(isdigit(input_string[i]) == 1 )
        {
            // it is a digit
//            char *string = input_string[i];
//            num = atoi(string);
//            the above steps wont work
            num = input_string[i] - '0'; // converting char to int data type
            push(ptr_to_bos,&top,num);

        }
        else if (input_string[i] == '*' || input_string[i] == '+')
        {
            temp1 = pop(ptr_to_bos,&top);
            temp2 = pop(ptr_to_bos,&top);
            result = input_string[i] == '*' ? temp2*temp1 : temp2+temp1;
            push(ptr_to_bos,&top,result);
        }
        else if (input_string[i] == '/' || input_string[i] == '-')
        {
            temp1 = pop(ptr_to_bos,&top);
            temp2 = pop(ptr_to_bos,&top);
            result = input_string[i] == '/' ? temp2/temp1 : temp2 - temp1;
            push(ptr_to_bos,&top,result);
        }
    }

    int ans = pop(ptr_to_bos,&top);
    printf("The evaluation of postifix expression is : %d\n",ans);


    printf("\n");
    return 0;
}