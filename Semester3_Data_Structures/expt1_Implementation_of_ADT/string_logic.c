//
// Created by Aditya Ved on 15/09/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack_logic.c"

int string_length(char *);

void remove_newline_character(char *);

int string_concatenate(char * , char * );

void print_string_cui(char *);

int string_compare(char *, char *);

void string_copy( char *  , char * );

int first_occurrence_of_character_in_string(char *,char);

void all_occurrences_of_string_in_a_string(char *,char*);


int string_concatenate_upto_n_characters(char * , char * , int );

int string_compare_upto_n_characters(char *, char * , int);

int string_compare_caseinsensitive(char *,char *);
int string_compare_caseinsensitive_upto_n_characters(char *,char * , int);


int string_copy_upto_n_characters( char *  , char * , int n);



int last_occurrence_of_character_in_string(char * ,char );

int first_occurrence_of_character_in_string_caseinsensitive(char * ,char );
int last_occurrence_of_character_in_string_caseinsensitive(char * ,char );
int first_occurrence_of_string_in_a_string(char *,char*);




// working
// returns the number of characters in the string excluding the null terminator
int string_length(char * ptr_to_char_array)
{

    int dummy = 1;
    int number_of_elements_in_string = 0;

    while(dummy == 1)
    {
        if((ptr_to_char_array[number_of_elements_in_string]) == '\0')
        {
            break;
        }
        else
        {
            number_of_elements_in_string++;
        }

    }

    return number_of_elements_in_string;

}

// working
void remove_newline_character(char * ptr_to_char_array)
{
    // hello \n  \0
    int len_of_string = string_length(ptr_to_char_array); // len = 6
    ptr_to_char_array[len_of_string-1] = '\0';

}

// working
int string_concatenate(char * ptr_to_char_array1, char * ptr_to_char_array2)
{
    // returns -1 if unsuccessful
    // returns 0 if successful
    int len1 = string_length(ptr_to_char_array1);
    int len2 = string_length(ptr_to_char_array2);

    if(len1+len2+1>100)
    {
        // exceeding the size of char array
        return -1;
    }

    int j,k;

    j = len1;
    for(k=0;k<len2+1;k++)
    {
        ptr_to_char_array1[j] = ptr_to_char_array2[k];
        j++;
    }
    return 0;
}


// working
void string_copy( char * ptr_to_char_array_destination , char * ptr_to_char_array_source)
{
    // copies source into the destination including the '\0' null terminator character
    // there \0

    int len_of_source = string_length(ptr_to_char_array_source);

    int i;
    for(i=0;i<=len_of_source;i++)
    {
        ptr_to_char_array_destination[i] = ptr_to_char_array_source[i];
    }

}


// working
void print_string_cui(char * ptr_to_char_array)
{
    int length = string_length(ptr_to_char_array);
    for(int i = 0; i<length;i++)
    {
        printf("%c",ptr_to_char_array[i]);
    }
    printf("\n");


}


// working
int string_compare(char * ptr_to_char_array1, char * ptr_to_char_array2)
{
    // returns zero if both the strings are  the same
    // returns +ve value say x , if char1 > char2 : in ascii value
    // returns -ve value say x , if char1 < char2 : in ascii value
    // here x is the difference in ascii values of the two characters at the 1st point of difference

    int len1 = string_length(ptr_to_char_array1);
    int len2 = string_length(ptr_to_char_array2);

    int max = len1>len2 ? len1 : len2;

    int flag = 1;
    int difference;
    for(int i = 0; i<max;i++)
    {
        if(ptr_to_char_array1[i] == ptr_to_char_array2[i])
        {
            continue;
        }

        else
        {
            difference = ptr_to_char_array1[i] - ptr_to_char_array2[i];
            flag = 0;
            break;
        }
    }

    if(flag == 0)
    {
        return difference;
    }

    else
    {
        // both strings are the same
        return 0;
    }

}



int first_occurrence_of_character_in_string(char *ptr_to_char_array1 ,char ch)
{
    // if position returned is -1 then character not found in string
    // else found position is returned

    int len = string_length(ptr_to_char_array1);
    int i;
    int position;
    for(i=0;i<len;i++)
    {
        if(ptr_to_char_array1[i] == ch)
        {
            position = i+1;
            return position;
        }
    }

    position = -1;
    return position;
}



void all_occurrences_of_string_in_a_string(char * ptr_to_main_string,char* ptr_to_string_to_be_searched)
{
    //  fxn returns the position of first_occurrence_of_(string to be searched) _in_ the _ (main string)
    int len_of_main_string = string_length(ptr_to_main_string);
    int len_of_string_to_be_searched = string_length(ptr_to_string_to_be_searched);

    int i,j,temp,flag=1;

    // searching blockwise :
    // eg if we have to search for lot in hloellothere then the search will go like this :
    // 1st try to match : hlo
    // hlo is not equal to lot
    // now try 2nd match loe
    // loe is also not equal to lot

    // now 3rd match oel
    // 4th : ell
    // 5th : llo
    // 6th : lot
    // this is where we get our result
    create_stack();
    int count;
    for(i= 0;i<len_of_main_string;i++)
    {
        temp = i;
        count = 0;
        for(j=i;j<temp+len_of_string_to_be_searched;j++)
        {
            if(ptr_to_main_string[j] == ptr_to_string_to_be_searched[count])
            {
                count++;
                continue;
            }
            else
            {
                flag = 0;
                break;
            }
        }

        if(flag == 0)
        {
            flag = 1;
            continue;
        }

        else
        {
            push_into_stack(temp+1);
            // temp+1 is the 1 based position of the 1st occurrence of the string
        }

    }

    if(is_stack_empty() == 1) // if stack is empty
    {
        printf("the string to be searched does not exist in the main string\n"); // no position found
    }

    else
    {
        printf("Displaying the position of all occurrences of string to be searched in the main string\n");
        display_bos_to_tos();
    }
}

// if we want to know the last occurrence of the string to be searched in the main string then
// we can just push each position that we get into the stack and then at the end check :
// if the stack is empty then there is not even one occurrence of the string to be searched in
// the main string and if the stack is not empty then pop a value from the stack and that will
// be the last occurrence of the string to be searched  in the main string


//void input_string(char * ptr_to_array , int length_of_array)
//{
//    for(int i=0;i<length_of_array;i++)
//    {
//        scanf("%c",ptr_to_array+i);
//        fflush(stdin);
//    }
//
//}




int string_concatenate_upto_n_characters(char * ptr_to_char_array1, char * ptr_to_char_array2, int n)
{
    // returns -1 if unsuccessful
    // returns 0 if successful
    int len1 = string_length(ptr_to_char_array1);
    int len2 = string_length(ptr_to_char_array2);
    if(n>len2)
    {
        // cannot concatenate characters more than the character in the 2nd string

        return -1;
    }

    // 80
    // 40


    if(len1+n+1 > 100)
    {
        // exceeding the size of the array
        return -2;
    }

    int j,k;

    j = len1;

    for(k=0;k<n;k++)
    {
        ptr_to_char_array1[j] = ptr_to_char_array2[k];
        j++;
    }

    ptr_to_char_array1[j] = '\0';

    return 0;

}



// working
int string_compare_upto_n_characters(char * ptr_to_char_array1, char *ptr_to_char_array2 , int number_of_characters)
{
    // exactly same as string_compare
    // only difference is that it compares upto n characters only


    int len1 = string_length(ptr_to_char_array1);
    int len2 = string_length(ptr_to_char_array2);

    int max = len1>len2 ? len1 : len2;
    if(number_of_characters>max)
    {
        printf("cannot compare characters more than the max number of characters\n");
        printf("Thus operation unsuccessful\n");
        return -10000;
    }

    int flag = 1;
    int difference;
    for(int i = 0; i<number_of_characters;i++)
    {
        if(ptr_to_char_array1[i] == ptr_to_char_array2[i])
        {
            continue;
        }

        else
        {
            difference = ptr_to_char_array1[i] - ptr_to_char_array2[i];
            flag = 0;
            break;
        }
    }

    if(flag == 0)
    {
        return difference;
    }

    else
    {
        // both strings are the same upto n characters
        return 0;
    }
}


int string_compare_caseinsensitive(char * ptr_to_char_array1,char *ptr_to_char_array2)
{
    // returns 0 if the 2 strings are the same irrespective of their case
    // returns the difference in ascii values if two strings are not the same even in case-insensitive comparison

    int len1 = string_length(ptr_to_char_array1);
    int len2 = string_length(ptr_to_char_array2);

    int max = len1>len2 ? len1 : len2;

    int flag = 1;
    int difference;
    for(int i = 0; i<max;i++)
    {
        if(ptr_to_char_array1[i] == ptr_to_char_array2[i])
        {
            continue;
        }

        else if (isupper(ptr_to_char_array1[i]) == 1)
        {
            char temp = tolower(ptr_to_char_array1[i]);
            if(temp == ptr_to_char_array2[i])
            {
                continue;
            }
            else
            {
                difference = ptr_to_char_array1[i] - ptr_to_char_array2[i];
                flag = 0;
                break;
            }

        }

        else if(islower(ptr_to_char_array1[i]) == 1)
        {
            char temp = toupper(ptr_to_char_array1[i]);
            if(temp == ptr_to_char_array2[i])
            {
                continue;
            }
            else
            {
                difference = ptr_to_char_array1[i] - ptr_to_char_array2[i];
                flag = 0;
                break;
            }
        }

        else
        {
            difference = ptr_to_char_array1[i] - ptr_to_char_array2[i];
            flag = 0;
            break;
        }
    }

    if(flag == 0)
    {
        return difference;
    }

    else
    {
        // both strings are the same
        return 0;
    }

}

int string_compare_caseinsensitive_upto_n_characters(char *ptr_to_char_array1,char * ptr_to_char_array2, int n)
{
    int len1 = string_length(ptr_to_char_array1);
    int len2 = string_length(ptr_to_char_array2);

    int max = len1>len2 ? len1 : len2;
    if(n>max)
    {
        printf("cannot compare characters more than the max number of characters\n");
        printf("thus operation unsuccessful\n");
        return -10000;
    }

    int flag = 1;
    int difference;

    for(int i = 0; i<n;i++)
    {
        if(ptr_to_char_array1[i] == ptr_to_char_array2[i])
        {
            continue;
        }

        else if (isupper(ptr_to_char_array1[i]) == 1)
        {
            char temp = tolower(ptr_to_char_array1[i]);
            if(temp == ptr_to_char_array2[i])
            {
                continue;
            }
            else
            {
                difference = ptr_to_char_array1[i] - ptr_to_char_array2[i];
                flag = 0;
                break;
            }

        }

        else if(islower(ptr_to_char_array1[i]) == 1)
        {
            char temp = toupper(ptr_to_char_array1[i]);
            if(temp == ptr_to_char_array2[i])
            {
                continue;
            }
            else
            {
                difference = ptr_to_char_array1[i] - ptr_to_char_array2[i];
                flag = 0;
                break;
            }
        }

        else
        {
            difference = ptr_to_char_array1[i] - ptr_to_char_array2[i];
            flag = 0;
            break;
        }
    }

    if(flag == 0)
    {
        return difference;
    }

    else
    {
        // both strings are the same
        return 0;
    }

}



int string_copy_upto_n_characters( char * ptr_to_char_array_destination , char * ptr_to_char_array_source , int n)
{
    // return 0 if successful
    // return -1 if unsuccessful

    int len_of_source = string_length(ptr_to_char_array_source);


    if (n> len_of_source)
    {
        // cannot copy characters more than the number of characters in the source string
        return -1;
    }

    int i;
    for(i=0;i<=n;i++)
    {
        ptr_to_char_array_destination[i] = ptr_to_char_array_source[i];
    }

    ptr_to_char_array_destination[i] = '\0';

    return 0;

}



int last_occurrence_of_character_in_string(char *ptr_to_char_array1 ,char ch)
{
    // if position returned is -1 then character not found in string
    // else found position is returned

    int len = string_length(ptr_to_char_array1);
    int i;
    int position;
    for(i=len-1;i>=0;i--)
    {
        if(ptr_to_char_array1[i] == ch)
        {
            position = i+1;
            return position;
        }
    }

    position = -1;
    return position;
}

int first_occurrence_of_character_in_string_caseinsensitive(char *ptr_to_char_array1 ,char ch)
{
    // if position returned is -1 then character not found in string
    // else found position is returned

    int len = string_length(ptr_to_char_array1);
    int i;
    int position;
    for(i=0;i<len;i++)
    {
        if(ptr_to_char_array1[i] == ch)
        {
            position = i+1;
            return position;
        }
        else if(islower(ptr_to_char_array1[i]) == 1)
        {
            char temp = toupper(ptr_to_char_array1[i]);
            if (temp == ch)
            {
                position = i+1;
                return position;
            }
        }

        else if(isupper(ptr_to_char_array1[i]) == 1)
        {
            char temp = tolower(ptr_to_char_array1[i]);
            if(temp == ch)
            {
                position = i+1;
                return position;
            }
        }
    }

    position = -1;
    return position;
}

int last_occurrence_of_character_in_string_caseinsensitive(char *ptr_to_char_array1 ,char ch )
{
    int len = string_length(ptr_to_char_array1);
    int i;
    int position;
    for(i=len-1;i>=0;i--)
    {
        if(ptr_to_char_array1[i] == ch)
        {
            position = i+1;
            return position;
        }

        else if(islower(ptr_to_char_array1[i]) == 1)
        {
            char temp = toupper(ptr_to_char_array1[i]);
            if (temp == ch)
            {
                position = i+1;
                return position;
            }
        }

        else if(isupper(ptr_to_char_array1[i]) == 1)
        {
            char temp = tolower(ptr_to_char_array1[i]);
            if(temp == ch)
            {
                position = i+1;
                return position;
            }
        }


    }

    position = -1;
    return position;
}


int first_occurrence_of_string_in_a_string(char * ptr_to_main_string,char* ptr_to_string_to_be_searched)
{
    //  fxn returns the position of first_occurrence_of_(string to be searched) _in_ the _ (main string)
    int len_of_main_string = string_length(ptr_to_main_string);
    int len_of_string_to_be_searched = string_length(ptr_to_string_to_be_searched);

    int i,j,temp,flag=1;

    // searching blockwise :
    // eg if we have to search for lot in hloellothere then the search will go like this :
    // 1st try to match : hlo
    // hlo is not equal to lot
    // now try 2nd match loe
    // loe is also not equal to lot

    // now 3rd match oel
    // 4th : ell
    // 5th : llo
    // 6th : lot
    // this is where we get our result

    int count;
    for(i= 0;i<len_of_main_string;i++)
    {
        temp = i;
        count = 0;
        for(j=i;j<temp+len_of_string_to_be_searched;j++)
        {
            if(ptr_to_main_string[j] == ptr_to_string_to_be_searched[count])
            {
                count++;
                continue;
            }
            else
            {
                flag = 0;
                break;
            }
        }

        if(flag == 0)
        {
            flag = 1;
            continue;
        }

        else
        {
            return temp+1; // temp+1 is the 1 based position of the 1st occurrence of the string
        }

    }

    return -1;
}