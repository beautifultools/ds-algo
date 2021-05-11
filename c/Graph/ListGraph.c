#include <stdio.h>
#include "ListGraph.h"
#include "LinkedList.h"
#include "ArrayStack.h"
#include "Que.h"

Graph* make_init_grp() {
	Graph* new_grp = (Graph*)malloc(sizeof(Graph));
	new_grp -> gn_list = (List*)malloc(sizeof(List));

};
void push_node_grp(Graph* graph, g_data data) {
	G_NODE* new_data = (G_NODE*)malloc(sizeof(G_NODE));
	push_list(new_data->gd_list, &data);
	push_list(graph->gn_list, new_data);
}
void push_rel_grp(Graph* graph, g_data data1, g_data data2) {
	int i = find_inx_by_data(graph->gn_list, data1);
	G_NODE* gn = (G_NODE*)find_data_by_inx(graph->gn_list, i);
	push_list(gn->gd_list, &data2);
}
void del_node_grp(Graph* graph, g_data data) {
	int i = find_inx_by_data(graph->gn_list, data);
	pop_list_inx(graph->gn_list, i);
}

void del_rel_grp(Graph* graph, g_data data1, g_data data2) {
	int i = find_inx_by_data(graph->gn_list, data1);
	G_NODE* gn = (G_NODE*)find_data_by_inx(graph->gn_list, i);
	int j = find_inx_by_data(gn->gd_list, data2);
	pop_list(gn->gd_list, j);
}

int is_empty_grp(Graph* graph) {
	return graph->gn_list->size <= 0 ? 1 : 0;
}

void traversal_dfs(Graph* graph) {
	Stack* stack = init_stack();
	const int x = graph->gn_list->size;
	
	if (is_empty_grp(graph)) return;
	g_data arr[200];
	int arr_inx = 0;
	List* list = graph->gn_list;
	push_stack(stack, find_data_by_inx(graph->gn_list, 0));
	for (int i = 0; i < list->size; i++) {
		if (is_empty_stack(stack)) return;

		G_NODE* g_node = pop_stack(stack);
		int isDup = 0;
		for (int k = 0; k < list->size; k++) {
			if (arr[k] == find_data_by_inx(g_node->gd_list, 0)) {
				isDup = 1;
				break;
			}
		}

		if (isDup) {
			i--;
			continue;
		}
		g_data gd = find_data_by_inx(g_node->gd_list, 0);
		printf("%d", gd);
		arr[++arr_inx] = gd;
		for (int j = 1; j < g_node->gd_list->size; j++) {
			push_stack(stack, find_data_by_inx(g_node->gd_list, j));
		}
	}
}

void traversal_bfs(Graph* graph) {
	Que* que = make_init_que();

	if (is_empty_grp(graph)) return;

	g_data arr[200];
	int arr_inx = 0;
	List* list = graph->gn_list;
	push_que(que, find_data_by_inx(graph->gn_list, 0));
	for (int i = 0; i < list->size; i++) {
		if (is_empty_que(que)) return;

		G_NODE* g_node = pop_stack(que);
		int isDup = 0;
		for (int k = 0; k < list->size; k++) {
			if (arr[k] == find_data_by_inx(g_node->gd_list, 0)) {
				isDup = 1;
				break;
			}
		}

		if (isDup) {
			i--;
			continue;
		}
		g_data gd = find_data_by_inx(g_node->gd_list, 0);
		printf("%d", gd);
		arr[++arr_inx] = gd;
		for (int j = 1; j < g_node->gd_list->size; j++) {
			push_stack(que, find_data_by_inx(g_node->gd_list, j));
		}
	}
}

void destroy_grp(Graph* graph) {
	//list detroy 하는 방법 찾아서 보기
}
