//
// Created by Aditya Ved on 04/12/22.
//

#include <stdio.h>
#include <stdlib.h>

void display_array(int * ptr_to_array, int n);

int main()
{
    printf("For Counting Sort :\nNote : assuming the elements in the input_array are in the range 0 to 9\n");

    printf("Enter the number of elements in the input_array : \n");
    int number_of_elements_in_input_array;
    scanf("%d",&number_of_elements_in_input_array);
    fflush(stdin);
    int input_array[number_of_elements_in_input_array];

    for(int i=0; i < number_of_elements_in_input_array; i++)
    {
        printf("Enter the value of %dth element :\n",i);
        int temp;
        scanf("%d",&temp);
        fflush(stdin);
        input_array[i]=temp;

    }

    printf("Input array : \n");
    display_array(input_array,number_of_elements_in_input_array);
    int number_of_elements_in_range = 10; // 0 to 9 is the range
    // thus all the elements in the input array will be in the range of 0 to 9

    int frequency_array[number_of_elements_in_range];
    for(int i=0;i<number_of_elements_in_range;i++)
    {
        frequency_array[i] = 0;
    }

    for(int i=0; i < number_of_elements_in_input_array; i++)
    {
        frequency_array[input_array[i]] += 1;
    }

    printf("Frequency array : \n");
    display_array(frequency_array, number_of_elements_in_range);

    int cumulative_array[number_of_elements_in_range];



    for(int i=0;i<number_of_elements_in_range;i++)
    {
        cumulative_array[i] = frequency_array[i];
    }

    for(int i=1;i<number_of_elements_in_range;i++)
    {
        cumulative_array[i] = cumulative_array[i] + cumulative_array[i-1];
    }

    printf("Cumulative array : \n");
    display_array(cumulative_array,number_of_elements_in_range);

    int right_shifted_cumulative_array[number_of_elements_in_range];
    right_shifted_cumulative_array[0] = 0;
    for(int i=0;i<number_of_elements_in_range-1;i++)
    {
        right_shifted_cumulative_array[i+1] = cumulative_array[i];
    }

    printf("Right Shifted Cumulative array : \n");
    display_array(right_shifted_cumulative_array,number_of_elements_in_range);

    int final_sorted_array[number_of_elements_in_input_array];

    for(int i=0;i<number_of_elements_in_input_array;i++)
    {
        int index = right_shifted_cumulative_array[input_array[i]];
        final_sorted_array[index] = input_array[i];
        right_shifted_cumulative_array[input_array[i]] += 1;
    }

    printf("Final Sorted array after performing counting sort algorithm : \n");
    display_array(final_sorted_array,number_of_elements_in_input_array);

    printf("\n");
    return 0;
}

void display_array(int * ptr_to_array, int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d\t",ptr_to_array[i]);
    }
    printf("\n\n");
}