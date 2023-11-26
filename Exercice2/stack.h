#ifndef __STACK__H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int val;
    struct node *next;
} node_t;

typedef struct stack 
{
    node_t *top;
} stack_t;

void init_stack_list(stack_t *); // initialize the data structure
int push_stack_list(stack_t *, int); // push value into stack
int pop_stack_list(stack_t *, int *); // pops top value from stack
void display_stack_list(stack_t *); // displays the contents of the stack

#endif