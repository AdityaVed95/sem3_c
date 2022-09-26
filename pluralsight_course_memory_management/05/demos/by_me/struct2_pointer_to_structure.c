//
// Created by Aditya Ved on 16/08/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct Person
{
    int age;
    double weight;
    char initial_letter;
};

int main()
{
    struct Person P1;
    struct Person *ptr_to_struct_P1;
    ptr_to_struct_P1 = &P1;

    ptr_to_struct_P1->age = 19;
    ptr_to_struct_P1->initial_letter = 'A';
    ptr_to_struct_P1->weight = 63.257;

    printf("Age of P1 is : %d\n", P1.age);
    printf("Initial Letter of P1 is : %c\n", P1.initial_letter);
    printf("Weight of P1 is : %lf\n", P1.weight);

    int x = sizeof(struct Person);
    printf("%d\n",x);

    // this is an incorrect statement : *(ptr_to_struct).age = 20;

//
//    calculating sizes :
//    doubt in the padding :
//
//
//    int x =10;
//    int size_of_int = sizeof (x);
//    printf("Size of int is : %d\n",size_of_int);
//
//    double y = 1000.3423435;
//    int size_of_double = sizeof(y);
//    printf("Size of double is : %d\n",size_of_double);
//
//
//    int size_of_structure_Person = sizeof (struct Person);
//    printf("Size of struct Person is : %d\n",size_of_structure_Person);
//    // ptr_to_struct = &(Person);
//    // the above line is incorrect because when we create a prototype of
//    // structure (like struct Person) then no memory is allocated to
//    // it, only when we create an object (like P1), memory is allocated
//    // to it
//    int size_of_P1 = sizeof (P1);
//    printf("size of P1 is : %d\n",size_of_P1);
//    int size_of_age = sizeof (P1.age);
//    int size_of_initial_letter = sizeof(P1.initial_letter);
//    int size_of_weight = sizeof(P1.weight);
//    printf("Size of P1.age is : %d\n",size_of_age);
//    printf("Size of P1.initial_letter is : %d\n",size_of_initial_letter);
//    printf("Size of P1.weight is : %d\n",size_of_weight);
//
//    size_t offset_of_age = offsetof(struct Person,age);
//    size_t offset_of_weight = offsetof(struct Person,weight);
//    size_t offset_of_initial_letter = offsetof(struct Person,initial_letter);
//
//    printf("offset of age is : %zu \n",offset_of_age);
//    printf("offset of weight is : %zu \n",offset_of_weight);
//    printf("offset of initial_letter is : %zu \n",offset_of_initial_letter);

    printf("\n");
    return 0;
}