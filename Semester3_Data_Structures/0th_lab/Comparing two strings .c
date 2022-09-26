//
// Created by Aditya Ved on 18/08/22.
//
#include <stdio.h>

int compare(char *ptr1,char*ptr2)
{
    while(*ptr1 == *ptr2)
    {
        if(*ptr1 == '\0' && *ptr2 == '\0')
        {
            break;
        }
        ptr1++;
        ptr2++;
    }

    if(*ptr1 == '\0' && *ptr2 == '\0' )
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

int main()
{

    char string1[100];
    char string2[100];
    int result;

    printf("Enter 1st string\n");
    fflush(stdout);

    gets(string1);
    fflush(stdin);

    printf("Enter the 2nd string : \n");
    gets(string2);
    fflush(stdin);



    char *ptr1 = &(string1);
    char *ptr2  = &(string2);

    result = compare(ptr1,ptr2);

    if (result == 1)
    {
        printf("yes same");
    }

    else
    {
        printf("Not same");
    }

    return 0;
}
