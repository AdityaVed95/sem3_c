//
// Created by Aditya Ved on 21/11/22.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int input_array[] = {7,0,1,2,9,3,8,4,5};
    int block0[3];
    int block1[3];
    int block2[3];
    int counter1=0,counter2=0,counter3=0;

    for(int i=0;i<9;i++)
    {
        if(i%3 == 0)
        {
            block0[counter1] = input_array[i];
            counter1++;
        }
        else if(i%3 == 1)
        {
            block1[counter2] = input_array[i];
            counter2++;
        }

        else if(i%3 == 2)
        {
            block2[counter3] = input_array[i];
            counter3++;
        }

    }

    printf("Initial input in Main memory is : \n");
    for(int i=0;i<9;i++)
    {
        printf("%d\t",input_array[i]);
    }

    printf("\n\nFor Direct Mapping : \n");
    printf("Cache memory can hold : \n");
    for(int i=0;i<3;i++)
    {
        printf("Block %d : ",i);

        if(i==0)
        {
            for(int j=0;j<3;j++)
            {
                if(j==2)
                {
                    printf("%d ", block0[j]);
                }
                else
                {
                    printf("%d / ", block0[j]);
                }

            }
        }

        else if(i==1)
        {
            for(int j=0;j<3;j++)
            {
                if(j==2)
                {
                    printf("%d ", block1[j]);
                }
                else
                {
                    printf("%d / ", block1[j]);
                }
            }
        }

        else if(i==2)
        {
            for(int j=0;j<3;j++)
            {
                if(j==2)
                {
                    printf("%d ", block2[j]);
                }
                else
                {
                    printf("%d / ", block2[j]);
                }
            }
        }

        printf("\n");

    }

    printf("\nSample output of cache memory is : \n");
    for(int i =0;i<3;i++)
    {
        if(i==0)
        {
            printf("Block 0 : ");
            printf("%d\n", block0[0]);
        }
        else if(i==1)
        {
            printf("Block 1 : ");
            printf("%d\n", block1[2]);
        }
        else if(i ==2)
        {
            printf("Block 2 : ");
            printf("%d\n", block2[1]);
        }
    }


    printf("\n\n\nFor 2 way Set associative mapping : There are two sets of cache memory\n\n");


    printf("The 1st set (set0) can be : \n");

    for(int i=0;i<3;i++)
    {
        if(i==0)
        {
            printf("Block 0 : ");
            printf("%d\n",block0[1]);
        }
        else if(i==1)
        {
            printf("Block 1 : ");
            printf("%d\n",block1[1]);
        }
        else if(i==2)
        {
            printf("Block 2 : ");
            printf("%d\n",block2[2]);

        }

    }

    printf("\nThe 2nd set (set1) can be : \n");

    for(int i=0;i<3;i++)
    {
        if(i==0)
        {
            printf("Block 0 : ");
            printf("%d\n",block0[2]);
        }
        else if(i==1)
        {
            printf("Block 1 : ");
            printf("%d\n",block1[0]);
        }
        else if(i==2)
        {
            printf("Block 2 : ");
            printf("%d\n",block2[0]);

        }

    }

    printf("\n");
    return 0;
}