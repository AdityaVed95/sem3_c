#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data; // data inside the node is of int datatype
    struct Node *next; // the pointer in node that is pointing to the next node
} Node;

typedef struct LinkedList {
    int count; // number of nodes
    Node *head; // a pointer pointing to the 1st node in the linked list
    Node *tail;
} LinkedList;

LinkedList* init_linked_list();
void destroy_linked_list(LinkedList*);
void print_linked_list(LinkedList*);
void print_node(Node*);
void insert_node(LinkedList*, int);
void remove_node(LinkedList*, Node*);

int main(int argc, char* argv[]){
    LinkedList *my_list = init_linked_list(); // this line creates a linked list
    // my_list is a pointer to the linked list


    if (!my_list)
        return 1;

    insert_node(my_list, 1);
    print_linked_list(my_list);

    insert_node(my_list, 2);
    print_linked_list(my_list);

    insert_node(my_list, 3);
    print_linked_list(my_list);

    remove_node(my_list, my_list->head->next);
    print_linked_list(my_list);

    destroy_linked_list(my_list);
    return 0;
}

LinkedList* init_linked_list() {
    LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
    if (list != NULL) {
        list->count = 0;
        list->head = NULL;
    }

    return list;
}

void destroy_linked_list(LinkedList *list) {
    if (list == NULL)
        return;

    Node *current = list->head;
    while(current != NULL) {
        Node *next = current->next;
        remove_node(list, current);
        current = next;
    }

    free(list);
    printf("List Destroyed.\n");
};

void print_linked_list(LinkedList *list) {
    if (list == NULL)
        return;

    Node *current = list->head;
    while (current != NULL) {
        print_node(current);
        current = current->next;
    }
    printf("\n");
};

void print_node(Node *node) {
    printf("[%d] => %s", node->data, node->next ? "" : "NULL");
}

void insert_node(LinkedList* list, int data) {
    if (list == NULL)
        return;

    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    
    Node *tail = NULL,
         *current = list->head;

    while (current) {
        tail = current;
        current = current->next;
    }


    if (tail == NULL) {
        list->head = new_node;
    } else {
        tail->next = new_node;
    }

    list->count++;
};

void remove_node(LinkedList* list, Node* node) {
    if (list == NULL || list->head == NULL || node == NULL)
        return;

    if (list->head == node) {
        printf("Destroying: [%d]\n", node->data);
        Node *next = list->head->next;
        free(list->head);
        list->count--;
        list->head = next;
        return;
    }
    
    Node *current  = list->head,
         *previous = NULL;
    
    while (current != NULL) {
        if (current == node) {
            printf("Destroying: [%d]\n", current->data);
            previous->next = current->next;
            free(current);
            break;
        } else {
            previous = current;
            current = current->next;
        }
    }

    list->count--;
};
