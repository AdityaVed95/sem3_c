//
// Created by Aditya Ved on 18/11/22.
//

#include <stdio.h>
#include <stdlib.h>

void initialise_with_blank_spaces(int * ptr_to_array, int number_of_page_frames);
int is_physical_memory_full(int * ptr_to_physical_memory,int number_of_page_frames);
void show_physical_memory(int * ptr_to_physical_memory,int number_of_page_frames);
void identify_and_replace_least_recently_used_page(int * sequence_of_pages_from_virtual_memory, int number_of_page_frames , int j , int * ptr_to_physical_memory);
int does_array_contain_this_element(int element, int size_of_array, int * ptr_to_array);

int main()
{
    printf("Note : Empty space is represented by -1\n");
    printf("Enter the number of elements in the sequence_of_pages_requested_by_the_processor\n");
    int number_of_pages_requested_by_the_processor;
    scanf("%d",&number_of_pages_requested_by_the_processor);
    fflush(stdin);

    int sequence_of_pages_requested_by_the_processor[number_of_pages_requested_by_the_processor]; // this is the sequence in which pages are requested by the processor.

    for(int i=0; i < number_of_pages_requested_by_the_processor; i++)
    {
        printf("Enter the value of the %dth element\n",i);
        int temp;
        scanf("%d",&temp);
        fflush(stdin);
        sequence_of_pages_requested_by_the_processor[i] = temp;

    }

    int number_of_page_frames = 3;
    int physical_memory[number_of_page_frames];
    initialise_with_blank_spaces(physical_memory, number_of_page_frames);
    double number_of_hits=0;
    int counter = 0;

    for(int i = 0; i < number_of_pages_requested_by_the_processor; i++)
    {
        printf("For the element %d : \n", sequence_of_pages_requested_by_the_processor[i]);

        // if the page is already present in the physical memory :
        if(sequence_of_pages_requested_by_the_processor[i] == physical_memory[0] || sequence_of_pages_requested_by_the_processor[i] == physical_memory[1] || sequence_of_pages_requested_by_the_processor[i] == physical_memory[2])
        {
            number_of_hits++;
            printf("A hit has occurred !!! The state of physical memory remains unchanged \n");
            show_physical_memory(physical_memory,number_of_page_frames);
            continue;
        }

        // if physical memory is not full and a hit has not occurred:
        if(is_physical_memory_full(physical_memory,number_of_page_frames) == 0)
        {
            physical_memory[counter] = sequence_of_pages_requested_by_the_processor[i];
            show_physical_memory(physical_memory,number_of_page_frames);
            counter++;
            continue;
        }


        else
        {
            // if the physical memory is full and a hit has not occurred :
            identify_and_replace_least_recently_used_page(sequence_of_pages_requested_by_the_processor, number_of_page_frames, i, physical_memory);
            show_physical_memory(physical_memory,number_of_page_frames);
        }


    }

    printf("Thus finally  : \n");
    show_physical_memory(physical_memory,number_of_page_frames);

    printf("The number of hits obtained : %lf \n",number_of_hits);
    printf("The number of attempts or (pages from virtual memory) are : %d", number_of_pages_requested_by_the_processor);

    double hit_ratio = number_of_hits / number_of_pages_requested_by_the_processor;
    printf("\nThe hit ratio = number of hits obtained / number of attempts \n");
    printf("Thus the hit ratio for LRU Page replacement algorithm is : %lf",hit_ratio);

    printf("\n");
    return 0;
}

void initialise_with_blank_spaces(int * ptr_to_array, int number_of_page_frames)
{
    for(int i=0;i<number_of_page_frames;i++)
    {
        ptr_to_array[i] = -1;
    }
}


int is_physical_memory_full(int * ptr_to_physical_memory,int number_of_page_frames)
{
    // returns 0 if the physical memory is not full
    // returns 1 if the physical memory is full
    for(int i=0;i<number_of_page_frames;i++)
    {
        if(ptr_to_physical_memory[i] == -1)
        {
            return 0;
        }
    }

    return 1;
}

void show_physical_memory(int * ptr_to_physical_memory,int number_of_page_frames)
{
    printf("State of physical memory is : \n");
    for(int i = 0;i<number_of_page_frames;i++)
    {
        printf("%d\n",ptr_to_physical_memory[i]);
    }
}

void identify_and_replace_least_recently_used_page(int * sequence_of_pages_from_virtual_memory , int number_of_page_frames , int j , int * ptr_to_physical_memory)
{
    // j is the index number of the page (in the sequence_of_pages_from_virtual_memory)  to be placed in the physical memory
    //
    int recents_list[number_of_page_frames];
    initialise_with_blank_spaces(recents_list,number_of_page_frames);
    int counter=0;

    // finding the page that should be replaced :
    for(int i=j-1;i>=0;i--)
    {
        // if(ptr_to_physical_memory[i] ) // is in recents then go behind
        if(does_array_contain_this_element(sequence_of_pages_from_virtual_memory[i],number_of_page_frames,recents_list))
        {
            continue;
        }

        else
        {
            recents_list[counter] = sequence_of_pages_from_virtual_memory[i];
            counter++;
            if(counter == number_of_page_frames)
            {
                break;
            }
        }
    }

    // element to be replaced : recents_list[number_of_page_frames-1]

    // replacing the page
    for(int i= 0 ;i<number_of_page_frames;i++)
    {
        if(ptr_to_physical_memory[i] == recents_list[number_of_page_frames-1])
        {
            ptr_to_physical_memory[i] = sequence_of_pages_from_virtual_memory[j];
        }
        else
        {
            continue;
        }
    }



}

int does_array_contain_this_element(int element, int size_of_array, int * ptr_to_array)
{
    for(int i=0;i<size_of_array;i++)
    {
        if(ptr_to_array[i] == element)
        {
            return 1;
        }

    }

    return 0;

}