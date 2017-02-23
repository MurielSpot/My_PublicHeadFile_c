#ifndef _TREE_HEADER_H_
#define _TREE_HEADER_H_

#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE_BINTREE 10

typedef enum flagBinTree{normalTree,binarySearchTree,balancedTree}flagBinTree;

struct child_sibling_representation_Tree{
	int data;
	struct child_sibling_representation_Tree* child;
	struct child_sibling_representation_Tree* sibling;
};

typedef struct nodeBinTree{
	int data;
	struct nodeBinTree* left;
	struct nodeBinTree* right;
	
	int height;
	int balanceFactor;//bf=h(l)-h(r)
}nodeBinTree;

typedef struct binTree{
	flagBinTree flag;
	int maxsize;
	int elemNum;
	int depth;
	nodeBinTree* root;
}binTree;

void preOrderTraversal_BinTree(nodeBinTree* btn);
void inOrderTraversal_BinTree(nodeBinTree* btn);
void postOrderTraversal_BinTree(nodeBinTree* btn);

binTree* createBinTree(void);
void initializeBinTree(flagBinTree flag,binTree* bt);
void printInfoBinTree(binTree* bt);


nodeBinTree* findElemBST(int data,nodeBinTree* btn);
nodeBinTree* findMinElemBST(nodeBinTree* btn);
nodeBinTree* findMaxElemBST(nodeBinTree* btn);
nodeBinTree* insertElemBST(int data,nodeBinTree* btn);
nodeBinTree* deleteElemBST(int data,nodeBinTree* bt);

int postOrderGetHeight(nodeBinTree* root);
void getBalanceFactor(nodeBinTree* root);
nodeBinTree* findUnbalancedNode_BBT(nodeBinTree* btn);
void adjustUnbalancedNode_BBT(int insertedData,nodeBinTree* unBalanced);

void doubleRotateLR_BBT(nodeBinTree* root);
void singleRotateL_BBT(nodeBinTree* root);
void doubleRotateRL_BBT(nodeBinTree* root);
void singleRotateR_BBT(nodeBinTree* root);

int testBST_1();
int testBST_2();
int testBST_3();
int testBST_3_2();

#endif
