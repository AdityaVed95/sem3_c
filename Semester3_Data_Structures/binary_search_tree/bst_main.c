//
// Created by Aditya Ved on 10/11/22.
//
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * ptr_right_child;
    struct node * ptr_left_child;

};

struct node * create_bst(int data1);
void insert_node_in_bst(int data_to_insert , struct node * start);
struct node * insertion_mechanism(struct node * tree, int data_to_insert);


int main()
{

    // create bst
    // insert nodes in bst
    // all 3 types of traversals of bst
    // search in bst


    // deletion is bst

    printf("Enter the data of root node of BST : \n");
    int data1;
    scanf("%d",&data1);
    fflush(stdin);
    struct node * start = create_bst(data1);

    int dummy = 1;
    while(dummy == 1)
    {
        printf("Enter 1 to insert anode in BST\n");
        printf("Enter 2 to exit insertion of nodes in BST \n");
        int response;
        scanf("%d",&response);

        if(response == 1)
        {
            printf("Enter the data of the node to be inserted in BST\n");
            int d;
            scanf("%d",&d);
            insert_node_in_bst(d,start);

        }

        else if(response == 2)
        {
            break;
        }

        else
        {
            printf("Invalid Input , please try again \n");
        }

    }

    printf("\n");
    return 0;
}

struct node * create_bst(int data1)
{
    struct node * start = (struct node *) malloc(sizeof (struct node));
    start->data = data1;
    start->ptr_left_child = NULL;
    start->ptr_right_child = NULL;
    return start;
}

void insert_node_in_bst(int data_to_insert , struct node * start)
{
    struct node * new_node = insertion_mechanism(start,data_to_insert);
    new_node->data = data_to_insert;
    new_node->ptr_left_child = NULL;
    new_node->ptr_right_child = NULL;

//    struct node * ptr_iterator = start;

//    while(dummy == 1)
//    {
//        if(data_to_insert > ptr_iterator->data)
//        {
//            ptr_iterator = ptr_iterator->ptr_right_child;
//        }
//
//        else if(data_to_insert < ptr_iterator->data)
//        {
//            ptr_iterator = ptr_iterator->ptr_left_child;
//        }
//
//    }

}

struct node * insertion_mechanism(struct node * tree, int data_to_insert)
{
    // initially tree = start
    if(tree->data > data_to_insert)
    {
        if(tree->ptr_left_child != NULL)
        {
            tree->ptr_left_child = insertion_mechanism(tree->ptr_left_child, data_to_insert);
        }
        tree->ptr_left_child = (struct node *)malloc(sizeof (struct node));
        return tree->ptr_left_child;
    }
    else if(tree-> data < data_to_insert)
    {
        if(tree->ptr_right_child != NULL)
        {
            tree->ptr_right_child = insertion_mechanism(tree->ptr_right_child,data_to_insert);
        }
        tree->ptr_right_child = (struct node *)malloc(sizeof (struct node));
        return tree->ptr_right_child;
    }

    else if(tree->data == data_to_insert)
    {
        printf("Duplication not allowed in BST, Please try later\n");
        return NULL;
    }

}
