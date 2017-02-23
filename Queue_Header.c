#include"Queue_Header.h"

/*
 类型名称 ：队列(Queue)

 数据对象集： 一个有0 个或多个元素的有穷线性表。

 操作集 ：长度为MaxSize 的队列Q:Queue ，队列元素item:ElementType
    1 、Queue* CreatQueue( int MaxSize ) ：生成长度为MaxSize 的空队列；
    2 、int IsFullQ( Queue* q ) ：判断队列Q 是否已满；
    3 、void EnQueue( ElementType item, Queue* q) ：  将数据元素item 插入队列Q 中；
    4 、int IsEmptyQ( Queue* q ) ：  判断队列Q 是否为空；
    5 、ElementType DeQueue( Queue* q ) ：将队头数据元素从队列中删除并返回。
    6 、void printQ(Queue *q)：打印队列
 */

queue* createQueue(){
	queue *aQueue=(queue*)malloc(sizeof(queue));
	aQueue->first=NULL;
	aQueue->last=NULL;
	aQueue->elemNum=0;
	aQueue->maxsize=MAXSIZEQUEUE;
	aQueue->infinity=INFINITYQUEUE;
	
	return aQueue;
}//createQueue

void printQueue(queue *q){
	if(!q->first){
		printf("empty!\nq->first=%d,q->last=%d,q->elemNum=%d,q->capacity=%d\n",q->first,q->last,q->elemNum,q->maxsize);
		
		printf("\n-----print end-----\n\n");
		return;
	}
	
	int i=q->elemNum;
	nodeQueue *temp=q->first;
	printf("\ntemp=%d,q->first=%d,q->last=%d,q->elemNum=%d,q->capacity=%d\n",temp,q->first,q->last,q->elemNum,q->maxsize);
	while(i--){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}//printQueue

void enQueue(int x,queue *q){
	nodeQueue *temp;
	
	if(isFullQueue(q)){
		return;
	}
	
	temp=(nodeQueue*)malloc(sizeof(nodeQueue));
	temp->data=x;
	temp->next=NULL;
	
	q->elemNum++;
	if(!q->first){
		q->first=temp;
		q->last=temp;
	}else{
		(q->last)->next=temp;
		q->last=temp;
	}
}//EnQueue

int deQueue(queue* q){
	nodeQueue *temp;
	int elem;
	
	if(isEmptyQueue(q)){
		return q->infinity;
	}
	
	temp=q->first;
	elem=temp->data;

	if(q->first==q->last){
		q->first=q->last=NULL;
	}else{
		q->first=q->first->next;
	}
	q->elemNum--;

	free(temp);

	return elem;
}//DeQueue

int isFullQueue(queue* q){
	if(q->elemNum==q->maxsize){
		puts("queue is full !!\n");
		return 1;
	}
	return 0;
}//IsFullQ

int isEmptyQueue(queue* q){
	if(q->elemNum){
		return 0;
	}
	puts("queue is empty !!\n");
	return 1; 
}//IsEmptyQ

int testQueue(void)
{
	queue* q;
	int elem,i;

	q=createQueue();
	
	puts("0 to end,1 to EnQueue,2 to DeQueue,3 to print:");
	scanf("%d",&i);
	
	while(i){
	if(i==1){
		puts("EnQueue elem:");
		scanf("%d",&i);
		enQueue(i,q);
	}else if(i==2){
		printf("get elem:%d\n",elem=deQueue(q));
	}else if(i==3){
		printQueue(q);
	}
	puts("0 to end,1 to EnQueue,2 to DeQueue,3 to print:");
	scanf("%d",&i);
	}
	
	return 0;
}
