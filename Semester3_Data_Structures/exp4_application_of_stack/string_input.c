//
// Created by Aditya Ved on 08/09/22.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter the input string to be evaluated : \n");
    char input_string[15];
    printf("Size of input string is : %d\n",sizeof (input_string));
    fgets(input_string,sizeof (input_string),stdin);

//  gets() function is unsafe dont use it :
// The gets() function is unsafe because it does not perform bounds
// checking on the size of its input. An attacker can easily send
// arbitrarily-sized input to gets() and overflow the destination buffer.

//    gets(input_string);

    printf("Input string is : %s\n",input_string);

    printf("\n");
    return 0;
}