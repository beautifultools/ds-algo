#include <stdio.h>
#include "ArrayHeap.h"

int main() {
	Heap* heap = make_init_heap();
	push_heap(heap, 3);
	push_heap(heap, 4);
	push_heap(heap, 4);
	push_heap(heap, 5);
	push_heap(heap, 10);

	printf("%d\n", pop_heap(heap));
	printf("%d\n", pop_heap(heap));
	printf("%d\n", pop_heap(heap));
	printf("%d\n", pop_heap(heap));
	printf("%d\n", pop_heap(heap));
	printf("%d\n", pop_heap(heap));
	
	destroy_heap(heap);
}