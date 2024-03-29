//
// Created by Aditya Ved on 17/10/22.
//


//  Sem3_COA/IEEE_754_floating_point_formats/main.c

#include <stdio.h>
#include <stdlib.h>
#include "binary_operations_library.c"
#include <math.h>


int number_of_bits_for_integer_part_single_precision=12;
int number_of_bits_for_fractional_part_single_precision=11;
int number_of_bits_for_integer_part_double_precision=26;
int number_of_bits_for_fractional_part_double_precision=26;


void single_precision_calculate_and_print(int integer_part, float fractional_part, float original_number);
void double_precision_calculate_and_print(int integer_part, float fractional_part, float original_number);

int main()
{
    printf("Enter the number whose IEEE representation is needed\n");
    float number;
    scanf("%f",&number);
    fflush(stdin);

    int integer_part = number;
    float fractional_part = number - integer_part;

    single_precision_calculate_and_print(integer_part, fractional_part, number);
    double_precision_calculate_and_print(integer_part,fractional_part,number);

    printf("\n");
    return 0;
}

void single_precision_calculate_and_print(int integer_part, float fractional_part, float original_number)
{

    // note :
    // in case of negative numbers :
    // these inputs are -ve :
    // int integer_part, float fractional_part, float original_number

    printf("\nFor the 32 bit single precision : short real format : \n\n");
    int sign_bit;
    int exponent;

    if(original_number>=0)
    {
        sign_bit = 0;
    }
    else
    {
        sign_bit = 1;
    }


    int binary_of_integer_part [number_of_bits_for_integer_part_single_precision] ;
    int binary_of_fractional_part [number_of_bits_for_fractional_part_single_precision];

    if(original_number>=0)
    {
        convert_positive_decimal_number_to_binary(integer_part,binary_of_integer_part,number_of_bits_for_integer_part_single_precision);
        converting_fractional_part_to_binary(fractional_part,binary_of_fractional_part,number_of_bits_for_fractional_part_single_precision);
    }

    else
    {
        convert_positive_decimal_number_to_binary(-integer_part,binary_of_integer_part,number_of_bits_for_integer_part_single_precision);
        converting_fractional_part_to_binary(-fractional_part,binary_of_fractional_part,number_of_bits_for_fractional_part_single_precision);
    }


    printf("The Number in binary format is : ");

    if(original_number<0)
    {
        printf("-");
    }

    display_integer_binary_number_array(binary_of_integer_part,number_of_bits_for_integer_part_single_precision);
    printf(".");
    display_integer_binary_number_array(binary_of_fractional_part,number_of_bits_for_fractional_part_single_precision);



    int i;
    int pos;
    for(i=0;i<number_of_bits_for_integer_part_single_precision;i++)
    {
        if(binary_of_integer_part[i] == 1)
        {
            pos = i;
            break;
        }
    }

    exponent = number_of_bits_for_integer_part_single_precision-pos-1;


    int part1_size = pos+1;
    int part2_size = number_of_bits_for_integer_part_single_precision + number_of_bits_for_fractional_part_single_precision - pos - 1;


    int binary_part1[part1_size];
    int binary_part2[part2_size];
    // achieving part1.part2 in binary form


    for(i=0;i<=pos;i++)
    {
        binary_part1[i]=binary_of_integer_part[i];
    }

    int k=0;
    for(i=pos+1;i<number_of_bits_for_integer_part_single_precision;i++)
    {
        binary_part2[k] = binary_of_integer_part[i];
        k++;
    }
    for(i=0;i<number_of_bits_for_fractional_part_single_precision;i++)
    {
        binary_part2[k] = binary_of_fractional_part[i];
        k++;
    }

    printf("\nNormalised form is : ");

    if(original_number<0)
    {
        printf("-");
    }

    display_integer_binary_number_array(binary_part1,part1_size);
    printf(".");
    display_integer_binary_number_array(binary_part2,part2_size);
    printf("  X  2^%d\n",exponent);

    int biased_exponent = exponent + 127;

    int binary_biased_exponent [8];
    convert_positive_decimal_number_to_binary(biased_exponent,binary_biased_exponent,8);


    printf("The True Exponent for this number = %d \n",exponent);
    printf("The biased exponent for this number = %d\n\n",biased_exponent);


    printf("The Sign-Exponent-Mantissa Table for this number in 32 bit format is:\n");
    printf("%d-",sign_bit);
    display_integer_binary_number_array(binary_biased_exponent,8);
    printf("-");
    display_integer_binary_number_array(binary_part2,part2_size);
    printf("\n");

}


void double_precision_calculate_and_print(int integer_part, float fractional_part, float original_number)
{


    // note :
    // in case of negative numbers :
    // these inputs are -ve :
    // int integer_part, float fractional_part, float original_number

    printf("\nFor the 64 bit double precision : long real format : \n\n");
    int sign_bit;
    int exponent;

    if(original_number>=0)
    {
        sign_bit = 0;
    }
    else
    {
        sign_bit = 1;
    }


    int binary_of_integer_part [number_of_bits_for_integer_part_double_precision] ;
    int binary_of_fractional_part [number_of_bits_for_fractional_part_double_precision];

    if(original_number>=0)
    {
        convert_positive_decimal_number_to_binary(integer_part,binary_of_integer_part,number_of_bits_for_integer_part_double_precision);
        converting_fractional_part_to_binary(fractional_part,binary_of_fractional_part,number_of_bits_for_fractional_part_double_precision);
    }

    else
    {
        convert_positive_decimal_number_to_binary(-integer_part,binary_of_integer_part,number_of_bits_for_integer_part_double_precision);
        converting_fractional_part_to_binary(-fractional_part,binary_of_fractional_part,number_of_bits_for_fractional_part_double_precision);
    }


    printf("The Number in binary format is : ");

    if(original_number<0)
    {
        printf("-");
    }

    display_integer_binary_number_array(binary_of_integer_part,number_of_bits_for_integer_part_double_precision);
    printf(".");
    display_integer_binary_number_array(binary_of_fractional_part,number_of_bits_for_fractional_part_double_precision);



    int i;
    int pos;
    for(i=0;i<number_of_bits_for_integer_part_double_precision;i++)
    {
        if(binary_of_integer_part[i] == 1)
        {
            pos = i;
            break;
        }
    }

    exponent = number_of_bits_for_integer_part_double_precision-pos-1;


    int part1_size = pos+1;
    int part2_size = number_of_bits_for_integer_part_double_precision + number_of_bits_for_fractional_part_double_precision - pos - 1;


    int binary_part1[part1_size];
    int binary_part2[part2_size];
    // achieving part1.part2 in binary form


    for(i=0;i<=pos;i++)
    {
        binary_part1[i]=binary_of_integer_part[i];
    }

    int k=0;
    for(i=pos+1;i<number_of_bits_for_integer_part_double_precision;i++)
    {
        binary_part2[k] = binary_of_integer_part[i];
        k++;
    }
    for(i=0;i<number_of_bits_for_fractional_part_double_precision;i++)
    {
        binary_part2[k] = binary_of_fractional_part[i];
        k++;
    }

    printf("\nNormalised form is : ");

    if(original_number<0)
    {
        printf("-");
    }

    display_integer_binary_number_array(binary_part1,part1_size);
    printf(".");
    display_integer_binary_number_array(binary_part2,part2_size);
    printf("  X  2^%d\n",exponent);

    int biased_exponent = exponent + 1023;

    int binary_biased_exponent [11];
    convert_positive_decimal_number_to_binary(biased_exponent,binary_biased_exponent,11);


    printf("The True Exponent for this number = %d \n",exponent);
    printf("The biased exponent for this number = %d\n\n",biased_exponent);


    printf("The Sign-Exponent-Mantissa Table for this number in 64 bit format is:\n");
    printf("%d-",sign_bit);
    display_integer_binary_number_array(binary_biased_exponent,11);
    printf("-");
    display_integer_binary_number_array(binary_part2,part2_size);
    printf("\n");

}