
// Created by Aditya Ved on 27/10/22. //
#include <stdio.h>
#include <stdlib.h>
// assuming initially that the hash table is empty and all elements are initialised to 0
// assuming input of zero is not allowed in the hash table.
// if the value of an element in the hash table is zero then that place is considered to be empty .
int insert_data_in_hash_table(int data , int number_of_elements , int * ptr_to_hash_table);
int hash_function(int data,int number_of_elements);
int handle_collision_and_display_hash_table(int data , int number_of_elements , int * ptr_to_hash_table);
int is_hash_table_full(int * ptr_to_hash_table , int number_of_elements);
void search_empty_place_after_collision_and_insert(int data , int number_of_elements , int * ptr_to_hash_table , int index);
void display_hash_table(int number_of_elements , int * ptr_to_hash_table );
int main() {
    int number_of_elements = 7; // creating hash table
    int hash_table[number_of_elements]; // initialising hash table

    for(int i = 0 ; i<number_of_elements; i++) {
        hash_table[i] = 0; }
    int dummy = 1; while(dummy == 1)
    {
        printf("Enter 1 to insert an element in thehash table\n");
        printf("Enter 2 to exit the insertion ofelements\n");
        int response; scanf("%d",&response); fflush(stdin);
        if(response == 1)
        {
            printf("Enter the data to be inserted inthe hash table \n"); int data;
            scanf("%d",&data); fflush(stdin);
            int ans =
            insert_data_in_hash_table(data,number_of_elements,hash_table);
            if(ans == 0)
            {
            } }
        else if(response == 2)
        {
        }
        else
        {
            printf("Invalid input, please try again.\n"); }
            break;
            break;

        }
        printf("Program ended!!\n"); printf("\n");
        return 0;
    }
    int insert_data_in_hash_table(int data,int number_of_elements, int * ptr_to_hash_table) {
        // returns 1 if data got inserted
// returns 0 if hash table was full and data cannot be inserted
        int index = hash_function(data,number_of_elements);
        if(ptr_to_hash_table[index] == 0) // collision did not occur
        {
            printf("No collision occurred, inserted %d at%dth index of the hash table\n",data,index); ptr_to_hash_table[index] = data;
            display_hash_table(number_of_elements,ptr_to_hash_table
            );
        }
        else if(ptr_to_hash_table[index] != 0) // if collision occurs
        {
            int ans =
                    handle_collision_and_display_hash_table(data, number_of_elements, ptr_to_hash_table);
            return ans; }
    }
    int hash_function(int data,int number_of_elements) {
        int ans = data % number_of_elements; return ans;
        return 1;

    }
    int handle_collision_and_display_hash_table(int data , int number_of_elements , int * ptr_to_hash_table)
    {
// returns 0 if hash table is full
// returns 1 if element got inserted at a position int ans =
        is_hash_table_full(ptr_to_hash_table,number_of_elements );
        if(ans == 1) // if hash table is full {
            printf("Sorry the hash table is full\n");
        printf("Exiting the insertion of elements in the hash table\n");
        display_hash_table(number_of_elements,ptr_to_hash_table );
        return 0; }
    // hash table is not full and collision hasoccurred
    printf("Collision has occurred !!!\n");
    search_empty_place_after_collision_and_insert(data,number_of_elements,ptr_to_hash_table,index);display_hash_table(number_of_elements,ptr_to_hash_table );
    return 1;
}
int is_hash_table_full(int * ptr_to_hash_table , int number_of_elements)
{
    // returns 0 if hash table is not full
    // returns 1 if hash table is full
    for (int i = 0; i < number_of_elements; i++)
    {
        if (ptr_to_hash_table[i] != 0)

        {
            continue;
        }
        else
        {
            return 0; }
    }
    return 1; }
void search_empty_place_after_collision_and_insert(int data , int number_of_elements , int * ptr_to_hash_table, int index)
{
// the index variable is the index number at which collision has occurred
    int dummy = 1;
    if(index == number_of_elements -1) {
        index = 0; }
    else
    {
        index++;
    }
    while(dummy == 1) {
        if(ptr_to_hash_table[index] == 0) // we got an empty space where we can store the data
        {
            printf("Inserted %d at %dth index of the
            hash table \n",data,index); ptr_to_hash_table[index] = data;
            break;
        }
        else// collision has occurred once again : the

            value at particular index is full , check next index
        {
            if(index == number_of_elements-1) {
                index = 0; }
            else
            {
                index ++;
            }
            continue;
        } }
}
void display_hash_table(int number_of_elements , int * ptr_to_hash_table )
{
    printf("The current status of Hash Table is :\n"); printf("{");
    for(int i = 0;i<number_of_elements;i++)
    {
        printf("%d",ptr_to_hash_table[i]); if(i == number_of_elements-1)
        {
        }
        printf(" , "); }
    printf("}\n"); }
continue;
