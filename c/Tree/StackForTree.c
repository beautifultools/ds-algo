#include "StackForTree.h"
#include <stdio.h>
#include <stdlib.h>

Stack* init_stack() {
	Stack* new_stack = (Stack*)malloc(sizeof(Stack));
	new_stack->size = MAX_SIZE_ARRAY;
	new_stack->inx = -1;
	return new_stack;
}

/*
Stack* init_stack(int size) {
	Stack* new_stack = (Stack*)malloc(sizeof(Stack) + size * sizeof(s_data));
	new_stack->size = size;
	new_stack->inx = -1;
	return new_stack;
}
*/

int is_empty_stack(Stack* stack) {
	return stack->inx < 0;
}

int is_full_stack(Stack* stack) {
	return (stack->inx + 1) >= stack->size;
}
int push_stack(Stack * stack, s_data data) {
	if (is_full_stack(stack))
		return 0;
	(stack->arr)[++(stack->inx)] = data;
	return 1;
}
s_data pop_stack(Stack * stack) {
	if (is_empty_stack(stack))
		return NULL;
	s_data _retData = (stack->arr)[stack->inx];
	(stack->arr)[(stack->inx)--] = NULL;
	return _retData;
}

s_data peek_stack(Stack * stack) {
	if (is_empty_stack(stack))
		return 0;
	return	(stack->arr)[stack->inx];
}

// Can this func return a different value if got an error like java try, catch ?
int destroy_stack(Stack * *stack) {
	if (stack == NULL)
		return 0;

	free(*stack);
	*stack = NULL;
	return 1;
}