//
// Created by Aditya Ved on 18/08/22.
//



#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the number of elements to be allocated in the heap memory\n");
    scanf("%d",&n);
    fflush(stdin);

    int *ptr_int = (int *)malloc(n*sizeof (int ));

    printf("Enter the elements(except zero) to be stored in the heap memory\n");
    int i;
    for(i=0;i<n;i++)
    {
        printf("Enter value of %dth element \n",(i+1));
        fflush(stdout);
        scanf("%d",(ptr_int+i));
        fflush(stdin);
    }


    printf("Enter the element whose first occurrence is to be removed from the heap memory and then do the resizing of heap memory\n");
    int remove_me;
    scanf("%d",&remove_me);
    fflush(stdin);



    //*(ptr_int+2) = 0;
    int position;

    for(i=0;i<n;i++)
    {
        if(remove_me == *(ptr_int+i))
        {
            position = i;
            break;
        }
    }

    *(ptr_int+position)= 0;


    int new_number_of_elements=n-1;
//
//    for(i=0;i<n;i++)
//    {
//        if(*(ptr_int+i) == 0)
//        {
//            continue;
//        }
//        else
//        {
//            new_number_of_elements++;
//        }
//    }



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

    free(ptr_new_int);


    printf("\n");
    return 0;
}