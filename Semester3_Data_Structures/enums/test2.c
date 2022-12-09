//
// Created by Aditya Ved on 09/12/22.
//

/* enumeration example */
#include<stdio.h>

int main()
{  /* create an enumeration with Week days  Sunday is 0, Monday is 1,... */
    enum Week { Sunday, Monday, Tuesday, Wednesday, Thursday };
    // enum Week {Sunday, Monday=3, Tuesday, Wednesday, Thursday};


    /* create enumeration variable */
    enum Week day;
    /* display the enumeration values by changing day */
    for(day=Sunday; day<=Thursday; day++)
        printf("\n%d", day);

    return 0;
}

