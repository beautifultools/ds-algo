#include "linkedList.h"
#include <stdio.h>

List* make_init_list() {
	List* retVal = (List*)malloc(sizeof(List));
	retVal->head = NULL;
	retVal->inx = NULL;
	retVal->size = 0;
	return retVal;
}


void push_list(List* list, l_data data) {
	push_list_inx(list, data, list->size);
};

int push_list_inx(List* list, l_data data, int inx) {
	if (list->size < inx) return 0;

	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	Node* curNode = list->head;

	for (int i = 1; i < inx; i++) {
		curNode = curNode->next;
	}


	if (curNode) {
		node->next = curNode->next;
		curNode->next = node;
		(list->size)++;
	} else {
		// curNode가 NULL이면 inx가 0으로 head에 넣는다. 
		node->next = list->head;
		list->head = node;
		(list->size)++;
		return 1;
	}
	return 1;
};

l_data pop_list(List* list) {
	return pop_list_inx(list, (list->size) - 1);
};

l_data pop_list_inx(List* list, int inx) {
	if (list->size <= 0 || list->size < inx + 1) return NULL;

	Node * node = list->head;
	Node * node_before = NULL;

	for (int i = 0; i < inx; i++) {
		node_before = node;
		node = node->next;
	}
	if (node_before != NULL) {
		node_before->next = node->next;
	}else{
		list->head = (list->head)->next;
	}

	l_data data = node->data;
	free(node);
	(list->size)--;
	return data;
};


l_data get_data_by_inx(List* list, int inx) {
	if (list->size < ++inx) return NULL;

	Node* node = list->head;
	for (int i = 0; i < inx; i++) {
		node = node->next;
	}

	return node->data;
}
int find_inx_by_data(List* list, l_data data) {
	if (list->size == 0) return 0;
	Node * node = list->head;
	int inx = 0;
	while (1) {
		if (node->data == data) {
			return inx;
		}
		node = node->next;
		inx++;
	}
	return 0;
};
l_data find_data(List* list, l_data data) {
	Node* node = list->head;
	for (int i = 0; i < list->size; i++) {
		if (node->data == data) return data;
		node = node->next;
	}
	return NULL;
};
int init_internal_inx(List* list) {
	if (list->size == 0) return 0;
	list->inx = list->head;
	return 1;
};
int has_next(List * list) {
	Node* node = list->inx;
	if (node == NULL || node->next == NULL) return 0;
	return 1;
};

l_data ret_next_val(List * list) {
	if (!has_next(list)) return NULL;

	Node* node = list->inx;
	node = node->next;
	return node->data;
};

Node* return_last(List * list) {
	if (list->head == NULL)return NULL;
	Node * node = list->head;
	while (1) {
		if (node->next == NULL) return node;
		node = node->next;
	}
};

int is_empty_list(List* list) {
	return list->head == NULL;
};
int destroy_list(List* list) {
	init_internal_inx(list);
	while (has_next(list)) {
		Node* next_node = (list->inx)->next;
		free(list ->inx);
		list ->inx = next_node;
	}
	free(list->inx);
	free(list);
};