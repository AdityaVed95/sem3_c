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
void insertion_mechanism(struct node * tree, int data_to_insert);
void preorder_traversal_bst(struct node * tree);
void inorder_traversal_bst(struct node * tree);
void postorder_traversal_bst(struct node * tree);
void search_element_in_bst(struct node * tree, int data_to_search);



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
            insertion_mechanism(start,d);

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

    printf("\nSuccessfully created BST \n\n");

    while(dummy == 1)
    {
        printf("Enter 1 to perform Preorder traversal\n");
        printf("Enter 2 to perform Inorder traversal\n");
        printf("Enter 3 to perform Postorder traversal\n");
        printf("Enter 4 to exit the traversal of BST\n");

        int response;
        scanf("%d",&response);
        fflush(stdin);

        if(response == 1)
        {
            preorder_traversal_bst(start);
            printf("\n");
        }

        else if(response == 2)
        {
            inorder_traversal_bst(start);
            printf("\n");
        }

        else if(response == 3)
        {
            postorder_traversal_bst(start);
            printf("\n");
        }

        else if (response == 4)
        {
            break;
        }

        else
        {
            printf("Invalid input, please try again !!!\n");
        }


    }

    printf("\nSuccessfully completed the traversals in BST !! \n\n");

    while(dummy == 1)
    {
        printf("Enter 1 to search an element in BST using the efficient search technique of BST \n");
        printf("Enter 2 to exit searching elements in BST\n");
        int response;

        scanf("%d",&response);
        fflush(stdin);

        if(response == 1)
        {
            printf("Enter the data to be searched in the BST\n");
            int d;
            scanf("%d",&d);
            fflush(stdin);
            search_element_in_bst(start,d);
        }

        else if(response == 2)
        {
            break;
        }

        else
        {
            printf("Invalid input, please try again !!!\n");
        }
    }

    printf("\nSuccessfully completed the Searching of data in BST \n\n");


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
    insertion_mechanism(start,data_to_insert);


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

void insertion_mechanism(struct node * tree, int data_to_insert)
{
    // initially tree = start
    if(tree->data > data_to_insert)
    {
        if(tree->ptr_left_child != NULL)
        {
            insertion_mechanism(tree->ptr_left_child, data_to_insert);
        }
        else
        {
            tree->ptr_left_child = (struct node *)malloc(sizeof (struct node));
            tree->ptr_left_child->data = data_to_insert;
            tree->ptr_left_child->ptr_left_child = NULL;
            tree->ptr_left_child->ptr_right_child = NULL;
        }

    }
    else if(tree-> data < data_to_insert)
    {
        if(tree->ptr_right_child != NULL)
        {
            insertion_mechanism(tree->ptr_right_child,data_to_insert);
        }
        else
        {
            tree->ptr_right_child = (struct node *)malloc(sizeof (struct node));
            tree->ptr_right_child->data = data_to_insert;
            tree->ptr_right_child->ptr_left_child = NULL;
            tree->ptr_right_child->ptr_right_child = NULL;
        }


    }

    else if(tree->data == data_to_insert)
    {
        printf("Duplication not allowed in BST, Please try later\n");
    }

}

void preorder_traversal_bst(struct node * tree)
{
    if(tree != NULL)
    {
        printf("%d ",tree->data);
        preorder_traversal_bst(tree->ptr_left_child);
        preorder_traversal_bst(tree->ptr_right_child);
    }
}

void inorder_traversal_bst(struct node * tree)
{
    if(tree != NULL)
    {
        inorder_traversal_bst(tree->ptr_left_child);
        printf("%d ",tree->data);
        inorder_traversal_bst(tree->ptr_right_child);
    }
}

void postorder_traversal_bst(struct node * tree)
{
    if(tree != NULL)
    {
        postorder_traversal_bst(tree->ptr_left_child);
        postorder_traversal_bst(tree->ptr_right_child);
        printf("%d ", tree->data);
    }
}

void search_element_in_bst(struct node * tree, int data_to_search)
{
    if(tree != NULL)
    {
        if(tree->data > data_to_search)
        {
            search_element_in_bst(tree->ptr_left_child,data_to_search);
        }
        else if(tree->data < data_to_search)
        {
            search_element_in_bst(tree->ptr_right_child,data_to_search);
        }
        else if(tree->data == data_to_search)
        {
            printf("Found %d in BST !!! \n",data_to_search);
        }
    }

    else
    {
        printf("Inputted data not found in BST !!!\n");
    }
}