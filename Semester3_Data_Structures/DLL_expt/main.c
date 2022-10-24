//
// Created by Aditya Ved on 20/10/22.
//

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node * ptr_next;
    struct Node * ptr_back;

};

struct Node * create_dll(int * , int );
struct Node * insert_node(struct Node * , int , int , int *);
struct Node * insert_at_start(struct Node * start , int data, int *);
struct Node * insert_at_last(struct Node * start , int data, int *);
struct Node * insert_in_between(struct Node * start,int data,int position,int * ptr_to_number_of_nodes);
struct Node * delete_given_node(struct Node * , int , int * );
struct Node * delete_at_start(struct Node * start , int *);
struct Node * delete_at_last(struct Node * start,  int *) ;
struct Node * delete_in_between(struct Node * start, int ,  int *);

void traverse_dll(struct Node * start);


int main()
{


    // create DLL
    // add node in DLL
    // delete a given node from the DLL
    int number_of_nodes = 0;

    printf("Enter the data of the 1st node : \n");
    int data1;
    scanf("%d",&data1);
    fflush(stdin);

    struct Node * start = create_dll(&number_of_nodes,data1);


    int dummy =1 ;

    while(dummy == 1)
    {
        printf("Enter 1 to insert a node\n");
        printf("Enter 2 to delete a given node\n");
        printf("Enter 3 to display the elements of the linked list\n");
        printf("Enter 4 to Exit the program \n");
        int response;
        scanf("%d",&response);
        fflush(stdin);

        if(response == 1)
        {
            printf("Enter the position (1 based numbering) at which you want to insert a node\n");
            int position;
            scanf("%d",&position);
            fflush(stdin);

            printf("Enter the data for the node to be inserterd\n");
            int data;
            scanf("%d",&data);
            fflush(stdin);
            start = insert_node(start,position,data,&number_of_nodes);
        }
        else if (response == 2)
        {
            printf("Enter the position of the node to be deleted\n");
            int position;
            scanf("%d",&position);
            fflush(stdin);
            start = delete_given_node(start,position,&number_of_nodes);
        }

        else if(response ==3)
        {
            traverse_dll(start);
        }

        else if (response == 4)
        {
            break;
        }

        else
        {
            printf("Invalid input, please try again.\n");
        }

    }

    printf("\n");
    return 0;
}


struct Node * create_dll(int * ptr_to_number_of_nodes , int data1)
{
    struct Node * start = (struct Node *) malloc(sizeof (struct Node));


    start->data = data1;
    start->ptr_next = NULL;
    start->ptr_back = NULL;

    *(ptr_to_number_of_nodes) +=1;

    printf("DLL created\n");
    return start;
}



struct Node * insert_node(struct Node * start, int position, int data , int * ptr_to_number_of_nodes)
{
    // insertion in between
    // insertion in end
    // insertion at start
    // insertion when empty



    if( 0 < position &&  position <= *(ptr_to_number_of_nodes)+1 ) // valid input
    {
        if(*(ptr_to_number_of_nodes) == 0) // IF dll is empty
        {
            printf("The linked list is empty, inserting new node in the linked list\n");
            start = create_dll(ptr_to_number_of_nodes,data);
            return start;
        }

        if(position == 1)
        {
            start = insert_at_start(start,data,ptr_to_number_of_nodes);
            return start;
        }

        if(position == *(ptr_to_number_of_nodes) + 1)
        {
            start = insert_at_last(start,data,ptr_to_number_of_nodes);
            return start;
        }

        // here if the program reaches then it is insertion in between
        start = insert_in_between(start,data,position,ptr_to_number_of_nodes);
        return start;

    }

    else
    {
        printf("Invalid input , Cannot insert nodes beyond the number of elements in linked list\n");
        printf("Note : number of nodes are : %d\n",*(ptr_to_number_of_nodes));
        printf("Please try later\n");
        return start;
    }

}


struct Node * delete_given_node(struct Node * start, int position , int * ptr_to_number_of_nodes)
{

    // delete at start
    // delete at end
    // delete in between

    if(*(ptr_to_number_of_nodes) == 0)
    {
        printf("Cant delete from empty DLL, try again later\n");
        return start;
    }

    if(*(ptr_to_number_of_nodes) == 1)
    {
        if(position == 1)
        {
            struct Node *temp = start;
            free(temp);
            start = NULL;
            *(ptr_to_number_of_nodes) -= 1;
            return start;
        }
        else
        {
            printf("There is only one node in the DLL, cannot delete the node at %dth position\n",position);
            return start;
        }

    }

    if( 0 < position &&  position <= *(ptr_to_number_of_nodes) )
    {
        if(position == 1)
        {
            start = delete_at_start(start,ptr_to_number_of_nodes);
            return start;
        }

        if(position == *(ptr_to_number_of_nodes))
        {
            start = delete_at_last(start,ptr_to_number_of_nodes);
            return start;
        }

        delete_in_between(start,position,ptr_to_number_of_nodes);
        return start;

    }

    printf("Cannot delete a node which doesnt exist in the DLL\n");

    return start;
}

void traverse_dll(struct Node * start)
{
    struct Node * ptr_iterator = start;
    int i=1;
    while (ptr_iterator != NULL)
    {
        printf("The data of %dth node is : %d\n",i,ptr_iterator->data);
        i++;
        ptr_iterator = ptr_iterator->ptr_next;
    }
}

struct Node * insert_at_start(struct Node * start , int data, int * ptr_to_number_of_nodes)
{
    struct Node * temp = (struct Node *) malloc(sizeof (struct Node));
    temp->data = data;
    temp->ptr_back = NULL;
    temp->ptr_next = start;
    start->ptr_back = temp;
    start = temp;
    *(ptr_to_number_of_nodes) +=1;
    return start;

}


struct Node * insert_at_last(struct Node * start , int data, int * ptr_to_number_of_nodes)
{
    struct Node * ptr_iterator = start;
    while(ptr_iterator->ptr_next != NULL)
    {
        ptr_iterator = ptr_iterator->ptr_next;
    }

    struct Node * temp = (struct Node *) malloc(sizeof (struct Node));
    temp->data = data;
    temp->ptr_next = NULL;
    temp->ptr_back = ptr_iterator;
    ptr_iterator->ptr_next = temp;
    *(ptr_to_number_of_nodes) += 1;
    return start;

}

struct Node * insert_in_between(struct Node * start,int data,int position,int * ptr_to_number_of_nodes)
{
    struct Node * ptr_iterator = start;

    // if insertion at postn 4 then go upto node 3
    for(int i=1;i<position-1;i++)
    {
        ptr_iterator = ptr_iterator->ptr_next;
    }

    struct Node * temp = (struct Node * ) malloc(sizeof (struct Node));
    temp->data = data;
    temp->ptr_next = ptr_iterator->ptr_next;
    temp->ptr_back = ptr_iterator;
    ptr_iterator->ptr_next->ptr_back = temp;
    ptr_iterator->ptr_next = temp;

    *(ptr_to_number_of_nodes) +=1;

    return start;


}

struct Node * delete_at_start(struct Node * start,int * ptr_to_number_of_nodes)
{
    struct Node * temp = start;
    start = start->ptr_next;
    start->ptr_back = NULL;
    free(temp);
    *(ptr_to_number_of_nodes) -= 1;
    return start;
}

struct Node * delete_at_last(struct Node * start,int * ptr_to_number_of_nodes)
{
    struct Node * ptr_iterator =start;

    while(ptr_iterator->ptr_next->ptr_next != NULL)
    {
        ptr_iterator = ptr_iterator->ptr_next;
    }

    printf("Deleting the node with data : %d\n",ptr_iterator->ptr_next->data);
    struct Node * temp = ptr_iterator->ptr_next;
    ptr_iterator->ptr_next = NULL;
    free(temp);
    *(ptr_to_number_of_nodes) -= 1;
    return start;

}


struct Node * delete_in_between(struct Node * start,int position,int * ptr_to_number_of_nodes)
{
    struct Node * ptr_iterator = start;
    for(int i=1;i<position-1;i++)
    {
        ptr_iterator= ptr_iterator->ptr_next;
    }
    // postn = 4
    // i =1 : ptr = 2nd
    // i = 2 : ptr = 3rd

    ptr_iterator->ptr_next->ptr_next->ptr_back = ptr_iterator;
    struct Node * temp = ptr_iterator->ptr_next;
    ptr_iterator->ptr_next = temp->ptr_next;
    printf("Deleting node with data %d\n",temp->data);
    free(temp);
    *(ptr_to_number_of_nodes) -= 1;
    return start;
}


