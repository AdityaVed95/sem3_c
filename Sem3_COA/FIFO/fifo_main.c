//
// Created by Aditya Ved on 14/11/22.
//

#include <stdio.h>
#include <stdlib.h>

int is_container_full(int n, int * ptr_to_container);
void show_container(int number_of_elements_in_container, int * ptr_to_container);
void initialise_container(int * ptr_to_container,int n);

int main()
{
    printf("Enter the number of elements in the sequence \n");
    int number_of_elements;
    scanf("%d",&number_of_elements);
    fflush(stdin);

    int input_array[number_of_elements];

    for(int i=0;i<number_of_elements;i++)
    {
        printf("Enter the value of the %dth element\n",i);
        int temp;
        scanf("%d",&temp);
        fflush(stdin);
        input_array[i] = temp;

    }

    int container_size = 3;
    int container[container_size];
    initialise_container(container,container_size);

    int pointer_to_oldest_element = 0;

    for(int i=0; i<number_of_elements;i++)
    {
        printf("For element = %d : \n",input_array[i]);
        // if container is not full :
        // then add new element to the container:
        if(is_container_full(container_size,container) == 0)
        {
//            if(pointer_to_oldest_element == -1)
//            {
//                pointer_to_oldest_element++;
//                container[pointer_to_oldest_element] = input_array[i];
//            }
            container[i] = input_array[i];
            show_container(container_size,container);
            continue;
        }



        // if input_array[i] element is already present in the stack :
        // if hit has occurred :
        if(input_array[i] == container[0] || input_array[i] == container[1] || input_array[i] == container[2])
        {
            printf("Hit has occurred : the state of the container does not change.\n");
            show_container(container_size,container);

        }

        // if container is full and hit has not occurred : replace the oldest element
        else
        {
            printf("Container is full and hit has not occurred : \n");
            container[pointer_to_oldest_element] = input_array[i];
            if(pointer_to_oldest_element == container_size-1)
            {
                pointer_to_oldest_element = 0;
            }
            else
            {
                pointer_to_oldest_element++;
            }

            show_container(container_size,container);
        }


    }

    printf("Final state of the container at the end of the program is : \n");
    show_container(container_size,container);

    printf("\n");
    return 0;
}


int is_container_full(int n, int * ptr_to_container)
{
    // if stack is full then it will not contain -1
    // if there is an empty place in stack then it will contain -1

    for(int i = 0;i<n;i++)
    {
        if(ptr_to_container[i] == -1)
        {
            return 0;
        }

    }

    return 1;
}


void show_container(int number_of_elements_in_container, int * ptr_to_container)
{
    printf("State of container is : \n");
    for(int i = 0;i<number_of_elements_in_container;i++)
    {
        printf("%d\n",ptr_to_container[i]);
    }
}


void initialise_container(int * ptr_to_container,int n)
{
    for(int i=0;i<n;i++)
    {
        ptr_to_container[i] = -1;
    }
}