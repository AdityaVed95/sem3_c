//
// Created by Aditya Ved on 11/09/22.
//

// Sem3_COA/binary_test1.c

#include <stdio.h>
#include <stdlib.h>
#include "boothes_version2/boothes_version2.c"


int main()
{
//    int num = 5;
//    int binary1 [MAX_BITS_SIZE];
//    convert_positive_decimal_number_to_binary(num,&(binary1[0]));
//
//    int i;
//    for(i=0;i<MAX_BITS_SIZE;i++)
//    {
//        printf("%d",binary1[i]);
//    }
//
//    printf("\n%d\n",(0%2));
//
//    printf("%d\n",(abs(-9)));
//    printf("%d\n",~10);
//
//    int binary_of_ones_complement[MAX_BITS_SIZE];
//    ones_complement(&(binary1[0]),&(binary_of_ones_complement[0]));
//
//    for(int j = 0; j < MAX_BITS_SIZE; ++j)
//    {
//        printf("%d",*(binary_of_ones_complement+j));
//    }
//    printf("\n");
//
//    int bit1 = 1;
//    int bit2 = 0;
//    int carry = 0;
//
//    if(bit1 == 1 && bit2 == 0 && carry == 0 )
//    {
//        printf("yes\n");
//    }
//    else
//    {
//        printf("No\n");
//    }
//
//    int binary_num1[] = {0,0,1,1,0,1,0,1};
//    int binary_num2[] = {1,1,1,0,0,0,0,1};
//    int binary_sum[MAX_BITS_SIZE];
//    binary_addition(&(binary_num1[0]),&(binary_num2[0]),&(binary_sum[0]));
//    for(i=0;i<MAX_BITS_SIZE;i++)
//    {
//        printf("%d",binary_sum[i]);
//    }

//    int binary_num1[] = {0,0,0,1,1,1,1,0};
//    int binary_twos_complement[MAX_BITS_SIZE];
//    twos_complement(&(binary_num1[0]),&(binary_twos_complement[0]));
//    for (int i = 0; i < MAX_BITS_SIZE; ++i)
//    {
//        printf("%d",binary_twos_complement[i]);
//    }

//    int binary_num1[] = {0,1,0,0,1,0,1,1};
//    int right_shifted[MAX_BITS_SIZE];
//    int extra_bit = right_shift(&(binary_num1[0]),&(right_shifted[0]));
//    printf("Extra bit is : %d\n",extra_bit);
//    for (int i = 0; i < MAX_BITS_SIZE; ++i)
//    {
//        printf("%d",right_shifted[i]);
//    }
//
//    int accumulator[] = {1,1,0,1,0,1,1,1};
//    int multiplier[] = {0,0,1,0,1,1,0,1};
//    int multiplicand[] = {1,0,1,1,0,0,1,0};
//    int Q_minus1 = 0;
//    int i;
////    right_shift_boothes(&(accumulator[0]),&(multiplier[0]),&(Q_minus1));
//
//    //add_multiplicand_and_do_right_shift_boothes(accumulator,multiplier,multiplicand,&Q_minus1);
//    subtract_multiplicand_and_do_right_shift_boothes(accumulator,multiplier,multiplicand,&(Q_minus1));
//
//
//    printf("New accumulator is : \n");
//    for(i = 0; i < MAX_BITS_SIZE; ++i)
//    {
//        printf("%d",accumulator[i]);
//    }
//
//    printf("\nNew multiplier is : \n");
//    for(i = 0; i < MAX_BITS_SIZE; ++i)
//    {
//        printf("%d",multiplier[i]);
//    }
//
//    printf("\nQ minus1  is : %d",Q_minus1);

//    int bin1[] ={0,0,0,0,1,0,1,0};
//    int bin2[] = {0,0,0,0,1,1,1,1};
//    int bin2_negative[] = {1,1,1,1,1,0,1,1};
//    int diff[MAX_BITS_SIZE];
//
//    binary_subtraction(bin1,bin2,diff);
//    printf("diff is : \n");
//    for (int i = 0; i < MAX_BITS_SIZE; ++i)
//    {
//        printf("%d",diff[i]);
//    }
//
//    int x = 100;
//    int y = -x;
//    printf("y is : %d\n",y);

    int binary_num[] = {0,0,1,0,1,0,0,0,1,0,1,1,0,0,0,0,};
    int two_complement[2*MAX_BITS_SIZE];
    twos_complement_trick(&(binary_num[0]),&(two_complement[0]));
    for (int i = 0; i < 2*MAX_BITS_SIZE-1; ++i)
    {
        printf("%d",two_complement[i]);
    }
    printf("\n");
    return 0;
}


//