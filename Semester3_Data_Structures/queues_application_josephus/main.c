//
// Created by Aditya Ved on 03/11/22.
//
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int id;
    struct node * ptr_next;
};

struct node * create_cq(int id);
void insert_node(int id , struct node * start);
struct node * search(int id, struct node * start);

int main()
{
    printf("Creating circular queue : \n");
    printf("Enter the number of players \n");
    int n;
    scanf("%d",&n);
    fflush(stdin);

    printf("Enter the id of the 1st player\n");
    int id1;
    scanf("%d",&id1);
    fflush(stdin);
    struct node * start = create_cq(id1);

    for(int i =2 ; i<= n ; i++)
    {
        printf("Enter the id for the %dth element\n");
        int id;
        scanf("%d",&id);
        fflush(stdin);
        insert_node(id,start);

    }

    printf("Enter the value of k for every kth player getting eliminated\n");
    int k;
    scanf("%d",&k);
    fflush(stdin);

    struct node * ptr_to_start_deletion;
    int id_delete;

    int dummy = 1;
    while (dummy == 1)
    {
        printf("Enter the player id from which we have to start eliminating the elements of the circular que\n");

        scanf("%d",&id_delete);
        fflush(stdin);
        ptr_to_start_deletion = search(id_delete,start);
        if(ptr_to_start_deletion == NULL)
        {
            printf("Given id does not exist\n");
            printf("please try again \n");
            continue;
        }

        else
        {
            break;
        }
    }


    for(int i=1;i<=n-1;i++)
    {

    }



    printf("\n");
    return 0;
}

struct node * create_cq(int id)
{
    struct node * start = (struct node *) malloc(sizeof (struct node));
    start->id = id;
    start->ptr_next = start;
    return start;

}


void insert_node(int id , struct node * start)
{
    struct node * new_node = (struct node *) malloc(sizeof (struct node));
    new_node->id = id;
    new_node->ptr_next = start;

    struct node * ptr_iterator = start;


    while(ptr_iterator->ptr_next != start)
    {
        ptr_iterator = ptr_iterator->ptr_next;
    }

    ptr_iterator->ptr_next = new_node;

}

struct node * search(int id, struct node * start)
{
    struct node * ptr_iterator = start;
    while(ptr_iterator != NULL)
    {
        if(ptr_iterator->id == id)
        {
            return ptr_iterator;
        }
        ptr_iterator  = ptr_iterator->ptr_next;
    }

    return NULL;

}

void delete_a_node(struct node * start, int id)
{
    struct node * ptr_iterator = start;

    while(ptr_iterator->ptr_next->id != id)
    {
        ptr_iterator = ptr_iterator->ptr_next;
    }

    struct node * delete_me = ptr_iterator->ptr_next;
    ptr_iterator->ptr_next = ptr_iterator->ptr_next->ptr_next;
    free(delete_me);

}