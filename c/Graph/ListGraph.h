#pragma once
#include "LinkedList.h"

/*
	Graph ADT

	# desc
	The datastructure that represents the linked Objects. 
	A data structure that simply combines a node (N, node) with a trunk (E, edge) that connects the node

	# funcs
	1. make_init_grp : make and initialize graph and return that graph
	2. push_node_grp : push node to graph.
	3. push_rel_grp : push node relation to graph.
	4. del_node_grp : delete node from graph. If there is no data, NULL is returned.
	5. del_rel_grp : delete node relation from graph. If the number of the node is less than 2, NULL is returned.
	6. is_empty_grp: Returns 1 if the queue is empty or 0 if it is not.
	7. destroy_grp: Remove the queue from memory.

	

	# problem
	// list destroy 하는 방법 찾기
	// list에서 데이터 비교 찾기.
	// 
*/

typedef int g_data;

typedef struct g_node {
	List* gd_list;
} G_NODE;

typedef struct _graph {
	List* gn_list;
} Graph;

Graph* make_init_grp();
void push_node_grp(Graph*, g_data);
void push_rel_grp(Graph*, g_data, g_data);
void del_node_grp(Graph*, g_data);
void del_rel_grp(Graph*, g_data, g_data);
int is_empty_grp(Graph*);
void traversal_dfs(Graph*);
void traversal_bfs(Graph*);
void destroy_grp(Graph*);