//
// Created by Aditya Ved on 03/12/22.
//

#include <stdio.h>
#include <stdlib.h>
#include "que_implementation.c"

void initialise_adjacency_matrix(int ptr_to_adjacency_matrix[7][7] , int dom);
void print_adjacency_matrix(int ptr_to_adjacency_matrix[7][7] , int dom);
void create_structures();
void print_structures();
void traverse_graph(int adjacency_matrix[7][7]);

struct vertex
{
    char name;
    int number;
    char status; // v is visited , u is unvisited
};

const int dom = 7;// dimensions_of_matrix

struct vertex * array_of_pointers_to_structure[dom];

int main()
{

    int adjacency_matrix[dom][dom];
    initialise_adjacency_matrix(adjacency_matrix,dom);
    print_adjacency_matrix(adjacency_matrix,dom);
    create_structures();
    print_structures();
    traverse_graph(adjacency_matrix);



    printf("\n");
    return 0;
}

void initialise_adjacency_matrix(int ptr_to_adjacency_matrix[7][7] , int dom)
{
    for(int i = 0 ; i<dom;i++)
    {
        for(int j = 0;j<dom;j++)
        {
            ptr_to_adjacency_matrix[i][j] = 0;
        }
    }

    ptr_to_adjacency_matrix[0][2] = 1;
    ptr_to_adjacency_matrix[0][5] = 1;
    ptr_to_adjacency_matrix[1][2] = 1;
    ptr_to_adjacency_matrix[1][6] = 1;
    ptr_to_adjacency_matrix[2][1] = 1;
    ptr_to_adjacency_matrix[2][3] = 1;
    ptr_to_adjacency_matrix[3][5] = 1;
    ptr_to_adjacency_matrix[4][3] = 1;
    ptr_to_adjacency_matrix[4][6] = 1;
    ptr_to_adjacency_matrix[5][4] = 1;
}

void print_adjacency_matrix(int ptr_to_adjacency_matrix[7][7] , int dom)
{
    printf("The adjacency matrix for the directed graph is : \n");
    for(int i = 0 ; i<dom;i++)
    {
        for(int j = 0;j<dom;j++)
        {
            printf("%d\t",ptr_to_adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}

void create_structures()
{
    for(int i=0;i<dom;i++)
    {
        array_of_pointers_to_structure[i] = (struct vertex *) malloc(sizeof (struct vertex));
        (array_of_pointers_to_structure[i])->number = i;
        (array_of_pointers_to_structure[i])->status = 'u';

    }

}

void print_structures()
{
    printf("\n\nEach Vertex with their initial status of unvisited :\n");
    for(int i=0;i<dom;i++)
    {
        printf("%d\t%c\n",array_of_pointers_to_structure[i]->number,array_of_pointers_to_structure[i]->status);

    }

}

void traverse_graph(int adjacency_matrix[7][7])
{
    int front1=-1,rear1=-1;
    int max = 50;
    int queue1 [max];

    int final_traversal_order_queue[max];
    int front_final=-1,rear_final=-1;

    printf("\n\nSequence of steps of enqueing and dequeing is :\n\n");

    array_of_pointers_to_structure[0]->status = 'v'; // visiting the 1st vertex

    insert(queue1, &front1, &rear1, max, array_of_pointers_to_structure[0]->number);
    insert(final_traversal_order_queue,&front_final,&rear_final,max,array_of_pointers_to_structure[0]->number);
    printf("Enqueuing this vertex : %d\n",array_of_pointers_to_structure[0]->number);

    while(is_que_empty(&front1, &rear1) == 0)
    {
        for(int i = 0;i< dom;i++) // covering each element of the row
        {
            if(adjacency_matrix[queue1[front1]][i] == 1)
            {
                if(array_of_pointers_to_structure[i]->status == 'u')
                {
                    insert(queue1, &front1, &rear1, max, array_of_pointers_to_structure[i]->number);
                    array_of_pointers_to_structure[i]->status = 'v';
                    insert(final_traversal_order_queue, &front_final, &rear_final, max, array_of_pointers_to_structure[i]->number);
                    printf("Enqueuing this vertex : %d\n",array_of_pointers_to_structure[i]->number);
                }
            }
        }

        delete(queue1,&front1,&rear1);
    }


    printf("\n\nThe final Breadth First Search Traversal sequence for the given graph is : \n");
    display(final_traversal_order_queue,&front_final,&rear_final);

}