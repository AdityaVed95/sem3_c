//
// Created by Aditya Ved on 18/08/22.
//

#include <stdio.h>

int main()
{
    int arr1[] = {15,25,35,45};
    int size = 4;

    int arr2[4];

    int i;

    for(i=size-1;i>=0;i--)
    {
        arr2[size-(i+1)] = arr1[i];
    }

    printf("Array 2 is : \n");

    for (i=0;i<size;i++)
    {
        printf("%d\t",arr2[i]);
    }


    return 0;
}
