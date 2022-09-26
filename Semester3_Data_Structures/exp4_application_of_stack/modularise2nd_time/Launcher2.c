//
// Created by Aditya Ved on 14/09/22.
//

//
// Created by Aditya Ved on 12/09/22.
//

//
// Created by Aditya Ved on 08/09/22.
//

// Semester3_Data_Structures/exp4_application_of_stack/main_before_modularsing/Launcher.c

#include <stdio.h>
#include <stdlib.h>
#include "stack_logic.c"
#include <ctype.h>
#include <string.h>

int main()
{
    printf("Welcome to postfix evaluator\n\n");
    printf("Note : If you wish to enter a number which is more than one digit long then please enclose it \nwithin () or put a whitespace before and after that number\n");
    printf("\nPlease Enter the Postfix expression to be evaluated : \n");
    char input_string [MAX];

    gets(input_string);
    printf("You have inputted this : \n");
    puts(input_string);
    fflush(stdin);
    fflush(stdout);

    create_stack();
    // creates a stack
    // directly push into and pop elements from the stack by simple function call

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
    int flag = 0;
    char more_than_one_digit_number [number_of_elements_in_input_string_excluding_nullTerminator];
    int big_numbers_counter=0;

    for(i=0;i<number_of_elements_in_input_string_excluding_nullTerminator;i++) // going from h to % in above example
    {
        if (flag == 0)
        {


            if (isdigit(input_string[i]) == 1)
            {
                // it is a digit
                //            char *string = input_string[i];
                //            num = atoi(string);
                //            the above steps wont work
                num = input_string[i] - '0'; // converting char to int data type
                push_into_stack(num);

            }

            else if (input_string[i] == '(' || input_string[i] == ' ')
            {
                flag = 1;
            }

            else if (input_string[i] == '*' || input_string[i] == '+')
            {
                temp1 = pop_from_stack();
                temp2 = pop_from_stack();
                result = input_string[i] == '*' ? temp2 * temp1 : temp2 + temp1;
                push_into_stack(result);
            }
            else if (input_string[i] == '/' || input_string[i] == '-')
            {
                temp1 = pop_from_stack();
                temp2 = pop_from_stack();
                result = input_string[i] == '/' ? temp2 / temp1 : temp2 - temp1;
                push_into_stack(result);
            }
        }

        else if(flag == 1)
        {
            if(input_string[i] == ')' || input_string[i] == ' ')
            {
                more_than_one_digit_number[big_numbers_counter] = '\0'; // making the element after the number  =  \0 to signify end of string
                int temp = atoi(more_than_one_digit_number); // convert string number into integer number and then push it to stack
                push_into_stack(temp);
                flag =0;
            }

            else if(isdigit(input_string[i]) == 1)
            {
                more_than_one_digit_number[big_numbers_counter] = input_string[i];
                big_numbers_counter++;
            }
        }
    }

    int ans = pop_from_stack();
    printf("The evaluation of postifix expression is : %d\n",ans);


    printf("\n");
    return 0;
}