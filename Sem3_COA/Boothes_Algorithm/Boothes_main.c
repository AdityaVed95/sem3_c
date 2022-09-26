//
// Created by Aditya Ved on 11/09/22.
//

// Sem3_COA/Boothes_main.c

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int MAX_BITS_SIZE=4; // this number determines the number of bits taken to represent any signed number in this program

void convert_positive_decimal_number_to_binary(int, int *);
void convert_negative_decimal_number_to_binary(int, int *);
void twos_complement(int *, int *);
void binary_addition(int * , int *, int *);
void ones_complement(int * , int * );
int right_shift(int *,int *);
void right_shift_boothes(int *, int * , int * );
void add_multiplicand_and_do_right_shift_boothes(int *, int * , int * , int *);
void subtract_multiplicand_and_do_right_shift_boothes(int *, int * , int * , int *);
void binary_subtraction(int *, int * , int *);
// the below two functions have been tailored according to the use case , use them wisely otherwise
void convert_positive_or_negative_binary_number_to_decimal(int *, int *);
int convert_positive_binary_number_to_decimal(int *);
void twos_complement_for_final_ans(int *, int *);
void ones_complement_for_final_ans(int * , int *);
void binary_addition_for_final_ans(int * , int *, int *);

int main()
{
    printf("\n\n\t\tWelcome to Boothes Algorithm for SIGNED multiplication\n");
    printf("\nEnter the Integer numbers from -128 to +127 only inorder to multiply them\n\n");


    // taking input of numbers
    printf("Enter 1st number : Multiplicand\n");
    fflush(stdout);
    int M_multiplicand,Q_multiplier;
    scanf("%d",&M_multiplicand);
    fflush(stdin);
    printf("Enter 2nd number : Multiplier\n");
    fflush(stdout);
    scanf("%d",&Q_multiplier);
    fflush(stdin);

    // d*r = m*q

    int M_multiplicand_binary_number1 [MAX_BITS_SIZE];
    int Q_multiplier_binary_number2 [MAX_BITS_SIZE];

    if (M_multiplicand >= 0)
    {
        convert_positive_decimal_number_to_binary(M_multiplicand, &(M_multiplicand_binary_number1[0]));
    }
    else
    {
        convert_negative_decimal_number_to_binary(M_multiplicand, &(M_multiplicand_binary_number1[0]));
    }

    if (Q_multiplier >= 0)
    {
        convert_positive_decimal_number_to_binary(Q_multiplier, &(Q_multiplier_binary_number2[0]));
    }
    else
    {
        convert_negative_decimal_number_to_binary(Q_multiplier, &(Q_multiplier_binary_number2[0]));
    }

    printf("Binary pattern of input : \n");
    printf("binary of M_multiplicand :  ");
    for(int i = 0;i<MAX_BITS_SIZE;i++)
    {
        printf("%d", M_multiplicand_binary_number1[i]);
    }
    printf("\nbinary of Q_multiplier :  ");
    for(int i = 0;i<MAX_BITS_SIZE;i++)
    {
        printf("%d", Q_multiplier_binary_number2[i]);
    }
    fflush(stdout);
    printf("\n");
    // now the actual logic of boothes algorithm starts

    int Accumulator[MAX_BITS_SIZE];
    for(int i = 0 ;i<MAX_BITS_SIZE;i++)
    {
        Accumulator[i] = 0;
    }

    int Q_minus1 = 0;

    int count = MAX_BITS_SIZE;

    while (count != 0)
    {
        if(Q_multiplier_binary_number2[MAX_BITS_SIZE-1] == Q_minus1)
        {
            right_shift_boothes(&(Accumulator[0]),&(Q_multiplier_binary_number2[0]),&(Q_minus1));

        }

        else if(Q_multiplier_binary_number2[MAX_BITS_SIZE-1] == 0)
        {

            add_multiplicand_and_do_right_shift_boothes(&(Accumulator[0]),&(Q_multiplier_binary_number2[0]),&(M_multiplicand_binary_number1[0]),&(Q_minus1));
            // add multiplicand to A
            // perform right shift
        }

        else if(Q_multiplier_binary_number2[MAX_BITS_SIZE-1] == 1)
        {
            subtract_multiplicand_and_do_right_shift_boothes(&(Accumulator[0]),&(Q_multiplier_binary_number2[0]),&(M_multiplicand_binary_number1[0]),&(Q_minus1));
            // do : A-M
            // perform right shift
        }

        count --;
    }

    printf("Ans of Boothes algorithm in binary form is : \n");
    for (int i = 0; i < MAX_BITS_SIZE; ++i)
    {
        printf("%d",Accumulator[i]);
    }
    for (int i = 0; i < MAX_BITS_SIZE; ++i)
    {
        printf("%d",Q_multiplier_binary_number2[i]);
    }

    int final_ans_binary[2 * MAX_BITS_SIZE];
    // 0 to 7
    int i;
    for (i = 0; i < MAX_BITS_SIZE; i++)
    {
        final_ans_binary[i] = Accumulator[i];
    }
    // 8 to 15
    // i = 8
    count = 0;
    while (i<(2*MAX_BITS_SIZE))
    {
        final_ans_binary[i] = Q_multiplier_binary_number2[count];
        count++;
    }


    printf("Converting Binary output to decimal : \n");
    int final_ans_decimal;
    convert_positive_or_negative_binary_number_to_decimal(&(final_ans_binary[0]),&final_ans_decimal);
    printf("Final ans in decimal is : \n");
    printf("%d",final_ans_decimal);
    printf("\n");
    return 0;
}

// this function is for dealing with a binary number of size = MAX_BITS_SIZE

// #working
void convert_positive_decimal_number_to_binary(int decimal_input, int * ptr_to_binary_number) // converts +ve nos to binary
{
    int quotient=10,remainder; // 10 is just taken as a random number
    int copy_of_decimal_input= decimal_input;
    int i=MAX_BITS_SIZE-1;

    while (quotient != 0)
    {
        quotient=copy_of_decimal_input/2;
        remainder = copy_of_decimal_input%2;
        *(ptr_to_binary_number+i) = remainder;
        copy_of_decimal_input = quotient;
        i--;
    }
    int k;
    for(k=i;k>=0;k--)
    {
        *(ptr_to_binary_number+k) = 0;
    }
}

// #working
void convert_negative_decimal_number_to_binary(int negative_num, int * ptr_to_binary_number)
{
    int positive_num = abs(negative_num);
    int binary_of_corresponding_positive_number[MAX_BITS_SIZE];
    convert_positive_decimal_number_to_binary(positive_num,&(binary_of_corresponding_positive_number[0]));
    // now we have to find 2's complement of binary_of_corresponding_positive_number to get
    // the binary pattern of actual negative number
    twos_complement(&(binary_of_corresponding_positive_number[0]),ptr_to_binary_number);

}

// #working
void twos_complement(int * ptr_to_original_binary_number, int * ptr_to_twos_complement_of_binary_number)
{
    int binary_of_ones_complement_of_original_binary_number[MAX_BITS_SIZE];
    ones_complement(ptr_to_original_binary_number,&(binary_of_ones_complement_of_original_binary_number[0]));

//    int binary_2nd_no_added[] = {0,0,0,0,0,0,0,1};
    int binary_2nd_no_added[MAX_BITS_SIZE];
    for (int i = 0; i < MAX_BITS_SIZE-1; ++i)
    {
        binary_2nd_no_added[i]=0;
    }
    binary_2nd_no_added[MAX_BITS_SIZE-1] = 1;

    binary_addition(&(binary_of_ones_complement_of_original_binary_number[0]),&(binary_2nd_no_added),ptr_to_twos_complement_of_binary_number);

}


void twos_complement_for_final_ans(int * ptr_to_original_binary_number, int * ptr_to_twos_complement_of_binary_number)
{
    int binary_of_ones_complement_of_original_binary_number[2*MAX_BITS_SIZE];
    ones_complement_for_final_ans(ptr_to_original_binary_number,&(binary_of_ones_complement_of_original_binary_number[0]));

//    int binary_2nd_no_added[] = {0,0,0,0,0,0,0,1};
    int binary_2nd_no_added[2*MAX_BITS_SIZE];
    for (int i = 0; i < (2*MAX_BITS_SIZE)-1; ++i)
    {
        binary_2nd_no_added[i]=0;
    }
    binary_2nd_no_added[(2*MAX_BITS_SIZE)-1] = 1;

    binary_addition_for_final_ans(&(binary_of_ones_complement_of_original_binary_number[0]),&(binary_2nd_no_added),ptr_to_twos_complement_of_binary_number);


}


// #working
void binary_addition(int * ptr_to_1st_binary_number,int * ptr_to_2nd_binary_number , int * ptr_to_final_sum)
{
    int i;
    int carry=0;
    int bit1,bit2;
    int sum;


    // simulating serial adder containing n number of 1 bit full adder
    // n = MAX_BITS_SIZE

    for(i=MAX_BITS_SIZE-1;i>=0;i--)
    {
        bit1 = *(ptr_to_1st_binary_number+i);
        bit2 = *(ptr_to_2nd_binary_number+i);

        // algorithms for 1 bit full adder
        // algorithm for sum
        if( (bit1 == 1 && bit2 == 1 && carry == 1) || (bit1 == 1 && bit2 == 0 && carry == 0) || (bit1 == 0 && bit2 == 1 && carry == 0) || (bit1 == 0 && bit2 == 0 && carry == 1))
        {
            sum = 1;
            *(ptr_to_final_sum+i) = sum;
        }
        else
        {
            sum = 0;
            *(ptr_to_final_sum+i) = sum;
        }

        // algorithm for carry
        if((bit1 == 1 && bit2 == 1)  ||  (bit1 == 1 && carry == 1)  ||  (bit2 == 1 && carry == 1))
        {
            carry = 1;
        }
        else
        {
            carry = 0;
        }
    }

//    printf("Carry is : %d\n",carry);
//    the carry generated in the last step has to be ignored because there is no space left in the array to accomodate it , and thus it is not significant

}


void binary_addition_for_final_ans(int * ptr_to_1st_binary_number,int * ptr_to_2nd_binary_number , int * ptr_to_final_sum)
{
    int i;
    int carry=0;
    int bit1,bit2;
    int sum;


    // simulating serial adder containing n number of 1 bit full adder
    // n = MAX_BITS_SIZE

    for(i=2*MAX_BITS_SIZE-1;i>=0;i--)
    {
        bit1 = *(ptr_to_1st_binary_number+i);
        bit2 = *(ptr_to_2nd_binary_number+i);

        // algorithms for 1 bit full adder
        // algorithm for sum
        if( (bit1 == 1 && bit2 == 1 && carry == 1) || (bit1 == 1 && bit2 == 0 && carry == 0) || (bit1 == 0 && bit2 == 1 && carry == 0) || (bit1 == 0 && bit2 == 0 && carry == 1))
        {
            sum = 1;
            *(ptr_to_final_sum+i) = sum;
        }
        else
        {
            sum = 0;
            *(ptr_to_final_sum+i) = sum;
        }

        // algorithm for carry
        if((bit1 == 1 && bit2 == 1)  ||  (bit1 == 1 && carry == 1)  ||  (bit2 == 1 && carry == 1))
        {
            carry = 1;
        }
        else
        {
            carry = 0;
        }
    }

//    printf("Carry is : %d\n",carry);
//    the carry generated in the last step has to be ignored because there is no space left in the array to accomodate it , and thus it is not significant

}


// #working
void ones_complement(int * ptr_to_binary_number, int * ptr_to_ones_complement_of_binary_number)
{
    int i;
    for(i=0;i<MAX_BITS_SIZE;i++)
    {
        if(*(ptr_to_binary_number+i) == 0)
        {
            *(ptr_to_ones_complement_of_binary_number+i) = 1;
        }

        if(*(ptr_to_binary_number+i) == 1)
        {
            *(ptr_to_ones_complement_of_binary_number+i) = 0;
        }
    }
}

void ones_complement_for_final_ans(int * ptr_to_binary_number, int * ptr_to_ones_complement_of_binary_number)
{
    int i;
    for(i=0;i<2*MAX_BITS_SIZE;i++)
    {
        if(*(ptr_to_binary_number+i) == 0)
        {
            *(ptr_to_ones_complement_of_binary_number+i) = 1;
        }

        if(*(ptr_to_binary_number+i) == 1)
        {
            *(ptr_to_ones_complement_of_binary_number+i) = 0;
        }
    }
}

// #working
int right_shift(int *ptr_to_binary_number, int * ptr_to_right_shifted_binary_number)
{

    ptr_to_right_shifted_binary_number[0] = ptr_to_binary_number[0];
    for(int i=0;i<MAX_BITS_SIZE-1;i++)
    {
        ptr_to_right_shifted_binary_number[i + 1] = ptr_to_binary_number[i];
    }
    return ptr_to_binary_number[MAX_BITS_SIZE-1];
    // this function return the right most bit which is not going to be in the right_shifted_binary_number

}

// #working
void right_shift_boothes(int * ptr_to_accumulator_binary_number, int * ptr_to_multiplier_binary_number, int * ptr_to_Qminus1_decimal_number)
{
    int right_shifted_accumulator[MAX_BITS_SIZE];
    int extra_bit_from_accumulator = right_shift(ptr_to_accumulator_binary_number,&(right_shifted_accumulator[0]));
    for(int i=0;i<MAX_BITS_SIZE;i++)
    {
        ptr_to_accumulator_binary_number[i] = right_shifted_accumulator[i];
    }

    int right_shifted_multiplier[MAX_BITS_SIZE];
    int extra_bit_from_multiplier = right_shift(ptr_to_multiplier_binary_number,&(right_shifted_multiplier[0]));
    for(int i = 0 ; i<MAX_BITS_SIZE;i++)
    {
        ptr_to_multiplier_binary_number[i] = right_shifted_multiplier[i];
    }

    ptr_to_multiplier_binary_number[0] = extra_bit_from_accumulator;
    *(ptr_to_Qminus1_decimal_number) = extra_bit_from_multiplier;

}


// #working
void add_multiplicand_and_do_right_shift_boothes(int * ptr_to_accumulator_binary_number, int * ptr_to_multiplier_binary_number, int * ptr_to_multiplicand_binary_number, int * ptr_to_Qminus1_decimal_number)
{
    int sum[MAX_BITS_SIZE];
    binary_addition(ptr_to_accumulator_binary_number,ptr_to_multiplicand_binary_number,&(sum[0]));
    for (int i = 0; i < MAX_BITS_SIZE; ++i)
    {
        ptr_to_accumulator_binary_number[i] = sum[i];
    }
    right_shift_boothes(ptr_to_accumulator_binary_number,ptr_to_multiplier_binary_number,ptr_to_Qminus1_decimal_number);

}

// #working
void subtract_multiplicand_and_do_right_shift_boothes(int * ptr_to_accumulator_binary_number, int * ptr_to_multiplier_binary_number, int * ptr_to_multiplicand_binary_number, int * ptr_to_Qminus1_decimal_number)
{
    int diff[MAX_BITS_SIZE];
    binary_subtraction(ptr_to_accumulator_binary_number,ptr_to_multiplicand_binary_number,&(diff[0]));

    for (int i = 0; i < MAX_BITS_SIZE; ++i)
    {
        ptr_to_accumulator_binary_number[i] = diff[i];
    }
    right_shift_boothes(ptr_to_accumulator_binary_number,ptr_to_multiplier_binary_number,ptr_to_Qminus1_decimal_number);

}

// #working
void binary_subtraction(int * ptr_to_1st_binary_number, int *ptr_to_2nd_binary_number , int *ptr_to_difference_binary_number)
{
    // difference_binary_number store  1st_binary_number - 2nd_binary_number
    // 1st bin is accumulator
    // 2nd bin is multiplicand
    int twos_complement_of_2nd_binary_number[MAX_BITS_SIZE];
    twos_complement(ptr_to_2nd_binary_number,&(twos_complement_of_2nd_binary_number[0]));
    // here the twos_complement_of_2nd_binary_number actually holds the value of 2's complement
    // of 2nd binary number

    binary_addition(ptr_to_1st_binary_number,&(twos_complement_of_2nd_binary_number[0]),ptr_to_difference_binary_number);

}

// this is for 16 bit numbers
void convert_positive_or_negative_binary_number_to_decimal(int *ptr_to_binary_number , int *ptr_to_decimal_number)
{
    if(*(ptr_to_binary_number) == 1)
    {
        // number is -ve
        int binary_twos_complement_number[2*MAX_BITS_SIZE];
        twos_complement_for_final_ans(ptr_to_binary_number,&(binary_twos_complement_number[0]));
        int positive_num = convert_positive_binary_number_to_decimal(binary_twos_complement_number);
        int negative_num = -positive_num;
        *(ptr_to_decimal_number) = negative_num;
    }

    else
    {
        // number is positive
        *(ptr_to_decimal_number) = convert_positive_binary_number_to_decimal(ptr_to_binary_number);

    }
}

// this is for 16 bit numbers
int convert_positive_binary_number_to_decimal(int *ptr_to_binary_number)
{
    int count = 2*(MAX_BITS_SIZE)-1;
    int sum=0;
    for(int i=0;i<2*MAX_BITS_SIZE;i++)
    {
        sum = sum + (pow(2,count)*(*(ptr_to_binary_number+i)));
        count--;
    }
    return sum;
}