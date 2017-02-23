#include"BfsDfsDijkstraFloyd_Header.h"

int testBfsDfsDijkstraFloyd_4(void){
	graph* aGraph=createGraph();
	initializeGraph(aGraph);
	autoInputGraph(aGraph);
	printGraph(aGraph);

	floyd(aGraph);

	return 0;
}

int testBfsDfsDijkstraFloyd_3(void){
	graph* aGraph=createGraph();
	initializeGraph(aGraph);
	autoInputGraph(aGraph);
	printGraph(aGraph);

	dijkstra(2,aGraph);

	return 0;
}

int testBfsDfsDijkstraFloyd_2(void){
	graph* aGraph=createGraph();
	initializeGraph(aGraph);
	autoInputGraph(aGraph);
	printGraph(aGraph);

	queue* aQueue;
	aQueue=createQueue();
	printQueue(aQueue);

	dfs(2,aGraph);
	initializeGraph(aGraph);
	puts("---");
	autoInputGraph(aGraph);
	bfs(2,aGraph,aQueue);

	return 0;
}

void bfs(int source,graph* aGraph,queue* aQueue){
	if(!aGraph){
		puts("no such a graph!");
		return;
	}else if(!aQueue){
		puts("no such a queue!");
		return;
	}

	aGraph->visited[source]=1;
	enQueue(source,aQueue);

	int count;
	while(!isEmptyQueue(aQueue)){
		source=deQueue(aQueue);
		printf("%d  ",source);
		for(count=0;count<aGraph->maxsize;count++){
			if(!(aGraph->visited[count])
				  && aGraph->connect[count][source]<aGraph->infinity
				  && aGraph->connect[count][source]>0){
				enQueue(count,aQueue);
				aGraph->visited[count]=1;
			}
		}
	}
	puts("-----bfs end-----");
}

void dfs(int source,graph* aGraph){
	if(!aGraph){
		puts("no such a graph!");
		return;
	}
	if(source>=aGraph->maxsize){
		puts("give a non-existing node,that is,source>=aGraph->maxsize!!");
		return;
	}
	int count;
	
	printf("%d  ",source);
	aGraph->visited[source]=1;
	for(count=0;count<aGraph->maxsize;count++){
		//traverse all the unvisited  reachable(excluding the source) graph node with the source node(1.all,	2.unvisited,  3.reachable,  4.connected with source node)
		if(!aGraph->visited[count]
		   && aGraph->connect[source][count] < (aGraph->infinity)
		   && aGraph->connect[source][count] > 0){
			dfs(count,aGraph);
		}
	}
}

void dijkstra(int source,graph* aGraph){//attention!! every array should renew in while loop
	if(source>=aGraph->maxsize){
		printf("source exceeds the maxsize of graph~~\n");
		return;
	}
	
	int dist[aGraph->maxsize];
	int path[aGraph->maxsize];
	
	//initialize record array
	int i,i2;
	for(i=0;i<aGraph->maxsize;i++){
		dist[i]=aGraph->infinity;
		path[i]=-2;//equals -2 representing invalid path,-1 connected with source
		aGraph->visited[i]=0;
	}
	
	//first node
	int minElem=source;
	int minDist;
	path[source]=-1;
	dist[source]=0;
	while(1){
		//find nearest graph node
		minDist=aGraph->infinity;
		for(i=0;i<aGraph->maxsize;i++){
			if(!aGraph->visited[i] && minDist>dist[i]){
				minDist=dist[i];
				minElem=i;
			}
		}
		if(minDist==aGraph->infinity)break;
		aGraph->visited[minElem]=1;

		//renew all the distance to source
		for(i=0;i<aGraph->maxsize;i++){
			if(!aGraph->visited[i] 
			    && aGraph->connect[i][minElem]+dist[minElem]<dist[i]){
			    path[i]=minElem;
				dist[i]=aGraph->connect[i][minElem]+dist[minElem];
			}
		}
	}
	
	//print
	for(i=0;i<aGraph->maxsize;i++){
		printf("dist[%d]:%d \n",i,dist[i]);
	}
	printf("\n\n");
	for(i=0;i<aGraph->maxsize;i++){
		printf("visited[%d]:%d\n",i,aGraph->visited[i]);
	}
	printf("\n\n");
	for(i=0;i<aGraph->maxsize;i++){
		printf("path[%d]:%d \n",i,path[i]);
		//printf("%c",(i%3==0)?'\n':' ');
	}
	
	puts("\n**********END************\n\n");
}

void floyd(graph* aGraph){
	int dist[aGraph->maxsize][aGraph->maxsize];
	int path[aGraph->maxsize][aGraph->maxsize];
	int i,j,k;
	
	//initialize
	for(i=0;i<aGraph->maxsize;i++){
		for(j=0;j<aGraph->maxsize;j++){
			dist[i][j]=aGraph->connect[i][j];
			path[i][j]=-1;
		}
	}
	
	//
	for(k=0;k<aGraph->maxsize;k++){
		for(i=0;i<aGraph->maxsize;i++){
			for(j=0;j<aGraph->maxsize;j++){
				if(dist[i][k]+dist[k][j]<dist[i][j]){
					dist[i][j]=dist[i][k]+dist[k][j];
					path[i][j]=k;
				}
			}
		}
	}
	
	//print
	for(i=0;i<aGraph->maxsize;i++){
		for(j=0;j<aGraph->maxsize;j++){
			printf("%7d ",dist[i][j]);
		}
		printf("\n");
	}
	puts("");
	for(i=0;i<aGraph->maxsize;i++){
		for(j=0;j<aGraph->maxsize;j++){
			printf("%7d ",path[i][j]);
		}
		printf("\n");
	}
}

int testBfsDfsDijkstraFloyd_1(void){
	graph* aGraph;
	initializeGraph(aGraph);
	autoInputGraph(aGraph);
	printGraph(aGraph);
	
	dfs(2,aGraph);
	
	return 0;
}
