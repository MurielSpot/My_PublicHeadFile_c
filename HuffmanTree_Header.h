#ifndef _HUFFMANTREE_HEADER_H_
#define _HUFFMANTREE_HEADER_H_

#include<stdio.h>
#include<stdlib.h>

#define CAPACITY_HUFFMANTREE 10
#define NEGATIVEINFINITY_HUFFMANTREE -10000

#define CAPACITY_MINHEAP 10
#define NEGATIVEINFINITY_MINHEAP -10000

typedef struct huffmanNode{
	int weight;
	struct huffmanNode* left;
	struct huffmanNode* right;
}huffmanNode;

typedef struct huffmanInfo{
	int elemNum;
	int capacity;
	int negativeInfinity;
	huffmanNode* root;
}huffmanInfo;

typedef struct minHeap{
	int elemNum;
	int capacity;
	huffmanNode* minHeapArray[CAPACITY_MINHEAP];
	int negativeInfinity;
}minHeap;

huffmanNode* huffman(minHeap minH);

void preOrderTraversalHuffman(huffmanNode* hn);

//manipulate minHeap----------
minHeap* createMinHeap(void);
void initializeMinHeap(minHeap* h);
void printMinHeap(minHeap* h);
void addElemMinHeap(huffmanNode* ht,minHeap* h);
huffmanNode* deleteElemMinHeap(minHeap* h);
int isEmptyMinHeap(minHeap* h);
int isFullMinHeap(minHeap* h);

int testMinHeap_1();
int testMinHeap_2();
//end: manipulate minHeap

#endif
