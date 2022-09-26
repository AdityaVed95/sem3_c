//
// Created by Aditya Ved on 08/09/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fortune_cookie(char msg [])
{
    printf("Msg reads : %s\n",msg);
}

int main()
{
    char quote[] = "Cookies make you fat";
    printf("0 : %c\n",quote[0]);
    printf("1 : %c\n",quote[1]);
    printf("0 : %c\n",*quote);
    printf("1 : %c\n",*(quote+1));

    fortune_cookie(quote);
    printf("\n");
    return 0;
}
