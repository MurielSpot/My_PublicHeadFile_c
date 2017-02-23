#include"HuffmanTree_Header.h"

//huffman--------------------
huffmanInfo* createHuffmanInfo(){
	return (huffmanInfo*)malloc(sizeof(huffmanInfo));
}

void initializeHuffmanTree(huffmanInfo* hi){
	hi->capacity=CAPACITY_MINHEAP;
	hi->elemNum=0;
	hi->negativeInfinity=NEGATIVEINFINITY_HUFFMANTREE;
	hi->root=NULL;
}

huffmanNode* combine2HuffmanTree(minHeap* h){
	huffmanNode* temp;
	int i;
	int size=h->elemNum;
	for(i=1;i<size;i++){//should end at i<size rather than i<=size
		temp=(huffmanNode*)malloc(sizeof(huffmanNode));
		temp->left=deleteElemMinHeap(h);
		temp->right=deleteElemMinHeap(h);
		temp->weight=temp->left->weight+temp->right->weight;//因为是完全二叉树，不需要检验指针是否为null
		addElemMinHeap(temp,h);
	}
	temp=deleteElemMinHeap(h);
	return temp;
}

void preOrderTraversalHuffman(huffmanNode* hn){
	if(!hn){
		return;
	}else{
		printf("%d ",hn->weight);
		preOrderTraversalHuffman(hn->left);
		preOrderTraversalHuffman(hn->right);
	}
}

//huffman end--------------------

//minheap--------------------
minHeap* createMinHeap(void){
	return (minHeap*)malloc(sizeof(minHeap));
}

void initializeMinHeap(minHeap* h){
	h->capacity=CAPACITY_MINHEAP-1;
	h->elemNum=0;
	h->negativeInfinity=NEGATIVEINFINITY_MINHEAP;
	int i;
	for(i=0;i<=h->capacity;i++){
		h->minHeapArray[i]=NULL;
	}
}

void printMinHeap(minHeap* h){
	int i;
	printf("\n-----------begin------------\n"
		   "h->capacity=%d,h->elemNum=%d,CAPACITY_MINHEAP=%d\n"
		   "h->minHeapArray[0]=NULL\n\n"
		   "h->minHeapArray[]->weight:",h->capacity,h->elemNum,CAPACITY_MINHEAP);
	for(i=1;i<=h->elemNum;i++){
		if(h->minHeapArray[i])
			printf("%d ",h->minHeapArray[i]->weight);
		else break;
	}
	printf("\n------------end-------------\n\b");
}

int isFullMinHeap(minHeap* h){
	if(h->elemNum>=h->capacity){
		printf("minHeap is full!\n");
		return 1;
	}
	return 0;
}

int isEmptyMinHeap(minHeap* h){
	if(h->elemNum){
		return 0;
	}
	printf("minHeap is empty!\n");
	return 1;
}

void addElemMinHeap(huffmanNode* ht,minHeap* h){
	huffmanNode* restore=ht;//因为是传引用调用，所以移动数组2的值到1时，ht会改变，最后赋值就出错了h->minHeapArray[temp]->weight=ht->weight;
	if(!h){
		printf("minHeap doesn't exist!\n");
		return;
	}
	if(isFullMinHeap(h)){
		return;
	}
	int temp=++h->elemNum;
	while(temp/2 && restore->weight<h->minHeapArray[temp/2]->weight){
		h->minHeapArray[temp]=h->minHeapArray[temp/2];
		temp=temp/2;
	}
	h->minHeapArray[temp]=restore;
}

huffmanNode* deleteElemMinHeap(minHeap* h){
	if(!h){
		printf("minHeap doesn't exist!\n");
		return NULL;
	}
	if(isEmptyMinHeap(h)){
		return NULL;
	}

	//store the minest node
	huffmanNode* minhuffmanNode=h->minHeapArray[1];
	
	//if only one node left,delete it straight
	if(h->elemNum==1){
		h->minHeapArray[1]=NULL;
		h->elemNum--;
		return minhuffmanNode;
	}

	//delete the last node from minheap
	huffmanNode* tempNode=h->minHeapArray[h->elemNum];
	h->minHeapArray[h->elemNum]=NULL;
	h->elemNum--;
	
	//renew minheap
	int parent=1,child;
	while(parent*2<=h->elemNum){
		child=parent*2;
		if(child!=h->elemNum && h->minHeapArray[child]->weight>h->minHeapArray[child+1]->weight){
			child++;
		}
		if(h->minHeapArray[child]->weight>=tempNode->weight){
			break;
		}
		h->minHeapArray[parent]=h->minHeapArray[child];
		parent=child;
	}
	h->minHeapArray[parent]=tempNode;
	
	return minhuffmanNode;
}
//minheap end--------------------


//test--------------------

int testHuffman_1(){
	int i,j;
	minHeap* h=createMinHeap();
	initializeMinHeap(h);
	printMinHeap(h);
	isEmptyMinHeap(h);

	i=1;
	j=41;
	while((j=j-2)>0){
		if(i>h->capacity)break;
		h->minHeapArray[i]=(huffmanNode*)malloc(sizeof(huffmanNode));
		h->minHeapArray[i]->right=h->minHeapArray[i]->left=NULL;
		h->minHeapArray[i]->weight=j;
		addElemMinHeap(h->minHeapArray[i],h);
		i++;
	}
	printMinHeap(h);

    huffmanNode* temp=combine2HuffmanTree(h);
    
	printMinHeap(h);

	preOrderTraversalHuffman(temp);
	printf("\n");
	
	return 0;
}

int testMinHeap_4(){
	int i,j;
	minHeap* h=createMinHeap();
	initializeMinHeap(h);
	printMinHeap(h);
	isEmptyMinHeap(h);

	i=1;
	j=41;
	while((j=j-2)>0){
		if(i>h->capacity)break;
		h->minHeapArray[i]=(huffmanNode*)malloc(sizeof(huffmanNode));
		h->minHeapArray[i]->right=h->minHeapArray[i]->left=NULL;
		h->minHeapArray[i]->weight=j;
		addElemMinHeap(h->minHeapArray[i],h);
		i++;
	}
	printMinHeap(h);

	j=41;
	huffmanNode* temp;
	while((j=j-2)>0){
		if(temp=deleteElemMinHeap(h))
			printf("%d ",temp->weight);
		
		//if(j>19)printMinHeap(h);
		//if(j%6==0)printMinHeap(h);
	}
	return 0;
}

int testMinHeap_3(){
	int i,j;
	minHeap* h=createMinHeap();
	initializeMinHeap(h);
	printMinHeap(h);
	isEmptyMinHeap(h);

	i=1;
	j=21;
	while((j=j-2)>0){
		if(i>h->capacity)break;
		h->minHeapArray[i]=(huffmanNode*)malloc(sizeof(huffmanNode));
		h->minHeapArray[i]->right=h->minHeapArray[i]->left=NULL;
		h->minHeapArray[i]->weight=j;
		addElemMinHeap(h->minHeapArray[i],h);
		i++;
	}
	printMinHeap(h);
	
	j=21;
	while((j=j-2)>0){
		printf("%d ",deleteElemMinHeap(h));
		printMinHeap(h);
	}
	return 0;
}

int testMinHeap_2(){
	int i,j;
	minHeap* h=createMinHeap();
	initializeMinHeap(h);
	printMinHeap(h);
	isEmptyMinHeap(h);

	i=1;
	j=21;
	while((j=j-2)>0){
		if(i>h->capacity)break;
		h->minHeapArray[i]=(huffmanNode*)malloc(sizeof(huffmanNode));
		h->minHeapArray[i]->right=h->minHeapArray[i]->left=NULL;
		h->minHeapArray[i]->weight=j;
		addElemMinHeap(h->minHeapArray[i],h);
		printMinHeap(h);
		i++;
	}
	return 0;
}

int testMinHeap_1(){
	int i;
	minHeap* h=createMinHeap();
	initializeMinHeap(h);
	printMinHeap(h);
	isEmptyMinHeap(h);
	
	i=1;
	while(i<11){
		if(i>h->capacity)break;
		h->minHeapArray[i]=(huffmanNode*)malloc(sizeof(huffmanNode));
		h->minHeapArray[i]->right=h->minHeapArray[i]->left=NULL;
		h->minHeapArray[i]->weight=i;
		addElemMinHeap(h->minHeapArray[i],h);
		printMinHeap(h);
		i++;
	}
	return 0;
}
