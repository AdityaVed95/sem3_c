//
// Created by Aditya Ved on 08/09/22.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
//    printf("Enter the input_string\n");
//    char input_string[100];
//    gets(input_string);
//    puts(input_string);
//    int i=0;
//
//    while(input_string[i] != '\0')
//    {
//        printf("%c\n",input_string[i]);
//        i++;
//    }
//
//    printf("\n");
//    return 0;


    int MAX=100;
    printf("Enter the Postfix expression to be evaluated\n");
    char input_string [MAX];

    gets(input_string);
    puts(input_string);

    int top = -1;
    char stack [MAX];

    char * ptr_to_bos = &(stack[0]);
    int i=0;

    while(input_string[i] != '\0')
    {
        printf("%c\n",input_string[i]);
        i++;
    }


    printf("\n");
    return 0;
}