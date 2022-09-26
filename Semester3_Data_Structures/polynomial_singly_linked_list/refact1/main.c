//
// Created by Aditya Ved on 22/09/22.
//

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int power;
    double coefficient;
    struct Node * ptr_next;

};

struct Node * create_polynomial(int);
struct Node * create_ll(double , int);
void add_node_at_end_of_ll(double , int  , struct Node ** );
void display_ll(struct Node * );
void destroy_ll(struct Node *);

struct Node * create_multiply_ll(int );
void search_in_multiply_ll_and_add_value_into_multiply_ll(double , int, struct Node *  );

struct Node * add_and_print_two_polynomials(struct Node *, struct Node *);
struct Node * subtract_and_print_two_polynomials(struct Node *, struct Node *);
struct Node * multiply_and_print_two_polynomials(struct Node *, struct Node *);
void destroy_polynomials(struct Node *,struct Node *, struct Node *, struct Node *, struct Node *);



int main()
{
    // the purpose of storing these pointers in the main function is that we can free these pointers during the end of the program
    struct Node * polynomial1;
    struct Node * polynomial2;
    struct Node * sum_of_polynomials;
    struct Node * difference_of_polynomials;
    struct Node * multiplication_of_polynomials;

    polynomial1 = create_polynomial(1); // create 1st polynomial
    polynomial2 = create_polynomial(2); // create 2nd polynomial
    // polynomial1 and polynomial2 are nothing but pointers pointing to
    // the start of the two respective linked lists

    int dummy = 1,response;

    while (dummy == 1)
    {
        printf("Enter 1 to add two polynomials and display the result\n");
        printf("Enter 2 to subtract two polynomials and display the result\n");
        printf("Enter 3 to multiply two polynomials and display the result\n");
        printf("Enter 4 to exit the program and destroy the created polynomials\n");


        scanf("%d",&response);
        fflush(stdin);

        if(response == 1)
        {
            sum_of_polynomials = add_and_print_two_polynomials(polynomial1,polynomial2); // this fxn will add two polynomials , store the result in the sum_ll and then destroy
        }

        else if (response == 2)
        {
            difference_of_polynomials = subtract_and_print_two_polynomials(polynomial1, polynomial2);
        }

        else if(response == 3)
        {
            multiplication_of_polynomials = multiply_and_print_two_polynomials(polynomial1, polynomial2);
        }

        else if(response == 4)
        {
            printf("Destroying all Polynomials.....................\nFreeing Up Memory.....................\n");
            destroy_polynomials(polynomial1, polynomial2, sum_of_polynomials, difference_of_polynomials,multiplication_of_polynomials);
            printf("Successfully Destroyed Polynomials.....................\nExiting.....................");
            break;
        }

        else
        {
            printf("Invalid input , please try again\n");
        }

    }

    printf("\n");
    return 0;
}


struct Node * create_polynomial(int nth_time)
{
    // this function creates a polynomial by taking user from the input
    printf("Welcome to the creation of the %dth polynomial\n",nth_time);
    printf("Input the terms inside the polynomial from higher degree to lower degree only\n");
    int pow;
    double coeff;

    printf("Enter the coefficient of 1st term\n");
    scanf("%lf",&coeff);
    fflush(stdin);
    printf("Enter the power of 1st term\n");
    scanf("%d",&pow);
    fflush(stdin);


    struct Node * head = create_ll(coeff,pow); // head is a pointer to the 1st node of the linked list
    struct Node * ptr_previous = head;
    int dummy = 1,response;
    int counter = 2;

    while (dummy == 1)
    {
        printf("Enter 1 to add a term to your polynomial\n");
        printf("Enter 2 to exit the creation of current polynomial\n");
        scanf("%d",&response);
        fflush(stdin);

        if(response == 1)
        {
            printf("Enter the coefficient of %dth term\n",counter);
            scanf("%lf",&coeff);
            fflush(stdin);
            printf("Enter the power of %dth term\n",counter);
            scanf("%d",&pow);
            fflush(stdin);

            add_node_at_end_of_ll(coeff,pow,&ptr_previous);
            counter++;
        }
        else if(response == 2)
        {
            break;
        }

        else
        {
            printf("Invalid input, please try again\n");
        }

    }


    return head;
}


struct Node * create_ll(double coeff, int pow)
{
    // this is the function to create 1st node of the linked list
    // this function returns a pointer to the 1st node of the created linked list
    struct Node * head = (struct Node *) malloc(sizeof (struct Node));
    head->coefficient = coeff;
    head->power = pow;
    head->ptr_next = NULL;

    return head;
}


void add_node_at_end_of_ll(double coeff, int pow, struct Node ** ptr_to_ptr_to_previous)
{
    //ptr_previous= *(ptr_to_ptr_to_previous);
    // this function will also update the value of ptr_previous after inserting a new node at the end

    struct Node * node = (struct Node *) malloc(sizeof (struct Node));
    node->power=pow;
    node->coefficient = coeff;
    node->ptr_next = NULL;
    (*(ptr_to_ptr_to_previous))->ptr_next = node;
    (*(ptr_to_ptr_to_previous))= node;
}


void display_ll(struct Node * head)
{
    // this function is used to display the linked list
    while (head!=NULL)
    {
        printf("coefficient : %lf\n",head->coefficient);
        printf("power : %d\n",head->power);
        printf("=================================\n");
        head = head->ptr_next;
    }

}

struct Node * add_and_print_two_polynomials(struct Node * polynomial1, struct Node *polynomial2)
{
    struct Node * sum_poly = NULL;
    struct Node * ptr_previous = NULL;


    int counter=1;

    while(polynomial1 != NULL || polynomial2!= NULL)
    {
        // if polynomial1 has exhausted and only polynomial2 is left
        // directly add the contents of polynomial1 into the linked list without the need of performing any operation
        if (polynomial1 == NULL)
        {
            add_node_at_end_of_ll(polynomial2->coefficient,polynomial2->power,&ptr_previous);
            polynomial2=polynomial2->ptr_next;
        }

        // if polynomial2 has exhausted and only polynomial1 is left
        else if(polynomial2 == NULL)
        {
            add_node_at_end_of_ll(polynomial1->coefficient,polynomial2->power,&ptr_previous);
            polynomial1=polynomial1->ptr_next;
        }

        else
        {
            if (polynomial1->power == polynomial2->power)
            {
                double sum = polynomial1->coefficient + polynomial2->coefficient;
                int power = polynomial1->power;

                if(counter == 1)
                {
                    sum_poly = create_ll(sum,power); // create a ll which will hold the final sum
                    ptr_previous = sum_poly;
                }

                else
                {
                    add_node_at_end_of_ll(sum,power,&ptr_previous);
                }

                polynomial1 = polynomial1->ptr_next;
                polynomial2 = polynomial2->ptr_next;
            }

            else if (polynomial1->power > polynomial2->power)
            {
                if(counter == 1)
                {
                    sum_poly = create_ll(polynomial1->coefficient,polynomial1->power);
                    ptr_previous=sum_poly;
                }
                else
                {
                    add_node_at_end_of_ll(polynomial1->coefficient,polynomial1->power,&ptr_previous);
                }

                polynomial1=polynomial1->ptr_next;
            }

            else if (polynomial1->power < polynomial2->power)
            {

                if(counter == 1)
                {
                    sum_poly = create_ll(polynomial2->coefficient,polynomial2->power);
                    ptr_previous=sum_poly;
                }

                else
                {
                    add_node_at_end_of_ll(polynomial2->coefficient,polynomial2->power,&ptr_previous);
                }

                polynomial2 = polynomial2->ptr_next;
            }
        }



        counter++;

    }
    printf("The sum of two polynomials is :\n");
    display_ll(sum_poly);
    return sum_poly;
}

struct Node * subtract_and_print_two_polynomials(struct Node * polynomial1, struct Node *polynomial2)
{
    // this fxn does polynomial1 - polynomial2
    struct Node * diff_poly= NULL;
    struct Node * ptr_previous = NULL;
    int counter = 1;

    while(polynomial1 != NULL || polynomial2!= NULL)
    {


        if (polynomial1 == NULL)
        {
            double temp = -(polynomial2->coefficient);
            add_node_at_end_of_ll(temp,polynomial2->power,&ptr_previous);
            polynomial2=polynomial2->ptr_next;
        }

        else if(polynomial2 == NULL)
        {
            add_node_at_end_of_ll(polynomial1->coefficient,polynomial2->power,&ptr_previous);
            polynomial1=polynomial1->ptr_next;
        }

        else
        {
            if(polynomial1->power == polynomial2->power)
            {
                double differ = polynomial1->coefficient - polynomial2->coefficient;
                int power = polynomial1->power;

                if(counter == 1)
                {
                    diff_poly = create_ll(differ,power);
                    ptr_previous = diff_poly;
                }
                else
                {
                    add_node_at_end_of_ll(differ,power,&ptr_previous);
                }

                polynomial1=polynomial1->ptr_next;
                polynomial2=polynomial2->ptr_next;
            }

            else if(polynomial1->power > polynomial2->power)
            {
                if(counter == 1)
                {
                    diff_poly =create_ll(polynomial1->coefficient,polynomial1->power);
                    ptr_previous = diff_poly;
                }
                else
                {
                    add_node_at_end_of_ll(polynomial1->coefficient,polynomial1->power,&ptr_previous);
                }

                polynomial1=polynomial1->ptr_next;
            }

            else if(polynomial1->power < polynomial2->power)
            {
                if(counter == 1)
                {
                    double temp = -(polynomial2->coefficient);
                    diff_poly= create_ll(temp,polynomial2->power);
                    ptr_previous = diff_poly;
                }
                else
                {
                    double temp = -(polynomial2->coefficient);
                    add_node_at_end_of_ll(temp,polynomial2->power,&ptr_previous);
                }

                polynomial2 = polynomial2->ptr_next;
            }
        }

        counter++;

    }

    printf("The difference of two polynomials is :\n");
    display_ll(diff_poly);
    return diff_poly;

}

struct Node * multiply_and_print_two_polynomials(struct Node * polynomial1, struct Node *polynomial2)
{

    struct Node * ptr_previous = NULL;

    int max_power = polynomial1->power + polynomial2->power;
    struct Node * multiply_poly = create_multiply_ll(max_power);

    while(polynomial1 != NULL)
    {
        struct Node * temp_polynomial2 = polynomial2;

        while (temp_polynomial2 != NULL)
        {
            double coeff = polynomial1->coefficient * temp_polynomial2->coefficient;
            int power = polynomial1->power + temp_polynomial2->power;
            search_in_multiply_ll_and_add_value_into_multiply_ll(coeff, power,multiply_poly);
            temp_polynomial2=temp_polynomial2->ptr_next;
        }


        polynomial1= polynomial1->ptr_next;
    }

    printf("The product of two polynomials is :\n");
    display_ll(multiply_poly);
    return multiply_poly;
}

void destroy_polynomials(struct Node *polynomial1,struct Node *polynomial2, struct Node * sum_poly, struct Node * diff_poly, struct Node * multiply_poly)
{
    destroy_ll(polynomial1);
    destroy_ll(polynomial2);
    destroy_ll(sum_poly);
    destroy_ll(diff_poly);
    destroy_ll(multiply_poly);

}

void destroy_ll(struct Node * current_ptr)
{
    // the current_ptr that is passsed to this function is nothing but the pointer to the 1st node of the linked list

    struct Node * next_pointer = NULL;

    while(current_ptr != NULL)
    {
        next_pointer = current_ptr->ptr_next;
        free(current_ptr);
        current_ptr = next_pointer;
    }

}

struct Node * create_multiply_ll(int max_power)
{
    // creates a ll in which the nodes of the ll :
    // have the coeff = 0 , and their powers are from higher power to lower power : considering each node of the ll

    struct Node * head = create_ll(0,max_power);
    max_power--;
    struct Node * ptr_previous = head;

    while(max_power >= 0)
    {
        add_node_at_end_of_ll(0,max_power,&ptr_previous);
        max_power -- ;
    }

    return head;
}

void search_in_multiply_ll_and_add_value_into_multiply_ll(double coeff, int power , struct Node * head_ptr)
{
    struct Node * ptr_to_required_node = head_ptr;

    while (ptr_to_required_node != NULL)
    {
        if(ptr_to_required_node->power == power)
        {
            break;
        }
        ptr_to_required_node = ptr_to_required_node->ptr_next;
    }

    ptr_to_required_node->coefficient = ptr_to_required_node->coefficient + coeff;

}