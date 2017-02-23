#ifndef _GRAPH_HEADER_H_
#define _GRAPH_HEADER_H_
/*
  *
  *初始化一个图，可重用
  *
  */
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZEGRAPH 8
#define INFINITYGRAPH 10000

typedef struct graph{
	int infinity;
	int maxsize;
	int connect[MAXSIZEGRAPH][MAXSIZEGRAPH];
	int visited[MAXSIZEGRAPH];
}graph;

graph* createGraph(void);
void initializeGraph(graph* aGraph);
void inputGraph(graph* aGraph);
void printGraph(graph* aGraph);
void autoInputGraph(graph* aGraph);

#endif
