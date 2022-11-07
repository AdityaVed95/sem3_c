//
// Created by Aditya Ved on 27/10/22.
//

#include <stdio.h>
#include <stdlib.h>

// assuming initially that the hashing table is empty and all elements are initialised to 0
// assuming input of zero is not allowed in the hashing table.
// if the value of an element in the hashing table is zero then that place is considered to be empty .




int insert_data_in_hashing_table(int data , int number_of_elements , int * ptr_to_hashing_table);
int hash_function(int data,int number_of_elements);
int handle_collision_and_display_hashing_table(int data , int number_of_elements , int * ptr_to_hashing_table , int index);
int is_hashing_table_full(int * ptr_to_hashing_table , int number_of_elements);
void search_empty_place_after_collision_and_insert_in_hashing_table(int data , int number_of_elements , int * ptr_to_hashing_table , int index);
void display_hashing_table(int number_of_elements , int * ptr_to_hashing_table );
int searching_in_hashing_table(int element_to_be_searched , int number_of_elements , int * ptr_to_hashing_table);

int main()
{
    int number_of_elements;
    printf("Enter the size of the hashing table : \n");
    scanf("%d",&number_of_elements);
    fflush(stdin);

    // creating hashing table
    int hashing_table[number_of_elements];

    // initialising hashing table
    for(int i = 0 ; i<number_of_elements; i++)
    {
        hashing_table[i] = 0;
    }

    int dummy = 1;
    while(dummy == 1)
    {
        printf("Enter 1 to insert an element in the hashing table\n");
        printf("Enter 2 to exit the insertion of elements\n");

        int response;
        scanf("%d",&response);
        fflush(stdin);

        if(response == 1)
        {
            printf("Enter the data to be inserted in the hashing table \n");
            int data;
            scanf("%d",&data);
            fflush(stdin);
            int ans = insert_data_in_hashing_table(data, number_of_elements, hashing_table);

            if(ans == 0)
            {
                break;
            }

        }

        else if(response == 2)
        {
            break;
        }

        else
        {
            printf("Invalid input, please try again.\n");
        }

    }

    while(dummy == 1)
    {
        printf("Enter 1 to search the occurrence of given element in the hashing table\n");
        printf("Enter 2 to exit\n");
        int response;
        scanf("%d",&response);
        fflush(stdin);

        if(response == 1)
        {
            printf("Enter the data to be searched in the hashing table \n");
            int data;
            scanf("%d",&data);
            fflush(stdin);
            int ans = searching_in_hashing_table(data,number_of_elements,hashing_table);
            if(ans == -1)
            {
                printf("Element not found in hashing table !!!\n");
            }
            else
            {
                printf("Element found at %dth index (zero based) of the hashing table\n",ans);
            }

        }

        else if(response == 2)
        {
            break;
        }

        else
        {
            printf("Invalid input, please try again.\n");
        }


    }


    printf("Program ended!!\n");
    printf("\n");
    return 0;
}

int insert_data_in_hashing_table(int data, int number_of_elements, int * ptr_to_hashing_table)
{
    // returns 1 if data got inserted
    // returns 0 if hashing table was full and data cannot be inserted

    int index = hash_function(data,number_of_elements);

    if(ptr_to_hashing_table[index] == 0) // collision did not occur
    {
        printf("No collision occurred, inserted %d at %dth index of the hashing table\n",data,index);
        ptr_to_hashing_table[index] = data;
        display_hashing_table(number_of_elements, ptr_to_hashing_table);
        return 1;
    }

    else if(ptr_to_hashing_table[index] != 0) // if collision occurs
    {
        int ans = handle_collision_and_display_hashing_table(data, number_of_elements, ptr_to_hashing_table,index);
        return ans;

    }

}

int hash_function(int data,int number_of_elements)
{
   int ans = data % number_of_elements;
   return ans;

}

int handle_collision_and_display_hashing_table(int data , int number_of_elements , int * ptr_to_hashing_table, int index)
{
    // returns 0 if hashing table is full
    // returns 1 if element got inserted at a position
    int ans = is_hashing_table_full(ptr_to_hashing_table, number_of_elements);

    if(ans == 1) // if hashing table is full
    {
        printf("Sorry the hashing table is full\n");
        printf("Exiting the insertion of elements in the hashing table\n");
        display_hashing_table(number_of_elements, ptr_to_hashing_table);
        return 0;
    }

    // hashing table is not full and collision has occurred
    printf("Collision has occurred !!!\n");
    search_empty_place_after_collision_and_insert_in_hashing_table(data, number_of_elements, ptr_to_hashing_table, index);
    display_hashing_table(number_of_elements, ptr_to_hashing_table);
    return 1;

}

int is_hashing_table_full(int * ptr_to_hashing_table , int number_of_elements)
{
    // returns 0 if hashing table is not full
    // returns 1 if hashing table is full

    for (int i = 0; i < number_of_elements; i++)
    {
        if (ptr_to_hashing_table[i] != 0)
        {
            continue;
        }
        else
        {
            return 0;
        }
    }

    return 1;

}


void search_empty_place_after_collision_and_insert_in_hashing_table(int data , int number_of_elements , int * ptr_to_hashing_table, int index)
{
    // the index variable is the index number at which collision has occurred
    int dummy = 1;

    if(index == number_of_elements -1)
    {
        index = 0;
    }

    else
    {
        index++;
    }

    while(dummy == 1)
    {

        if(ptr_to_hashing_table[index] == 0) // we got an empty space where we can store the data
        {
            printf("Inserted %d at %dth index of the hashing table \n",data,index);
            ptr_to_hashing_table[index] = data;
            break;
        }

        else// collision has occurred once again : the value at particular index is full , check next index
        {
            if(index == number_of_elements-1)
            {
                index = 0;
            }
            else
            {
                index ++;
            }

            continue;

        }

    }

}


void display_hashing_table(int number_of_elements , int * ptr_to_hashing_table )
{
    printf("The current status of Hashing Table is :\n");
    printf("{");
    for(int i = 0;i<number_of_elements;i++)
    {
        printf("%d", ptr_to_hashing_table[i]);
        if(i == number_of_elements-1)
        {
            continue;
        }

        printf(" , ");

    }
    printf("}\n");

}

int searching_in_hashing_table(int element_to_be_searched , int number_of_elements , int * ptr_to_hashing_table)
{
    // returns -1 if element not found in the hashing table
    // returns the zero based index position of the element in the hashing table.


    int index = hash_function(element_to_be_searched, number_of_elements);
    int copy_of_index = index;
    if(ptr_to_hashing_table[index] == element_to_be_searched)
    {
        return index;
    }
    index++;

    int dummy = 1;
    while(dummy == 1)
    {
        if(ptr_to_hashing_table[index] == element_to_be_searched)
        {
            return index;
        }
        else if(index == number_of_elements-1)
        {
            index = 0;
        }
        else if (index == copy_of_index)
        {
            break;
        }
        else
        {
            index ++;
        }
    }

    return -1;
}