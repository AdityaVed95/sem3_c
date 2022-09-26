//
// Created by Aditya Ved on 19/09/22.
//

#include <stdio.h>
#include <stdlib.h>
#include "binary_operations_library.c"
int MAX_BITS_SIZE = 4;

int main()
{
    printf("\n\tWelcome to Restoring Division Algorithm for unsigned numbers\n");
    int dividend_decimal;
    int divisor_decimal;
    printf("\nNote : If you wish to perform division for bigger numbers, simply increase the value \nof MAX_BITS_SIZE in the program and the program will work just as expected !!!\nDefault is set to 4 bits \nHappy Dividing !!!\n\n");

    printf("Enter the dividend : \n");

    scanf("%d",&dividend_decimal);
    fflush(stdin);

    printf("Enter the divisor\n");
    scanf("%d",&divisor_decimal);
    fflush(stdin);

    int Q_dividend_binary [MAX_BITS_SIZE];
    int M_divisor_binary [MAX_BITS_SIZE];

    printf("Converting Decimal input to binary :\n");
    convert_positive_decimal_number_to_binary(dividend_decimal,Q_dividend_binary,MAX_BITS_SIZE);
    convert_positive_decimal_number_to_binary(divisor_decimal,M_divisor_binary,MAX_BITS_SIZE);


    printf("Binary Value of Dividend is : ");
    display_integer_binary_number_array(Q_dividend_binary,MAX_BITS_SIZE);
    printf("\nBinary Value of Divisor is : ");
    display_integer_binary_number_array(M_divisor_binary,MAX_BITS_SIZE);
    printf("\n\n");
    printf("===============================================================================\n");

    int accumulator[MAX_BITS_SIZE];
    int i;
    // initialise accumulator
    for(i=0;i<MAX_BITS_SIZE;i++)
    {
        accumulator[i] = 0;
    }

    int count = MAX_BITS_SIZE;
    int left_shifted_accumulator[MAX_BITS_SIZE];
    int left_shifted_Q_dividend [MAX_BITS_SIZE];

    while (count != 0)
    {

        // left shift binary
        printf("For count = %d \n\n",count);
        left_shift(accumulator,left_shifted_accumulator,MAX_BITS_SIZE);
        for(i=0;i<MAX_BITS_SIZE;i++)
        {
            accumulator[i] = left_shifted_accumulator[i];
        }

        accumulator[MAX_BITS_SIZE-1] = Q_dividend_binary[0];

        // display A after left shift
        printf("Value of A register after performing left shift is: ");
        display_integer_binary_number_array(accumulator,MAX_BITS_SIZE);

        left_shift(Q_dividend_binary,left_shifted_Q_dividend,MAX_BITS_SIZE);
        for(i=0;i<MAX_BITS_SIZE;i++)
        {
            Q_dividend_binary[i] = left_shifted_Q_dividend[i];
        }


        binary_subtraction(accumulator,M_divisor_binary,accumulator,MAX_BITS_SIZE);

        if(accumulator[0] == 1)
        {
            printf("Value in A register after performing A-M is negative\nThus Restoration of A is performed\n");
            // A is negative
            // unsuccessful step
            // quotient bit  = 0
            Q_dividend_binary[MAX_BITS_SIZE-1] = 0;
            // restoration is performed
            binary_addition(accumulator,M_divisor_binary,accumulator,MAX_BITS_SIZE);


            // display final value of A and Q for the current step
            printf("Value of A register at the end of this step is :  ");
            display_integer_binary_number_array(accumulator,MAX_BITS_SIZE);
            printf("Value of Q register at the end of this step is : ");
            display_integer_binary_number_array(Q_dividend_binary,MAX_BITS_SIZE);

            printf("===============================================================================\n");
            count--;
        }

        else if(accumulator[0] == 0)
        {
            // A is positive
            // successful step
            // quotient bit = 1
            printf("Value in A register after performing A-M is positive\nThus Restoration of A is not performed\n");
            Q_dividend_binary[MAX_BITS_SIZE-1] = 1;


            // display final value of A and Q for the current step
            printf("Value of A register at the end of this step is :  ");
            display_integer_binary_number_array(accumulator,MAX_BITS_SIZE);
            printf("Value of Q register at the end of this step is : ");
            display_integer_binary_number_array(Q_dividend_binary,MAX_BITS_SIZE);
            printf("===============================================================================\n");
            // restoration is not performed
            count--;

        }

    }

    printf("\n\nThe quotient that we got from the algorithm is : \n");
    display_integer_binary_number_array(Q_dividend_binary,MAX_BITS_SIZE);

    printf("\nThe remainder that we got from the algorithm is : \n");
    display_integer_binary_number_array(accumulator,MAX_BITS_SIZE);

    int quotient,remainder;
    convert_positive_or_negative_binary_number_to_decimal(accumulator,&remainder,MAX_BITS_SIZE);
    convert_positive_or_negative_binary_number_to_decimal(Q_dividend_binary,&quotient,MAX_BITS_SIZE);

    printf("\n\nConverting the binary form of quotient and remainder to decimal:\n\n");
    printf("Quotient = %d\n",quotient);
    printf("Remainder = %d\n",remainder);
    printf("\nThank You !\n");
    printf("\n");
    return 0;
}