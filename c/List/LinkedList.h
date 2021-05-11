#pragma once
/*created by humblejohn 2019.04.27*/

/*
	Linked List ADT

	# desc
	It has a node inside and implements the list through the node. 
	Each node has data and an address value that points to the next node.

	The list contains the head with the address value of the first node, the index for the for statement, and size indicating the total size.

	# funcs
	-. make_init_list : make and initialize list
	-. push_list : Check if the head is empty, and if not, put it in the head. If the head is empty, create a new node, find the last node, and put it next to the next node.
	-. push list_inx : Find the corresponding index. Returns -1 if the input index is greater than the current size. Finds the node in the index immediately preceding the input index. Create a new node and insert the next value of the node found in the next value. Put the address value of the current node in the next value of the immediately preceding node.
	-. pop_list : If it is empty, it returns -1. If it is not empty, find the last node, save the data and free it, and change the next value of the last node to null. Returns the last saved data.
	-. get_data_by_inx: Returns null if it is empty or the input index is larger than size. If not, return the data in that index.
	-. pop_list_inx : Returns -1 if it is empty or the input index is larger than size. Otherwise, it finds the address value of the next node corresponding to the current node, and changes the next value of the previous node to the address value of the corresponding node. Save and free the data of the node. Finally, the data is returned.
	-. find_inx_by_data : If it is empty, it returns -1. If not empty, compare the data values ​​from head. Searches to the end and returns 1 if the value is in the middle. If there is no value, 0 is returned.
	-. find_data: find data and return Node of that. Returns null if it is empty or the data does not exist.
	-. init_internal_inx : Put the address value of head in the index.
	-. has_next : Check the next value of the node pointed to by the current index and return 1 or 0 according to the null value.
	-. return_last : Let index point to next and return the data of the node pointed to by index.
	-. is_empty_list : Check if list is empty
	-. destroy_list : Destroy list
*/


/* declare variables */
typedef int l_data;

typedef struct _node {
	l_data data;
	struct _node* next;
} Node;

typedef struct linked_list {
	Node* head;
	Node* inx;
	int size;
} List;

/* declare funcs */
List* make_init_list();
void push_list(List*, l_data);
int push_list_inx(List*, l_data, int);
l_data pop_list(List*);
l_data pop_list_inx(List*, int);
l_data get_data_by_inx(List*, int);
int find_inx_by_data(List*, l_data);
l_data find_data(List*, l_data);
int init_internal_inx(List*);
int has_next(List*);
l_data ret_next_val(List* list);
Node* return_last(List*);
int is_empty_list(List*);
int destroy_list(List*);