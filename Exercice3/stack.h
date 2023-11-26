#ifndef __STACK__H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_FLNM 100

// Structure de la pile basée sur un fichier
typedef struct {
    char filename[MAX_FLNM];
    int fd; // file descriptor of the open file
    int top_off; // final offset
} stack_t;

// Prototypes des fonctions pour la pile basée sur un fichier
void set_file(stack_t *, char *); // special function to determine the file to be used
void init_stack_file(stack_t *); // initialize the data structure
int push_stack_file(stack_t *, int); // push value into stack
int pop_stack_file(stack_t *, int *); // pops top value from stack
void display_stack_file(stack_t *); // displays the contents of the stack

#endif // __STACK__H__
