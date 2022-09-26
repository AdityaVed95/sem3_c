//
// Created by Aditya Ved on 22/09/22.
//

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    double coefficient;
    int power;
    struct Node * ptr_next;
};

struct Node * ptr_head_num1;//ptr to the 1st node for the 1st polynomial
struct Node * ptr_head_num2;
struct Node * ptr_head_num3;

struct Node * create_linked_list(double , int );
void insert_in_ll_at_end(struct Node ** );

int main()
{
    printf("Enter the polynomial values from higher to lower powers of x\n");
    printf("For the 1st polynomial\n");
    printf("Enter the number of terms in the polynomial\n");
    int num1,num2,num3;
    scanf("%d",&num1);
    fflush(stdin);
    int i,coeff,pow;
    struct Node * ptr_previous = NULL;

    for(i=1;i<=num1;i++)
    {
        if(i==1)
        {
            // check if this can be put inside create_linked list
            printf("Enter the coefficient of 1st term\n");
            scanf("%d",&coeff);
            fflush(stdin);
            printf("Enter the power of 1st term\n");
            scanf("%d",&pow);
            fflush(stdin);
            ptr_head_num1 = create_linked_list(coeff,pow);
            ptr_previous = ptr_head_num1;
            continue;
        }

        insert_in_ll_at_end(&(ptr_previous));


    }

    printf("\n");
    return 0;
}

struct Node * create_linked_list(double coeff, int pow)
{
    struct Node * head = (struct Node *) malloc(sizeof (struct Node));
    head->coefficient = coeff;
    head->power = pow;
    head->ptr_next = NULL;
    return head;
}

void insert_in_ll_at_end(struct Node ** ptr_to_ptr_to_previous)
{
    struct Node * ptr_previous= *(ptr_to_ptr_to_previous);
    int coeff,pow;
    printf("Enter the coefficient of %dth term\n",i);
    scanf("%d",&coeff);
    fflush(stdin);
    printf("Enter the power of %dth term\n",i);
    scanf("%d",&pow);
    fflush(stdin);

    struct Node * node = (struct Node *) malloc(sizeof (struct Node));
    node->power=pow;
    node->coefficient = coeff;
    node->ptr_next = NULL;
    ptr_previous->ptr_next = node;
    ptr_previous = node;

}