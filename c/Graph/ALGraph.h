#pragma once

#include "LinkedList.h"

enum {A, B, C, D, E, F, G, H, I, J};

typedef struct _ual
{
	int numV;
	int numE;
	List* adjList;
} ALGraph;

void GraphInit(ALGraph* pg, int nv);

void GraphDestory(ALGraph* pg);

void AddEdge(ALGraph* pg, int fromV, int toV);

void ShowGraphEdgInfo(ALGraph* pg);


