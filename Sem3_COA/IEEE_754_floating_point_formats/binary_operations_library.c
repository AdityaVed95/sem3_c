//
// Created by Aditya Ved on 12/09/22.
//

// MAX_BITS_SIZE is the number of bits on which the operation is to be performed

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// all the below functions are meant to deal with an array or any data structure in which data is stored in contiguous memory locations
// they were created with arrays in mind

void convert_positive_decimal_number_to_binary(int , int *,int );
void convert_negative_decimal_number_to_binary(int, int *,int); // uses twos_complement_trick function internally


void convert_positive_or_negative_binary_number_to_decimal(int *, int *, int );
int convert_positive_binary_number_to_decimal(int * , int);

void display_integer_binary_number_array(int *,int );

void converting_fractional_part_to_binary(float fractional_part,int * ptr_to_binary_number,int MAX_BITS_SIZE);

float given_fraction_part_of_number(float original_num);


void convert_positive_decimal_number_to_binary(int decimal_input, int * ptr_to_binary_number,int MAX_BITS_SIZE) // converts +ve nos to binary
{

    int quotient = 10, remainder; // 10 is just taken as a random number
    int copy_of_decimal_input = decimal_input;
    int i = MAX_BITS_SIZE - 1;

    while (quotient != 0)
    {
        quotient = copy_of_decimal_input / 2;
        remainder = copy_of_decimal_input % 2;
        *(ptr_to_binary_number + i) = remainder;
        copy_of_decimal_input = quotient;
        i--;
    }

    int k;
    for (k = i; k >= 0; k--)
    {
        *(ptr_to_binary_number + k) = 0;
    }
}




void twos_complement_trick(int * ptr_to_original_binary_number, int * ptr_to_twos_complement_of_binary_number, int MAX_BITS_SIZE)
{
    int i;
    int flag = 0;
    for(i=MAX_BITS_SIZE-1;i>=0;i--)
    {
        if(flag == 0)
        {
            if(*(ptr_to_original_binary_number+i) == 1)
            {
                *(ptr_to_twos_complement_of_binary_number+i) = 1;
                flag = 1;
            }
            else if (*(ptr_to_original_binary_number+i) == 0)
            {
                *(ptr_to_twos_complement_of_binary_number+i) = 0;
            }

        }

        else if (flag == 1)
        {
            if(*(ptr_to_original_binary_number+i) == 0)
            {
                *(ptr_to_twos_complement_of_binary_number+i) = 1;
            }

            else if (*(ptr_to_original_binary_number+i) == 1)
            {
                *(ptr_to_twos_complement_of_binary_number+i) = 0;
            }
        }
    }
}


void convert_negative_decimal_number_to_binary(int negative_num, int * ptr_to_binary_number, int MAX_BITS_SIZE )
{
    int positive_num = abs(negative_num);
    int binary_of_corresponding_positive_number[MAX_BITS_SIZE];
    convert_positive_decimal_number_to_binary(positive_num,&(binary_of_corresponding_positive_number[0]),MAX_BITS_SIZE);
    // now we have to find 2's complement of binary_of_corresponding_positive_number to get
    // the binary pattern of actual negative number
    twos_complement_trick(&(binary_of_corresponding_positive_number[0]),ptr_to_binary_number, MAX_BITS_SIZE);

}


void convert_positive_or_negative_binary_number_to_decimal(int *ptr_to_binary_number , int *ptr_to_decimal_number , int MAX_BITS_SIZE)
{
    if(*(ptr_to_binary_number) == 1)
    {
        // number is negative
        int binary_twos_complement_number[MAX_BITS_SIZE];
        twos_complement_trick(ptr_to_binary_number,&(binary_twos_complement_number[0]), MAX_BITS_SIZE);
        int positive_num = convert_positive_binary_number_to_decimal(binary_twos_complement_number,MAX_BITS_SIZE);
        int negative_num = -positive_num;
        *(ptr_to_decimal_number) = negative_num;
    }

    else
    {
        // number is positive
        *(ptr_to_decimal_number) = convert_positive_binary_number_to_decimal(ptr_to_binary_number,MAX_BITS_SIZE);

    }
}





int convert_positive_binary_number_to_decimal(int *ptr_to_binary_number , int MAX_BITS_SIZE)
{
    int count = (MAX_BITS_SIZE)-1;
    int sum=0;
    for(int i=0;i<MAX_BITS_SIZE;i++)
    {
        sum = sum + (pow(2,count)*(*(ptr_to_binary_number+i)));
        count--;
    }
    return sum;
}

void display_integer_binary_number_array(int *ptr_to_binary_number,int MAX_BITS_SIZE)
{
    for(int i=0;i<MAX_BITS_SIZE;i++)
    {
        printf("%d",ptr_to_binary_number[i]);
    }

}


void converting_fractional_part_to_binary(float fractional_part,int * ptr_to_binary_number,int MAX_BITS_SIZE)
{
    float num = fractional_part;
    int i=0;


    while(i<MAX_BITS_SIZE)
    {
        num = num * 2;

        if(num == 1)
        {
            ptr_to_binary_number[i] = 1;
            break;
        }


        if(num>1)
        {
            ptr_to_binary_number[i] = 1;
        }
        else
        {
            ptr_to_binary_number[i] = 0;
        }

        fractional_part = given_fraction_part_of_number(num);
        num = fractional_part;
        i++;

    }

    if(i == MAX_BITS_SIZE-1)
    {
        return;
    }

    else
    {
        for(int k=i+1;k<MAX_BITS_SIZE;k++)
        {
            ptr_to_binary_number[k] = 0;
        }
    }
}


float given_fraction_part_of_number(float original_num)
{
    int integer_part = original_num;
    float fractional_part = original_num - integer_part;
    return fractional_part;
}