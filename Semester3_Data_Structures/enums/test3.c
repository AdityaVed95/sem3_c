//
// Created by Aditya Ved on 09/12/22.
//

//
// Created by Aditya Ved on 09/12/22.
//

/* enumeration example */
#include<stdio.h>

int main()
{  /* create an enumeration with Week days  */

    enum Week {Sunday, Monday=3, Tuesday, Wednesday, Thursday} ;



    /* create enumeration variable */
    enum Week day;
    /* display the enumeration values by changing day */

    printf("%d\n",Sunday);
    printf("%d\n",Monday);
    printf("%d\n",Tuesday);
    printf("%d\n",Wednesday);
    printf("%d\n",Thursday);

    for(day=Sunday; day<=Thursday; day++)
        printf("\n%d", day);



    /* the above loop is equilvalent to :

        for(int i=0;i<=6;i++)
        {
            printf("%d",i);
        }

     */

    return 0;

}

