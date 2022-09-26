//
// Created by Aditya Ved on 15/09/22.
//
#include <stdio.h>
#include <stdlib.h>
#include "string_logic.c"

int main()
{
    int MAX = 100;
    char input_string1[MAX];
    char input_string2[MAX];

    printf("Enter 1st string :\n");
    fgets(input_string1,MAX,stdin);
    fflush(stdin);

    printf("Enter 2nd string:\n");
    fgets(input_string2,MAX,stdin);
    fflush(stdin);

    remove_newline_character(input_string1);
    remove_newline_character(input_string2);

    int dummy = 1,response,resp_1;

    while (dummy == 1)
    {
        printf("Enter 1 to to calculate the length of both the strings\n");
        printf("Enter 2 to concatenate two strings\n");
        printf("Enter 3 to print both the strings\n");
        printf("Enter 4 to compare two strings \n");
        printf("Enter 5 to copy a string into another string\n");
        printf("Enter 6 to search for 1st occurrence of a character in a string\n");
        printf("Enter 7 to search for all occurrences of the search string in the main string\n");
        printf("Enter 8 to exit\n");

        scanf("%d",&response);
        fflush(stdin);

        if(response == 1)
        {
            printf("The number of characters in 1st string is : %d\n",string_length(input_string1));
            printf("The number of characters in 2nd string is : %d\n",string_length(input_string2));
        }

        else if(response == 2)
        {
            printf("Enter 1 to store the result in string1 after concatenation\n");
            printf("Enter 2 to store the result in string2 after concatenation\n");
            scanf("%d",&resp_1);
            fflush(stdin);
            if(resp_1 == 1)
            {
                int ans = string_concatenate(input_string1,input_string2);
                if(ans == 0)
                {
                    printf("Concatenation complete!\n");
                }
                else if (ans == -1)
                {
                    printf("Could not concatenate as length of source string was becoming more than 100 characters after concatenation\n");
                }
            }

            if (resp_1 == 2)
            {
                int ans = string_concatenate(input_string2,input_string1);
                if(ans == 0)
                {
                    printf("Concatenation complete!\n");
                }
                else if (ans == -1)
                {
                    printf("Could not concatenate as length of source string was becoming more than 100 characters after concatenation\n");
                }
            }
        }

        else if(response == 3)
        {
            printf("Input String 1 is :\n");
            print_string_cui(input_string1);
            printf("Input String 2 is :\n");
            print_string_cui(input_string2);
        }

        else if(response == 4)
        {
            printf("Note : prints zero if both the strings are  the same\n"
                   " prints +ve value say x , if char1 > char2 : in ascii value\n"
                   " prints -ve value say x , if char1 < char2 : in ascii value\n"
                   " here x is the difference in ascii values of the two characters at the 1st point of difference\n");

            printf("Comparing string1 and string2 character by character\n");
            int ans = string_compare(input_string1,input_string2);
            printf("Result of comparision is : %d\n",ans);
        }

        else if(response == 5)
        {
            printf("Enter 1 to do string1 = string2\n");
            printf("Enter 2 to do string2 = string1\n");
            scanf("%d",&resp_1);
            fflush(stdin);

            if(resp_1 == 1)
            {
                string_copy(input_string1,input_string2);
            }
            else if(resp_1 == 2)
            {
                string_copy(input_string2,input_string1);
            }
        }

        else if (response == 6)
        {
            printf("Enter the character to be searched\n");
            char temp;
            scanf("%c",&temp);
            fflush(stdin);
            printf("Enter 1 to search in string1 and 2 to search in string2\n");
            scanf("%d",&resp_1);
            fflush(stdin);
            if (resp_1 == 1)
            {
                int pos = first_occurrence_of_character_in_string(input_string1,temp);
                if(pos == -1)
                {
                    printf("Character not found in the string\n");
                }
                else
                {
                    printf("Character found at %d position in the string\n",pos);
                }
            }
            else if(resp_1 == 2)
            {
                int pos = first_occurrence_of_character_in_string(input_string2,temp);
                if(pos == -1)
                {
                    printf("Character not found in the string\n");
                }
                else
                {
                    printf("Character found at %d position in the string\n",pos);
                }
            }
        }

        else if (response == 7)
        {
            printf("Enter the string to be searched for in the main string\n");
            char search[100];
            fgets(search,MAX,stdin);
            fflush(stdin);
            remove_newline_character(search);
            printf("Enter 1 to search in string1 and 2 to search in string 2\n");
            scanf("%d",&resp_1);

            if(resp_1 == 1)
            {
                all_occurrences_of_string_in_a_string(input_string1,search);
            }
            else if (resp_1 == 2)
            {
                all_occurrences_of_string_in_a_string(input_string2,search);
            }
        }

        else if(response == 8)
        {
            break;
        }

        else
        {
            printf("Invalid input\n");
        }

    }

    printf("\n");
    return 0;
}


//typedef struct abstract String;

//
//    printf("Enter main string :\n");
//    fgets(input_string1,MAX,stdin);
//    fflush(stdin);
//
//    printf("Enter string to be searched for in the main string:\n");
//    fgets(input_string2,MAX,stdin);
//    fflush(stdin);
//
//
//    remove_newline_character(input_string1);
//    remove_newline_character(input_string2);

//    printf("main is : %s\n",input_string1);
//    printf("to be searched is : %s\n",input_string2);

//    int len1 = string_length(input_string1);
//    int len2 = string_length(input_string2);
//    printf("%d\n",len1);
//    printf("%d\n",len2);

//    string_concatenate(input_string1,input_string2);
//    printf("The input_string1 after concatenation is : %s\n",input_string1);

//string_copy(input_string2,input_string1);
// input_string2 = input_string1

//    print_string_cui(input_string1);
//    print_string_cui(input_string2);

//string_concatenate_upto_n_characters(input_string1,input_string2,4);
//printf("%s",input_string1);

//int ans = string_compare_caseinsensitive_upto_n_characters(input_string1,input_string2,3);
//
//int ans = last_occurrence_of_character_in_string_caseinsensitive(input_string1,'$');
//    all_occurrences_of_string_in_a_string(input_string1,input_string2);