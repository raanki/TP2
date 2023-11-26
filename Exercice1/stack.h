#ifndef __STACK__H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct stack 
{
    int tab[MAX];
    int top;
} stack_t;

void init_stack_array(stack_t *); // initialize the data structure
int push_stack_array(stack_t *, int); // push value into stack
int pop_stack_array(stack_t *, int *); // pops top value from stack
int top_stack_array(stack_t *, int *); // returns top value of stack
void display_stack_array(stack_t *); // displays the contents of the stack

#endif // __STACK__H__
