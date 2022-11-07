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
struct node * search_for_ptr_on_the_basis_of_id(int id, struct node * start);
struct node * search_on_the_basis_of_id_one_step_behind(int id, struct node * start);
struct node * search_one_step_behind_on_basis_of_ptr_to_given_node(struct node * ptr_to_current_node);
int number_of_nodes(struct node * start);

int main()
{
    printf("Creating circular queue : \n");
    printf("Enter the number of players \n");
    int n;
    scanf("%d",&n);
    fflush(stdin);
    printf("Note : no duplication of id's is allowed for each player.\n");
    printf("Enter the id of the 1st player\n");
    int id1;
    scanf("%d",&id1);
    fflush(stdin);
    struct node * start = create_cq(id1);

    for(int i =2 ; i<= n ; i++)
    {
        printf("Enter the id for the %dth element\n",i);
        int id;
        scanf("%d",&id);
        fflush(stdin);
        insert_node(id,start);

    }

    printf("Enter the value of k for every kth player getting eliminated (note k = 1 or above and k is an integer)\n");
    printf("Eg : For k = 1 : directly next element gets eliminated , for k = 2 alternate elements get eliminated and so on  ....\n");

    int k;
    scanf("%d",&k);
    fflush(stdin);

    struct node * ptr_to_start_deletion;
    int id_delete;

    int dummy = 1;
    // getting pointer to the node from where the deletion is meant to start.
    while (dummy == 1)
    {
        printf("Enter the player id from which we have to start eliminating the elements of the circular que\n");

        scanf("%d",&id_delete);
        fflush(stdin);
        ptr_to_start_deletion = search_for_ptr_on_the_basis_of_id(id_delete, start);
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

    //main logic :
    struct node *ptr_before;

    for(int i=1;i<=n-1;i++)
    {

        ptr_before = search_on_the_basis_of_id_one_step_behind(id_delete, start);
        struct node *temp = ptr_before->ptr_next;
        ptr_before->ptr_next = ptr_before->ptr_next->ptr_next;

        struct node *temp_copy = temp;
        // for k = 1 : directly next element is deleted, for k = 2 : alternating elements are deleted
        struct node *ptr_to_next_node_to_be_deleted;
        for (int j = 1; j <= k; j++)
        {
            ptr_to_next_node_to_be_deleted = temp_copy->ptr_next;
            temp_copy = temp_copy->ptr_next;
        }

        struct node *ptr_before_ptr_to_next_node_to_be_deleted = search_one_step_behind_on_basis_of_ptr_to_given_node(ptr_to_next_node_to_be_deleted);
        id_delete = ptr_before_ptr_to_next_node_to_be_deleted->ptr_next->id;

        free(temp);

    }

    printf("winner is : %d\n",ptr_before->id);


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

// returns a pointer to that node with given id, returns null if a node with given id does not exist

struct node * search_for_ptr_on_the_basis_of_id(int id, struct node * start)
{
    struct node * ptr_iterator = start;

    if(ptr_iterator->id == id)
    {
        return ptr_iterator;
    }
    ptr_iterator  = ptr_iterator->ptr_next;

    while(ptr_iterator != start)
    {
        if(ptr_iterator->id == id)
        {
            return ptr_iterator;
        }
        ptr_iterator  = ptr_iterator->ptr_next;
    }

    return NULL;

}


// returns a pointer one step behind that node with given id, returns null if a node with given id does not exist

struct node * search_on_the_basis_of_id_one_step_behind(int id, struct node * start)
{
    struct node * ptr_iterator = start;

    if(ptr_iterator->ptr_next->id == id)
    {
        return ptr_iterator;
    }
    ptr_iterator  = ptr_iterator->ptr_next;

    while(ptr_iterator != start)
    {
        if(ptr_iterator->ptr_next->id == id)
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

// returns a pointer to a node behind the current node
struct node * search_one_step_behind_on_basis_of_ptr_to_given_node(struct node * ptr_to_current_node)
{
    struct node * ptr_copy_of_current_node = ptr_to_current_node;

    while(ptr_copy_of_current_node->ptr_next != ptr_to_current_node)
    {
        ptr_copy_of_current_node = ptr_copy_of_current_node->ptr_next;
    }

    return ptr_copy_of_current_node;

}

int number_of_nodes(struct node * start)
{
    if(start == NULL)
        return 0;

    struct node * ptr_iterator = start;
    ptr_iterator = ptr_iterator->ptr_next;
    int i = 1;

    while(ptr_iterator != start )
    {
        ptr_iterator = ptr_iterator->ptr_next;
        i++;
    }

    return i;
}




