#ifndef _BFSDFSDIJSTRAFLOYDHEADER_H_
#define _BFSDFSDIJSTRAFLOYDHEADER_H_

#include<stdio.h>
#include"Graph_Header.h"
#include"Queue_Header.h"

/**
 *title:	traverse graph & the shortest path
 */

void dfs(int source,graph* aGraph);
void bfs(int source,graph* aGraph,queue* aQueue);
void dijkstra(int source,graph* aGraph);
void floyd(graph* aGraph);

int testBfsDfsDijkstraFloyd_1(void);
int testBfsDfsDijkstraFloyd_2(void);

#endif
