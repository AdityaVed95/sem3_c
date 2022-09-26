//
// Created by Aditya Ved on 16/08/22.
//

#include <stdio.h>
#include <stdlib.h>

struct Person
{
    int age;
    double weight;
    char initial_letter;
};

int main()
{
    struct Person *ptr_to_Person = (struct Person *) malloc(sizeof (struct Person));

    ptr_to_Person->weight = 46.924;
    ptr_to_Person->age = 35;
    ptr_to_Person->initial_letter = 'B';

    printf("weight is : %lf\n",ptr_to_Person->weight);
    printf("age is : %d\n",ptr_to_Person->age);
    printf("initial_letter is : %c\n",ptr_to_Person->initial_letter);

    printf("Value of address stored in ptr_to_person : %u\n",ptr_to_Person);

    printf(" &(ptr_to_Person->age) =  %u\n", &(ptr_to_Person->age));
    printf("&(ptr_to_Person->weight) =  %u\n",&(ptr_to_Person->weight));
    printf("&(ptr_to_Person->initial_letter) =  %u\n",&(ptr_to_Person->initial_letter));




    free(ptr_to_Person);

    // so here we understood that we had a pointer pointing to an allocated block of memory
    // the type of pointer is struct Person
    // the size of the block is equal to the size of the struct Person
    // we cannot use the dot operator here since it can be used when you have created an object of
    // type struct Person (like P1) , which is actually not created in this case




    // the below line gives error
    // printf("weight is : %lf\n",struct Person.age);

    printf("\n");
    return 0;
}