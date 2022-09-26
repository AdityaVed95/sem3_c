#include <stdio.h>
#include <stdlib.h>


void multiply(int a , int b)
{
    int product;
    product = a*b;
    printf("The product is : %d\n",product);

}

int main()
{
    void (* multiply_fxn_ptr) (int, int);
    multiply_fxn_ptr = &multiply;
    (*multiply_fxn_ptr)(5,4);
    printf("\n");
    return 0;
}