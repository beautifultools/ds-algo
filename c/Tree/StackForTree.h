#pragma once
#include"Tree.h"

/*
	Stack ADT

	# funcs
	1. init_stack: Enter the size of the stack and create an empty stack.
	2. is_empty: Checks if the stack is empty. Returns 1 if it is empty, 0 if it is not empty.
	3. is_full: Checks whether the stack is full. Returns 1 if there is a difference, 0 if it is not.
	4. push_stack: puts data into the stack. Returns 1 if successful, 0 if failed.
	5. pop_stack: Stack data is extracted. The extracted data disappears from the stack. If there is no data to extract, NULL is returned.
	6. peek_stack: only checks the last data. The data does not disappear from the stack. If there is no data to extract, NULL is returned.
	7. destroy_stack: safely removes the stack. It releases the memory of the array declared in.
*/

#define MAX_SIZE_ARRAY 200
/* declare variables */
typedef Node* s_data;

/**/
typedef struct _stack {
	s_data arr[MAX_SIZE_ARRAY];
	int size;
	int inx;
} Stack;

/*
typedef struct _stack {
	int size;
	int inx;
	s_data arr[];
} Stack;
*/

/* declare funcs */
Stack* init_stack();
// Stack* init_stack(int);
int is_empty_stack(Stack*);
int is_full_stack(Stack*);
int push_stack(Stack*, s_data);
s_data pop_stack(Stack*);
s_data peek_stack(Stack*);
int destroy_stack(Stack*);

