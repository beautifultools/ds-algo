#include <stdio.h>
#include "Que.h"

Que* make_init_que() {
	Que* newQue = (Que*)malloc(sizeof(Que));
	newQue->arr_size = MAX_SIZE_ARRAY;
	newQue->front = 0;
	newQue->rear = 0;
	return newQue;
};
int push_que(Que* que, q_data data) {
	if (is_full_que(que))
		return 0;

	(que->arr)[que->rear] = data;
	que->rear = (que->rear + 1) % que->arr_size;

	return 1;
};
q_data peek_que(Que * que) {
	if (is_empty_que(que))
		return NULL;
	return (que->arr)[que->front];
};

q_data pop_que(Que * que) {
	if (is_empty_que(que))
		return NULL;
	q_data retVal = (que->arr)[(que->front)++];
	que->front = que->front % que->arr_size;
	return retVal;
};

int is_full_que(Que * que) {
	return (que->rear + 1) % que->arr_size == que->front;
};

int is_empty_que(Que * que) {
	return que->front == que->rear;
};
void destroy_que(Que * que) {
	que->front = 0;
	que->rear = 0;
};