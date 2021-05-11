#pragma once

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
	7. is_full_grp: Returns 1 if the queue is full or 0 if it is not.
	8. destroy_grp: Remove the queue from memory.



	# problem
	2�� �����Ϳ� 2�� �迭�� �ٸ���. 123456 �̸� 2�� �迭�� 123456�̷��� �Ϸ��� �޸�. 2�� �����Ͷ��. ��ĭ�� �ڴ�. �����ߴ� ��Ұ� �ƴ϶� �ٸ� ��ҷ� ����.
*/

#define MAX_ARRAY_SIZE_GRAPH 200

typedef int g_data;

typedef struct _graph {
	g_data g_arr[MAX_ARRAY_SIZE_GRAPH];
	int rel_arr[MAX_ARRAY_SIZE_GRAPH][MAX_ARRAY_SIZE_GRAPH];
	int size;
} Graph;

Graph* make_init_grp();
int push_node_grp(Graph*, g_data);
int push_rel_grp(Graph*, g_data, g_data);
int del_node_grp(Graph*, g_data);
int del_rel_grp(Graph*, g_data, g_data);
int is_empty_grp(Graph*);
int is_full_grp(Graph*);
int find_inx_grp(Graph*, g_data);
void traversal_dfs(Graph*);
void traversal_bfs(Graph*);
void destroy_grp(Graph*);

