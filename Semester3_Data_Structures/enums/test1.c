//
// Created by Aditya Ved on 09/12/22.
//

#include <stdio.h>
#include <stdlib.h>

#define PI 3.14
// the above line is a macro
// macro used to define a constant value or a group of statements.

// enum is used to define a group of constants which do not change: eg name of the week
enum Week {Sunday,Monday,Tuesday,Wednesday,Thursday };

int main()
{
    enum Week day;
    day = Sunday;
    printf("%Week",day);
    printf("\n");
    return 0;
}