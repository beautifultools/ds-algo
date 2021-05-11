#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraphDFS.h"
#include "Que.h"

void GraphInit(ALGraph* pg, int nv) {
	int i;

	pg->adjList = (List*)malloc(sizeof(List) * nv);
	pg->numV = nv;
	pg->numE = 0;

	for (i = 0; i < nv; i++)
	{
		pg->adjList[i] = *make_init_list();
	}
	pg->visitInfo = (int*)malloc(sizeof(int) * pg->numV);
	// 배열의 모든 요소를 0으로 초기화
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

void GraphDestroy(ALGraph* pg) {
	if (pg->adjList != NULL)
		free(pg->adjList);

	if (pg->visitInfo != NULL) {
		free(pg->visitInfo);
	}
};

void AddEdge(ALGraph* pg, int fromV, int toV)
{
	push_list(&(pg->adjList[fromV]), toV);
	push_list(&(pg->adjList[toV]), fromV);
	pg->numE += 1;
}

void showGraphEdgeInfo(ALGraph* pg)
{
	int i;
	int vx;

	for (i = 0; i < pg->numV; i++)
	{
		printf("%c와 연결된 정점 : ", i + 65);

		if (init_internal_inx(&(pg->adjList[i])))
		{
			printf("%c", vx + 65);
			while (has_next(&(pg->adjList[i]))) {
				printf("%c", vx + 65);
			}
			printf("\n");
		}
	}
}

void BFShowGraphVertex(ALGraph * pg, int startV) {
	int visitV = startV;
	int nextV;

	Que* que = init_que();
	VisitVertes(pg, visitV);
	
	while (init_internal_inx(&(pg->adjList[visitV]))) {
		int visitFlag = 0;

		if (VisitVertes(pg, nextV)) {
			push_stack(stack, visitV);
			visitV = nextV;
			visitFlag = 1;
		}
		else {
			while (has_next(&(pg->adjList[visitV]))) {
				if (VisitVertes(pg, nextV)) {
					push_stack(stack, visitV);
					visitV = nextV;
					visitFlag = 1;
					break;
				}
			}
		}
		if (!visitFlag) {
			if (is_empty_stack(stack)) {
				break;
			}
			else {
				visitV = pop_stack(stack);
			}
		}
	}

	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

int VisitVertes(ALGraph * pg, int visitV) {

	if (pg->visitInfo[visitV] == 0) {  // 처음 방문일 떄 0
		pg->visitInfo[visitV] = 1; // visit을 방문한 것으로 기록
		print("%c", visitV + 65);
		return 1;
	}

	return 0;
}