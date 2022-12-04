//
// Created by Aditya Ved on 04/12/22.
//

#include <stdio.h>
#include <stdlib.h>

void swap(int * ptr_to_array, int position1, int position2);

int main()
{
    printf("Enter the number of elements in the array : \n");
    int n;
    scanf("%d",&n);
    fflush(stdin);
    int array[n];

    for(int i=0;i<n;i++)
    {
        printf("Enter the value of %dth element :\n",i);
        int temp;
        scanf("%d",&temp);
        fflush(stdin);
        array[i]=temp;

    }


    for(int i=0;i<n-1;i++)
    {
        for(int j = 0;j<n-1-i;j++)
        {
            if(array[j]>array[j+1])
            {
                swap(array,j,j+1);
            }
        }
    }

    printf("The array after bubble sort is : \n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",array[i]);
    }
    printf("\n");
    return 0;
}

void swap(int * ptr_to_array, int position1, int position2)
{
    int temp = ptr_to_array[position1];
    ptr_to_array[position1] = ptr_to_array[position2];
    ptr_to_array[position2] = temp;

}
