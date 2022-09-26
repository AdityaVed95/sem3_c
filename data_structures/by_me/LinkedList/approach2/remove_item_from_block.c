//
// Created by Aditya Ved on 17/08/22.
//


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 4;
    int *ptr_int = (int *)malloc(n*sizeof (int ));
    *ptr_int= 15;
    *(ptr_int+1) = 25;
    *(ptr_int+2) = 35;
    *(ptr_int+3) = 45;

    // now we want to remove 35 from block of memory

    *(ptr_int+2) = 0;

    int i;
    int new_number_of_elements=0;

    for(i=0;i<n;i++)
    {
        if(*(ptr_int+i) == 0)
        {
            continue;
        }
        else
        {
            new_number_of_elements++;
        }
    }

    int array_int1[new_number_of_elements];
    int counter=0;

    for(i=0;i<n;i++)
    {
        if(*(ptr_int+i) == 0)
        {
            continue;
        }
        else
        {
            array_int1[counter] = *(ptr_int+i);
            counter++;
        }
    }

    free(ptr_int);

    int *ptr_new_int = (int *) malloc(new_number_of_elements*sizeof (int ));

    for(i=0;i<new_number_of_elements;i++)
    {
        *(ptr_new_int+i)=array_int1[i];
    }

    printf("The new allocated block of memory is : \n");

    for(i=0;i<new_number_of_elements;i++)
    {
        printf("%d\n",*(ptr_new_int+i));
    }




    printf("\n");
    return 0;
}