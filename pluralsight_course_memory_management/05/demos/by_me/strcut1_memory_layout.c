//
// Created by Aditya Ved on 15/08/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct Grade
{
    char letter;
    int rank;
}mac;


int main()
{
    struct Grade student1;
    student1.letter = 'A';
    student1.rank = 5;

    mac student2;
    student2.letter = 'B';
    student2.rank = 50;

    // here : struct Grade and mac are interchangeable

    // struct Grade * = &(student1);

    printf("Address of student1.letter is %u\n",&student1.letter);
    printf("Address of student1.rank is %u\n",&student1.rank);
    printf("Address of student1 is : %u\n",&student1);

    const size_t size_of_letter = sizeof(student1.letter);
    const size_t size_of_rank = sizeof(student1.rank);
    const size_t size_of_student1 = sizeof(student1);

    printf("Size of letter is %zu\n",size_of_letter);
    printf("Size of rank is %zu\n",size_of_rank);
    printf("Size of student1 is : %zu\n\n",size_of_student1);

    const size_t size_of_padding = size_of_student1 - (size_of_letter+size_of_rank);


    printf("Thus the size of padding is : (size of student) - (size of letter + size of rank)"
           " = %zu \n",size_of_padding);


    //The datatype size_t is unsigned integral type. It represents
    // the size of any object in bytes and returned by sizeof
    // operator. It is used for array indexing and counting.
    // It can never be negative. The return type of strcspn, strlen
    // functions is size_t


    // here we dont need to specify student1 or student2 because this memory
    // layout would be same for all the object of type structure

    const size_t letter_offset = offsetof(struct Grade,letter);
    const size_t rank_offset = offsetof(mac,rank);

    printf("The offset of struct Grade from letter is %zu\n",letter_offset);
    printf("The offset of struct Grade from rank is %zu\n",rank_offset);


    printf("\n");
    return 0;
}