#include "LinkedList.h"
#include <stdio.h>

List* make_init_list() {
	List* retVal = (List*)malloc(sizeof(List));
	retVal->head = NULL;
	retVal->index = NULL;
	retVal->size = 0;
	return retVal;
}

int push_list(List* list, l_data data) {
	return push_list_inx(list, data, list->size);
};

int push_list_inx(List* list, l_data data, int index) {
	if (list->size < index) return 0;
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	if (index == 0) {
		node->next = list->head;
		list->head = node;
		(list->size)++;
		return 1;
	}

	Node* curNode = list->head;

	for (int i = 1; i < index; i++) {
		curNode = curNode->next;
	}

	node->next = curNode->next;
	curNode->next = node;
	(list->size)++;
	return 1;
};

l_data pop_list(List* list) {
	return pop_list_inx(list, (list->size) - 1);
};

l_data pop_list_inx(List * list, int index) {
	l_data data = NULL;
	if (list->size <= 0 || list->size < index + 1) return data;

	Node * node = list->head;
	Node * node_before = NULL;

	for (int i = 0; i < index; i++) {
		node_before = node;
		node = node->next;
	}

	if (node_before != NULL) {
		node_before->next = node->next;
	}
	else
	{
		list->head = (list->head)->next;
	}

	data = node->data;
	free(node);
	(list->size)--;
	return data;
};

int find_inx_by_data(List * list, l_data data) {
	if (list->size == 0) return 0;
	Node * node = list->head;
	int index = 0;
	while (1) {
		if (node->data == data) {
			return index;
		}
		node = node->next;
		index++;
	}
	return 0;
};
l_data find_data_by_inx(List * list, int index) {
	if (list->size < ++index) return NULL;
	Node* node = list->head;
	for (int i = 0; i < index; i++) {
		node = node->next;
	}
	return node->data;
};
int init_internal_inx(List * list) {
	if (list->size == 0) return 0;
	list->index = list->head;
	return 1;
};
int has_next(List * list) {
	Node* node = list->index;
	if (node == NULL || node->next == NULL) return 0;
	return 1;
};

l_data ret_next_val(List * list) {
	if (!has_next(list)) return NULL;

	Node* node = list->index;
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

int is_empty_list(List * list) {
	return list->head == NULL;
};
int destroy_list(List * list) {
	init_internal_inx(list);
	while (has_next(list)) {
		Node* next_node = (list->index)->next;
		free(list->index);
		list->index = next_node;
	}
	free(list->index);
	free(list);
};

Node* find_data(List* list, l_data data) {
	if (list->size <=0) return NULL;
	Node* node = list->head;
	for (int i = 0; i < list->size; i++) {
		if (node->data == data) {
			return node;
		}
		node = node->next;
	}
	return (void*)0;
};