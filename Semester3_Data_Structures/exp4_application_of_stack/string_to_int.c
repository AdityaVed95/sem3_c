//
// Created by Aditya Ved on 08/09/22.
//
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *s1 = "1dsa4$#%243";
    printf("%p\n",s1);
    int num1;
    sscanf(s1,"%d",&num1);
    printf("the integer value of num1 is : %d\n",num1);

    int num2 = atoi(s1);
    printf("the integer value of num2 is : %d\n",num2);


    char array1[] = {"5","4","-"};
//    char * char_ptr = &array1[0];
//    int num3 = atoi(array1[0]);
    char ch1 = "5";
    char *string = ch1;
    int num3 = atoi(string);
    printf("num3 is : %d\n",num3);

    printf("\n");
    return 0;

}