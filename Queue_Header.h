#ifndef _QUEUE_HEADER_H_
#define _QUEUE_HEADER_H_

#include<stdio.h>
#include<stdlib.h>

#define INFINITYQUEUE 10000
#define MAXSIZEQUEUE 7

typedef struct nodeQueue{
	int data;
	struct nodeQueue *next;
}nodeQueue;

typedef struct queue{//link list storage链式存储
	nodeQueue *first;
	nodeQueue *last;
	int elemNum;
	int maxsize;
	int infinity;
}queue;

queue* createQueue();
void enQueue(int x,queue *q);
int deQueue(queue* q);
int isFullQueue(queue* q);
int isEmptyQueue(queue* q);
void printQueue(queue *q);

#endif /*queue.h*/
