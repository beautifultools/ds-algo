#include <stdio.h>
#include "UsefulHeap.h"

int DataPriorityComp(char ch1, char ch2) {
	return ch2 - ch1;
}

int main(void) {
	Heap heap;
	HeapInit(&heap, DataPriorityComp);

	HInsert(&heap, 'a');
	HInsert(&heap, 'b');
	HInsert(&heap, 'c');
	printf("%c\n", HDelete(&heap));

	HInsert(&heap, 'a');
	HInsert(&heap, 'b');
	HInsert(&heap, 'c');
	printf("%c\n", HDelete(&heap));

	while (!HIsEmpty(&heap))
		printf("%c \n", HDelete(&heap));

	return 0;

}