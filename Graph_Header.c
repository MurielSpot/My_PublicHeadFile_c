#include"Graph_Header.h"

/*
graph* initializeGraph();
	function:	create and initialize a graph
*/
graph* createGraph(void){
	graph* aGraph=(graph*)malloc(sizeof(graph));
	return aGraph;
}

void initializeGraph(graph* aGraph){
	int i,j;
	
	if(!aGraph){
		puts("graph doesn't exist!!");
	}
	aGraph->infinity=INFINITYGRAPH;
	aGraph->maxsize=MAXSIZEGRAPH;
	for(i=0;i<aGraph->maxsize;i++){
		for(j=0;j<aGraph->maxsize;j++){
				aGraph->connect[i][j]=aGraph->infinity;
		}
		aGraph->connect[i][i]=0;
		aGraph->visited[i]=0;
	}
}//initializeGraph

void autoInputGraph(graph* aGraph){
	aGraph->connect[0][1]=aGraph->connect[1][0]=1;
	aGraph->connect[0][2]=aGraph->connect[2][0]=2;
	aGraph->connect[0][3]=aGraph->connect[3][0]=3;
	aGraph->connect[0][5]=aGraph->connect[5][0]=5;
	aGraph->connect[1][4]=aGraph->connect[4][1]=5;
	aGraph->connect[2][3]=aGraph->connect[3][2]=5;
	aGraph->connect[4][5]=aGraph->connect[5][4]=9;
	aGraph->connect[4][6]=aGraph->connect[6][4]=10;
	aGraph->connect[6][7]=aGraph->connect[7][6]=3;
}//autoInputGraph

void inputGraph(graph* aGraph){
	int count;
	int start,end,dist;

	printf("input how many paths:\n");
	scanf("%d",&count);

	while(count--){
		puts("input two cities' number and the distance between them:");
		scanf("%d %d %d",&start,&end,&dist);
		aGraph->connect[start][end]=aGraph->connect[end][start]=dist;
	}
}//inputGraph

void printGraph(graph* aGraph){
	int i,j;

	printf("**********************\n");
	printf("aGraph->maxsize:%d,aGraph->infinity:%d\n",aGraph->maxsize,aGraph->infinity);
	for(i=0;i<aGraph->maxsize;i++){
		for(j=0;j<aGraph->maxsize;j++){
			printf("%6d ",aGraph->connect[i][j]);
		}
		puts("\n");
	}
	puts("\n**********END************\n\n");
}//printGraph

int testGraph(void){
	graph* temp=createGraph();
	initializeGraph(temp);
	printGraph(temp);
	autoInputGraph(temp);
	printGraph(temp);
	inputGraph(temp);
	printGraph(temp);

	return 0;
}//testGraph
