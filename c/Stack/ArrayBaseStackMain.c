#include <stdio.h>
#include "ArrayBaseStack.h"

int main(void) {
	//Stack�� ���� �� �ʱ�ȭ
	Stack stack;
	StackInit(&stack);

	SPush(&stack, 1); SPush(&stack, 2);
	SPush(&stack, 3); SPush(&stack, 4);

	while (!SIsEmpty(&stack)) {
		prinitf("%d", SPop(&stack));
	}

	return 0;
}