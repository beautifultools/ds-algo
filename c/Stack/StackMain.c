#include <stdio.h>
#include "ArrayStack.h"

/*
	This stack main contains funcs to implement simple algorithm using stack.
*/
#if 0
// stack operation check
void main() {
	Stack* stack = init_stack(5);
	push_stack(stack, 5);
	push_stack(stack, 4);
	push_stack(stack, 4);

	int* tmp = stack->arr;
	tmp = tmp + 3;

	printf("%d", pop_stack(stack));
	printf("%d", pop_stack(stack));
	printf("%d", pop_stack(stack));

	destroy_stack(stack);
	free(tmp);
	printf("ok");
	//printf("%d", pop_stack(stack));
}

/*
const char const* make_array(char* p)
{
	p = (char*)malloc(sizeof(char) * 5);
	return p;

	const char* k = 100;
	k = 200;
	char* p = &k;
}
*/
#endif

/* Determine whether the input string is an operator or not */
int is_opr(char opr) {
	return opr == '+' || opr == '-' || opr == '*' || opr == '/';
}

/* A function that returns the ranking of the operation of the input operator */
int val_opr(char opr) {
	if (opr == '+' || opr == '-')
		return 1;
	else if (opr == '*' || opr == '/')
		return 2;

	return 0;
}

/* A function that compares the ranking of two operators */
int cmp_opr(char opr1, char opr2) {
	return val_opr(opr1) >= val_opr(opr2);
}

/* A sub calculator created for the purpose of using the calculation functions that the CPU handles */ 
int subCal(char opr, int a, int b) {
	if (opr == '+') return a + b;
	else if (opr == '-') return a - b;
	else if (opr == '*') return a * b;
	else if (opr == '/') {
		if (b == 0) {
			return 0;
		}
		return a / b;
	}
}

/* A function that gets the final value from an array converted from a moderate operator to a back operator. */ 
int cal_fi_val(char arr[]) {
	Stack* stack = init_stack(10);

	int inx = 0;
	while (arr[inx] != NULL) {
		char tmp = arr[inx++];
		if (is_opr(tmp)) {

			int a = pop_stack(stack) - '0';
			int b = pop_stack(stack) - '0';

			push_stack(stack, subCal(tmp, b, a) + '0');

		}
		else {
			push_stack(stack, tmp);
		}
	}
	int ret_tmp = pop_stack(stack) - '0';
	//destroy_stack(stack);
	return ret_tmp;
}

/* A function that converts a moderate operator to a postfix operator */ 
char* cvt_infix_to_postfix(char arr[], char ret_arr[]) {

	Stack* st_opr = init_stack();
	int inx = 0;
	int ret_inx = 0;

	while (arr[inx] != NULL) {

		char tmp = arr[inx++];

		if (!is_opr(tmp)) {
			ret_arr[ret_inx++] = tmp;
			continue;
		}

		if (is_empty_stack(st_opr)) {
			push_stack(st_opr, tmp);
		}

		else {
			while (cmp_opr(peek_stack(st_opr), tmp)) {
				ret_arr[ret_inx++] = pop_stack(st_opr);
			}
			push_stack(st_opr, tmp);
		}
	}

	while (!is_empty_stack(st_opr)) {
		ret_arr[ret_inx++] = pop_stack(st_opr);
	}
	ret_arr[ret_inx] = NULL;
	destroy_stack(&st_opr);

	return ret_arr;
}



int main() {
	char* arr = "3+2*5/2";
	//char arr[10] = {'5','+','4','*','3','+','2', NULL};
	char ret_arr[10];
	cvt_infix_to_postfix(arr, ret_arr);
	int fiVal = cal_fi_val(ret_arr);
	printf("postfix : %s\n", ret_arr);
	printf("result : %d", fiVal);
	return 0;
}