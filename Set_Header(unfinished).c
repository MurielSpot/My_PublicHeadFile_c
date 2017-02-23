#include"Set_Header.h"


sets* createSets(){
	return (sets*)malloc(sizeof(sets));
}

void initializeSets(sets* s){
	if(!s){
		puts("sets doesn't exist");
		return;
	}
	s->capacity=CAPACITY_SET;
	s->elemNum=0;
	s->invalidData=-1;
}

void printSets(sets* s){
	printf("s->capacity=%d,s->elemNum=%d,s->invalidData=%d\n"
			"s->setArray[%d]:(data,parent)\n"
			,s->capacity,s->elemNum,s->invalidData,CAPACITY_SET);

	int i;
	for(i=0;i<s->elemNum;i++){
		printf("(%d,%d) ",s->setArray[i].data,s->setArray[i].parent);
	}
	printf("\n");
}

void addElem_Sets(elemType data,int parent,sets* s){
	if(!s){
		puts("sets doesn't exist");
		return;
	}
	if(s->elemNum==s->capacity){
		puts("set is full");
		return;
	}
	
	(s->setArray[s->elemNum]).data=data;
	(s->setArray[s->elemNum]).parent=parent;
	s->elemNum++;
}

elemType deleteElem_Sets(elemType data,sets* s){
	if(!s){
		puts("sets doesn't exist");
		return s->invalidData;
	}
	if(s->elemNum==0){
		puts("set is empty");
		return s->invalidData;
	}
	
	//find the position of the elem data
	int i;
	int record;
	int position=findElem_Sets(s,data);

	///////////////////////////////
	//unfinished
	//complex afterwards
}

int findElem_Sets(sets* s,elemType x){
	int i;
	for(i=0;i<s->elemNum && s->setArray[i].data!=x;i++);
	if(i==s->elemNum)return s->invalidData;
	for(;s->setArray[i].parent>=0;i=s->setArray[i].parent);
	return i;//return the index of the root where elem belongs
}

void union_Sets(sets* s,elemType x1,elemType x2){
	int i,j;
	i=findElem_Sets(s,x1);
	j=findElem_Sets(s,x2);
	if(i!=j){
		s->setArray[j].parent=i;
	}
}

//test--------------
int test3(){
	sets* temp=createSets();
	initializeSets(temp);
	printSets(temp);

	int i=10;
	elemType data;
	int parent;
	while(i--){
		scanf("%d %d",&data,&parent);
		addElem_Sets(data,parent,temp);
	}
	printSets(temp);

	union_Sets(temp,2,3);
	printSets(temp);

	printf("\n%d",findElem_Sets(temp,5));

	return 0;
}

int test2(){
	sets* temp=createSets();
	initializeSets(temp);
	printSets(temp);

	int i=10;
	elemType data;
	int parent;
	while(i--){
		scanf("%d %d",&data,&parent);
		addElem_Sets(data,parent,temp);
	}
	printSets(temp);

	printf("\n%d",findElem_Sets(temp,9));
	
	return 0;
}

int test1(){
	sets* temp=createSets();
	initializeSets(temp);
	printSets(temp);
	
	int i=10;
	elemType data;
	int parent;
	while(i--){
		scanf("%d %d",&data,&parent);
		addElem_Sets(data,parent,temp);
	}
	printSets(temp);
	
	return 0;
}
