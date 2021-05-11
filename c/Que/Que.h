#pragma once

/*
	Que ADT

	# desc
	FIFO(First In First Out) Datastructure

	# funcs
	1. : Makes a queue of a predetermined size.
	2. push_que: Put data into the queue. Returns 0 if it is already full.
	3. peek_que: Check the data in the queue. The confirmed data will not be erased. If there is no data, NULL is returned.
	4. pop_que: Get data from the queue. Imported data is lost from the queue. If there is no data, NULL is returned.
	5. is_full_que: Returns 1 if the queue is full and 0 if it is not full.
	6. is_empty_que: Returns 1 if the queue is empty or 0 if it is not.
	7. destroy_que: Remove the queue from memory.

	# problem
	This queue could use MAX_SIZE -1 as it's size. To solve it, new checking empty func required.
*/

#define MAX_SIZE_ARRAY  10

typedef int q_data;

typedef struct _que {
	q_data arr[MAX_SIZE_ARRAY];
	int arr_size;
	int front;
	int rear;
} Que;

Que* make_init_que();
int push_que(Que*, q_data);
q_data peek_que(Que*);
q_data pop_que(Que*);
int is_full_que(Que*);
int is_empty_que(Que*);
void destroy_que(Que*);
