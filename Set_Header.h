#ifndef _SET_HEADER_H_
#define _SET_HEADER_H_

#include<stdio.h>
#include<stdlib.h>

#define CAPACITY_SET 10

typedef int elemType;

typedef struct{
	elemType data;
	int parent;
}setType;

typedef struct{
	int elemNum;
	int capacity;
	elemType invalidData;
	setType setArray[CAPACITY_SET];
}sets;

sets* createSets();
void initializeSets(sets* s);

void addElem_Sets(elemType data,int parent,sets* s);
elemType deleteElem_Sets(elemType data,sets* s);

int findElem_Sets(sets* s,elemType x);
void union_Sets(sets* s,elemType x1,elemType x2);

int test2();
int test1();

#endif
