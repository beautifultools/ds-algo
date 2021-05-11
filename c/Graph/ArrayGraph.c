#include "ArrayGraph.h"
#include "ArrayStack.h"
#include "Que.h"

Graph* make_init_grp() {
	Graph* graph = (Graph*)malloc(sizeof(Graph));

	for (int i = 0; i < MAX_ARRAY_SIZE_GRAPH; i++) {
		graph->g_arr[i] = 0;
		for (int j = 0; j < MAX_ARRAY_SIZE_GRAPH; j++) {
			graph->rel_arr[i][j] = 0;
		}
	}
	
	graph->size = 0;
	return graph;
};
int push_node_grp(Graph* graph, g_data data) {
	if (is_full_grp(graph)) {
		return 0;
	}
	(graph->g_arr)[(graph->size)++] = data;
	return 1;
}

int push_rel_grp(Graph* graph, g_data from, g_data to) {
	return set_rel_grp(graph, from, to, 1);
}
int del_node_grp(Graph* graph, g_data data) {
	if (is_empty_grp(graph)) {
		return 0;
	}
	int inx = -1;
	g_data arr[] = graph->g_arr;
	for (int i = 0; i < graph->size; i++) {
		if (arr[i] == data) {
			inx = i;
			break;
		}
	}

	if (inx == -1) {
		return 0;
	}

	int size = graph->size--;
	int rel_arr[MAX_ARRAY_SIZE_GRAPH][MAX_ARRAY_SIZE_GRAPH] = graph->rel_arr;

	for (int i = inx; i <= size; i++) {
		arr[i] = arr[i + 1];
	}

	for (int i = 0; i < inx; i++) {
		for (int j = inx; j < size; j++) {
			rel_arr[i][j] = rel_arr[i][j + 1];
		}
	}

	for (int i = inx; i <= size; i++) {
		for (int j = 0; j <= size; j++) {
			if (j < inx) {
				rel_arr[i][j] = rel_arr[i + 1][j];
			}
			else {
				rel_arr[i][j] = rel_arr[i + 1][j + 1];
			}
		}
	}


};

int del_rel_grp(Graph* graph, g_data from, g_data to, int rel) {
	return set_rel_grp(graph, from, to, 0);
}

int set_rel_grp(Graph* graph, g_data from, g_data to, int rel) {
	int size = graph->size;
	int inx1 = 0;
	int inx2 = 0;
	for (int i = 0; i < size; i++) {
		if (graph->g_arr[i] == from) {
			inx1 = i;
		}

		if (graph->g_arr[i] == to) {
			inx2 = i;
		}
	}

	if (!(inx1 && inx2)) {
		return 0;
	}
	
	(graph->rel_arr)[from][to] = rel;
}

int is_full_grp(Graph* graph) {
	return graph->size >= MAX_ARRAY_SIZE_GRAPH;
}

int is_empty_grp(Graph* graph) {
	return graph->size <= 0;
}

void traversal_bfs(Graph* graph) {
	Que* que = make_init_que();
	push_que(que, (q_data)(graph->g_arr)[0]);
	do
	{
		g_data data = pop_que(que);
		printf("%d\n", data);
		
		int inx = find_inx_grp(graph, data);
		for (int i = 0; i < graph->size; i++) {
			int** arr = graph->rel_arr; 
			if (arr[inx][i] == 1) {
				push_que(que, (q_data)graph->g_arr[i]);
			}
		}

	} while (!is_empty_que(que));
		
	// ó�� ����� ������ �Ǿ� �ִ� ��� ��带 ť�� �ִ´�.
	// �ʺ� �켱�̶�� �ϴ� ���� �� ���� �ִ� ��� ���� �� ��� ���� ���̴�.
	// �Ѱ��� ��带 ���� �ڽĿ� �� ������ �� �ڽĵ��� �ٸ� �ڽĵ鿡 ���ؼ� ���� ����� �Ǿ�� �Ѵ�.
	// FIFO���� �׷���. 
}

void traversal_dfs(Graph* graph, int inx) {
	// ó�� ��带 ������ �´�.

	printf('%d', graph->g_arr[inx]);
	for (int i = 0; i < graph->size; i++) {
		if (graph->rel_arr[inx][i] == 1) {
			traversal_bfs(graph, i);
		}
	}
/*
	Stack* stack = make_init_stack();
	push_stack(stack, (s_data)(graph->g_arr)[0]);
	do
	{
		g_data data = pop_stack(stack);
		printf("%d\n", data);

		int inx = find_inx_grp(graph, data);
		for (int i = 0; i < graph->size; i++) {
			int** arr = graph->rel_arr;
			if (arr[inx][i] == 1) {
				push_stack(stack, (q_data)graph->g_arr[i]);
			}
		}

	} while (!is_empty_que(stack));
	*/
}

void destroy_grp(Graph* graph) {
	free(graph);
}