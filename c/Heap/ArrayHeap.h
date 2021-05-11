#pragma once

/* Heap ADT
	Heap is a kind of complete binary tree.
	It is used for priority queues and Huffman codes, which are lossless compression algorithms.

	# features
	It allows duplicate.
	It coulbe be implemented by array, dynamic allocation. But using array is more efficiency in heap.

	# funcs
	- make_init_heap : make and initialize heap. return maden heap.
	- push_heap : Add data to heap. balancing occured after adding.
	- peek_heap : checking the value in the root.
	- pop_heap : remove and return data in the root.
	- is_empty : check if heap is empty.
	- is_full : check if heap is full.
	- destroy_heap : release all memory of the heal
 */

#define MAX_SIZE_HEAP 200

typedef int h_data;

typedef struct _heap {
	h_data h_arr[MAX_SIZE_HEAP];
	int inx;
} Heap;

Heap* make_init_heap();
int push_heap(Heap*, h_data);
h_data peek_heap(Heap*);
h_data pop_heap(Heap*);
int is_empty(Heap*);
int is_full(Heap*);
int destroy_heap(Heap*);
