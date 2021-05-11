
#include <stdio.h>
#include <stdlib.h>
#include "ALGraph.h"
#include "LinkedList.h"



void GraphInit(ALGraph* pg, int nv) {
	int i;

	pg->adjList = (List*)malloc(sizeof(List) * nv);
	pg->numV = nv;
	pg->numE = 0;

	for (i = 0; i < nv; i++)
	{
		pg->adjList[i] = *make_init_list();
	}
}




void GraphDestroy(ALGraph* pg)
{
	if (pg->adjList != NULL)
		free(pg->adjList);
}

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
			printf("%c", vx + 65); //왜 65를 더하는지 확인 필요.
			while (has_next(&(pg->adjList[i]))) {
				printf("%c", vx + 65);
			}
			printf("\n");
		}
	}
}