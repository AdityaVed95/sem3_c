//
// Created by Aditya Ved on 16/08/22.
//

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    unsigned capacity;
    int* int_pointer;

};
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    // stack is a pointer of type [ struct Stack ]

    stack->capacity = capacity;
    stack->top = -1;
    stack->int_pointer = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}
int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}
void push(struct Stack* stack, int item)
{
    if (isFull(stack))
        return;
    stack->int_pointer[++stack->top] = item;
    printf("%d pushed to stackn", item);
}
int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->int_pointer[stack->top--];
}
int peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->int_pointer[stack->top];
}
int main()
{
    struct Stack* stack = createStack(100);
    push(stack, 11);
    push(stack, 12);
    push(stack, 33);
    printf("%d popped from stackn", pop(stack));
    return 0;
}