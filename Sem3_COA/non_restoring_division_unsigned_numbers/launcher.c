//
// Created by Aditya Ved on 26/09/22.
//

#include <stdio.h>
#include <stdlib.h>
#include "binary_operations_library.c"
int MAX_BITS_SIZE = 4;

void left_shift_A_and_Q(int *  , int * , int * , int * );
void final_display_quotient_and_remainder(int *  , int * );

int main()
{
    printf("\n\tWelcome to Non Restoring Division Algorithm for unsigned numbers\n");
    int dividend_decimal;
    int divisor_decimal;
    printf("\nNote : If you wish to perform division for bigger numbers, simply increase the value \nof MAX_BITS_SIZE in the program and the program will work just as expected !!!\nDefault is set to 4 bits \nHappy Dividing !!!\n\n");

    printf("Enter the dividend : \n");

    scanf("%d", &dividend_decimal);
    fflush(stdin);

    printf("Enter the divisor\n");
    scanf("%d", &divisor_decimal);
    fflush(stdin);

    int Q_dividend_binary[MAX_BITS_SIZE];
    int M_divisor_binary[MAX_BITS_SIZE];

    printf("Converting Decimal input to binary :\n");
    convert_positive_decimal_number_to_binary(dividend_decimal, Q_dividend_binary, MAX_BITS_SIZE);
    convert_positive_decimal_number_to_binary(divisor_decimal, M_divisor_binary, MAX_BITS_SIZE);


    printf("Binary Value of Dividend is : ");
    display_integer_binary_number_array(Q_dividend_binary, MAX_BITS_SIZE);
    printf("\nBinary Value of Divisor is : ");
    display_integer_binary_number_array(M_divisor_binary, MAX_BITS_SIZE);
    printf("\n\n");
    printf("===============================================================================\n");

    int accumulator[MAX_BITS_SIZE];
    int i;
    // initialise accumulator
    for (i = 0; i < MAX_BITS_SIZE; i++)
    {
        accumulator[i] = 0;
    }

    int count = MAX_BITS_SIZE;
    int left_shifted_accumulator[MAX_BITS_SIZE];
    int left_shifted_Q_dividend[MAX_BITS_SIZE];


    while (count != 0)
    {
        // left shift binary
        printf("For count = %d \n\n",count);

        if(accumulator[0] == 1)
        {
            left_shift_A_and_Q(accumulator,left_shifted_accumulator,Q_dividend_binary,left_shifted_Q_dividend);
            binary_addition(accumulator,M_divisor_binary,accumulator,MAX_BITS_SIZE);
        }

        else if (accumulator[0] == 0)
        {
            left_shift_A_and_Q(accumulator,left_shifted_accumulator,Q_dividend_binary,left_shifted_Q_dividend);
            binary_subtraction(accumulator,M_divisor_binary,accumulator,MAX_BITS_SIZE);
        }


        if(accumulator[0] == 1)
        {
            Q_dividend_binary[MAX_BITS_SIZE-1] = 0;
        }

        else if(accumulator[0] == 0)
        {
            Q_dividend_binary[MAX_BITS_SIZE-1] = 1;
        }


        // display final value of A and Q for the current step
        if(count != 1)
        {
            printf("Value of A register at the end of this step is :  ");
            display_integer_binary_number_array(accumulator,MAX_BITS_SIZE);
            printf("Value of Q register at the end of this step is : ");
            display_integer_binary_number_array(Q_dividend_binary,MAX_BITS_SIZE);
            printf("===============================================================================\n");

        }


        count--;

    }

    // if A register is negative
    if(accumulator[0] == 1)
    {
        // restoration is performed in the last step
        printf("Restoration is performed in the last step as we get negative value in A register in the last step\n");
        printf("Value in A register before performing restoration is : ");
        display_integer_binary_number_array(accumulator,MAX_BITS_SIZE);
        binary_addition(accumulator,M_divisor_binary,accumulator,MAX_BITS_SIZE);
    }


    printf("Value of A register at the end of this step is :  ");
    display_integer_binary_number_array(accumulator,MAX_BITS_SIZE);
    printf("Value of Q register at the end of this step is : ");
    display_integer_binary_number_array(Q_dividend_binary,MAX_BITS_SIZE);
    printf("===============================================================================\n");

    final_display_quotient_and_remainder(accumulator,Q_dividend_binary);

}


void left_shift_A_and_Q(int * ptr_to_A_accumulator , int * ptr_to_left_shifted_A_accumulator, int * ptr_to_Q_dividend, int * ptr_to_left_shifted_Q_dividend)
{
    // left shift A,Q
    left_shift(ptr_to_A_accumulator,ptr_to_left_shifted_A_accumulator,MAX_BITS_SIZE);
    for(int i=0;i<MAX_BITS_SIZE;i++)
    {
        ptr_to_A_accumulator[i] = ptr_to_left_shifted_A_accumulator[i];
    }

    ptr_to_A_accumulator[MAX_BITS_SIZE-1] = ptr_to_Q_dividend[0];

    left_shift(ptr_to_Q_dividend,ptr_to_left_shifted_Q_dividend,MAX_BITS_SIZE);
    for(int i=0;i<MAX_BITS_SIZE;i++)
    {
        ptr_to_Q_dividend[i] = ptr_to_left_shifted_Q_dividend[i];
    }
}


void final_display_quotient_and_remainder(int * ptr_to_A_accumulator , int * ptr_to_Q_dividend)
{
    printf("\n\nThe quotient that we got from the algorithm is : \n");
    display_integer_binary_number_array(ptr_to_Q_dividend,MAX_BITS_SIZE);

    printf("\nThe remainder that we got from the algorithm is : \n");
    display_integer_binary_number_array(ptr_to_A_accumulator,MAX_BITS_SIZE);

    int quotient,remainder;
    convert_positive_or_negative_binary_number_to_decimal(ptr_to_A_accumulator,&remainder,MAX_BITS_SIZE);
    convert_positive_or_negative_binary_number_to_decimal(ptr_to_Q_dividend,&quotient,MAX_BITS_SIZE);

    printf("\n\nConverting the binary form of quotient and remainder to decimal:\n\n");
    printf("Quotient = %d\n",quotient);
    printf("Remainder = %d\n",remainder);
    printf("\nThank You !\n");

}
