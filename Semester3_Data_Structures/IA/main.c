//
// Created by Aditya Ved on 23/11/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

struct employee_record
{
    int  employee_number;
    char employee_name[MAX];
    char employee_designation[MAX];
    struct employee_record *next;
    double employee_salary;
};

struct employee_record * insert_node(struct employee_record *front, int id, char name[], char desg[], double sal);
void display_a_record(struct employee_record *ptr_to_record);
struct employee_record* delete_node(struct employee_record *front, int id);
int search_by_employee_id(struct employee_record *front, int employee_number_to_search);
void display_all_records(struct employee_record  *front);
void menu();
void delete_all_nodes_of_linked_list(struct employee_record * front);

int main()
{
    struct employee_record *singly_linked_list;
    char name[MAX], desig[MAX];
    int choice;
    int employee_num;
    double sal;
    int dummy = 0;

    singly_linked_list = NULL;

    while(dummy == 0)
    {
        menu();
        printf("\n Enter choice :  ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\n Enter the Employee Number: ");
                scanf("%d", &employee_num);
                fflush(stdin);
                printf(" Enter the Employee name: ");
                fgets(name,MAX,stdin);
                fflush(stdin);
                printf(" Enter the Employee Designation: ");
                fgets(desig,MAX,stdin);
                fflush(stdin);
                printf(" Enter the Employee Salary : ");
                scanf("%lf",&sal);
                fflush(stdin);
                singly_linked_list = insert_node(singly_linked_list, employee_num, name, desig, sal);
                break;

            case 2:
                if (singly_linked_list == NULL)
                {
                    printf("\n Employee Records List is empty, deletion operation is invalid\n");
                    break;
                }
                printf("\n\n Enter the employee number to be deleted: ");
                scanf("%d", &employee_num);
                singly_linked_list = delete_node(singly_linked_list, employee_num);
                break;

            case 3:
                if (singly_linked_list == NULL)
                {
                    printf("\n Employee Records List is empty\n");
                    break;
                }
                display_all_records(singly_linked_list);
                break;

            case 4:
                if (singly_linked_list == NULL)
                {
                    printf("\n Employee Records List is empty\n");
                    break;
                }
                printf("\n\n Enter the employee number to be searched: ");
                scanf("%d", &employee_num);
                fflush(stdin);
                search_by_employee_id(singly_linked_list, employee_num);
                break;

            case 5:
                delete_all_nodes_of_linked_list(singly_linked_list);
                exit(0);

            default:
                printf("Invalid option. Please try again.\n");
        }
    }

}



struct employee_record * insert_node(struct employee_record *front, int id, char name[], char desg[], double sal)
{
    struct employee_record *temp;

    temp = (struct employee_record*)malloc(sizeof(struct employee_record));

    if (temp == NULL)
    {
        printf("\n Insufficient memory : Allocation failed \n");
        return front;
    }

    temp->employee_number = id;
    strcpy(temp->employee_name, name);
    strcpy(temp->employee_designation, desg);
    temp->employee_salary = sal;
    temp->next = NULL;

    if(front == NULL) // if the linked list is empty :
    {
        front = temp;
        return(front);
    }

    struct employee_record * ptr_to_last_node = front;

    while(ptr_to_last_node->next != NULL)
    {
        ptr_to_last_node = ptr_to_last_node->next;
    }

    ptr_to_last_node->next = temp;

    return(front);
}

void display_a_record(struct employee_record *ptr_to_record)
{
    printf("\n Employee Details:\n");
    printf("\n Employee No    : %d", ptr_to_record->employee_number);
    printf("\n Name           : %s", ptr_to_record->employee_name);
    printf(" Designation    : %s", ptr_to_record->employee_designation);
    printf(" Salary : %lf\n", ptr_to_record->employee_salary);
    printf("-------------------------------------\n");
}

struct employee_record* delete_node(struct employee_record *front, int id)
{
    struct employee_record *ptr;
    struct employee_record *bptr;

    if (front->employee_number == id)
    {
        ptr = front;
        printf("\n Node deleted:");
        display_a_record(front);
        front = front->next;
        free(ptr);
        return(front);
    }
    for (ptr = front->next, bptr = front; ptr != NULL; ptr = ptr->next,
            bptr = bptr->next)
    {
        if (ptr->employee_number == id)
        {
            printf("Successfully verified existence of employee record with given id\n");
            printf("\n Employee Record deleted:\n");
            printf("The details of the employee whose record got deleted is : \n\n");
            display_a_record(ptr);
            bptr->next = ptr->next;
            free(ptr);
            return(front);
        }
    }
    printf("\n Employee Number %d not found \n\n", id);
    return(front);
}

int search_by_employee_id(struct employee_record *front, int employee_number_to_search)
{
    // returns 1 if employee is found
    // returns 0 if employee is not found

    struct employee_record *ptr;

    for (ptr = front; ptr != NULL; ptr = ptr -> next)
    {
        if (ptr->employee_number == employee_number_to_search)
        {
            printf("\n Employee with given Employee Number was found:");
            display_a_record(ptr);
            return 1;
        }
    }
    printf("\n Employee Number %d not found ", employee_number_to_search);
    return 0;
}

void display_all_records(struct employee_record  *front)
{
    struct employee_record *ptr;

    for (ptr = front; ptr != NULL; ptr = ptr->next)
    {
        display_a_record(ptr);
    }
}

void menu()
{
    printf("\n MAIN MENU \n");
    printf("---------------------------------------------\n");
    printf("Enter option: \n");
    printf("1 to INSERT a record into the database       \n");
    printf("2 to DELETE a record from the database       \n");
    printf("3 to DISPLAY all the records                 \n");
    printf("4 to SEARCH a record in the database                  \n");
    printf("5 to EXIT the program                            \n");
    printf("---------------------------------------------\n");
}

void delete_all_nodes_of_linked_list(struct employee_record * front)
{
    struct employee_record * ptr_iterator = front;
    struct employee_record * temp;
    while(ptr_iterator != NULL)
    {
        temp = ptr_iterator;
        ptr_iterator = ptr_iterator->next;
        free(temp);
    }

}