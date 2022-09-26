//
// Created by Aditya Ved on 03/09/22.
//

#include <stdio.h>
int factorial(int);

int main()
{
    int num = 4;
    int fact = factorial(num);
    printf("Factorial is : %d",fact);
    printf("\n");
    return 0;
}

int factorial(int n)
{
    if(n == 0)
    {
        return 1;
    }

    else
    {
        return n*factorial(n-1);
    }
}