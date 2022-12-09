//
// Created by Aditya Ved on 09/12/22.
//

#include <stdio.h>
#include <stdlib.h>

typedef enum {thread,link} boolean;
struct node
{
	struct node *left_ptr;
	boolean left;
	int info;
	struct node *right_ptr;
	boolean right;

};




int main()
{
    struct node * node1 = (struct node * ) malloc(sizeof (struct node));
    node1->left = thread;
    node1->right = link;

    printf("%d\n",node1->left);
    printf("%d\n",node1->right);

    if(node1->left == thread)
    {
        printf("hello thread\n");
    }

    if(node1->right == link)
    {
        printf("hello link\n");
    }

    if(node1->left == 0)
    {
        printf("hello thread\n");
    }

    if(node1->right == 1)
    {
        printf("hello link\n");
    }

    printf("\n");
    return 0;
}