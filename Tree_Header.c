#include"Tree_Header.h"

int testBST_4_2(){
	binTree* bst;
	nodeBinTree* temp,insertPosition;
	bst=createBinTree();
	initializeBinTree(binarySearchTree,bst);
	printInfoBinTree(bst);
	if(bst){
		bst->root=insertElemBST(1,bst->root);
		bst->root=insertElemBST(2,bst->root);
		bst->root=insertElemBST(-4,bst->root);
		
		bst->root=insertElemBST(-2,bst->root);
		
		bst->root=insertElemBST(4,bst->root);
		
		bst->root=insertElemBST(-1,bst->root);
		postOrderGetHeight(bst->root);
		printf("pog\n");
		getBalanceFactor(bst->root);
		printf("gbf\n");
		postOrderTraversal_BinTree(bst->root);
		temp=findUnbalancedNode_BBT(bst->root);
		printf("temp:%d,temp->data:%d,temp->height:%d,temp->bf:%d\n",temp,temp->data,temp->height,temp->balanceFactor);
		adjustUnbalancedNode_BBT(-1,temp);
		printf("aun\n");
		postOrderGetHeight(bst->root);
		printf("pog\n");
		getBalanceFactor(bst->root);
		printf("gbf\n");
		postOrderTraversal_BinTree(bst->root);
		
		/*
		bst->root=insertElemBST(41,bst->root);
		bst->root=insertElemBST(-11,bst->root);
		bst->root=insertElemBST(-12,bst->root);
		
		postOrderTraversal_BinTree(bst->root);
		*/
	}

	return 0;
}

int testBST_4(){
	binTree* bst;
	bst=createBinTree();
	initializeBinTree(binarySearchTree,bst);
	printInfoBinTree(bst);
	if(bst){
		bst->root=insertElemBST(1,bst->root);
		bst->root=insertElemBST(2,bst->root);
		bst->root=insertElemBST(-1,bst->root);
		bst->root=insertElemBST(-2,bst->root);
		bst->root=insertElemBST(3,bst->root);
		bst->root=insertElemBST(41,bst->root);
		bst->root=insertElemBST(-11,bst->root);

		postOrderGetHeight(bst->root);
		getBalanceFactor(bst->root);
		postOrderTraversal_BinTree(bst->root);
	}

	return 0;
}

int testBST_3_2(){
	binTree* bst;
	bst=createBinTree();
	initializeBinTree(binarySearchTree,bst);
	printInfoBinTree(bst);
	if(bst){
		bst->root=insertElemBST(1,bst->root);
		bst->root=insertElemBST(2,bst->root);
		bst->root=insertElemBST(-4,bst->root);
		bst->root=insertElemBST(-2,bst->root);
		bst->root=insertElemBST(4,bst->root);
		bst->root=insertElemBST(3,bst->root);
		bst->root=insertElemBST(41,bst->root);
		bst->root=insertElemBST(-11,bst->root);
		bst->root=insertElemBST(-12,bst->root);

		postOrderGetHeight(bst->root);
		getBalanceFactor(bst->root);
		postOrderTraversal_BinTree(bst->root);
	}

	return 0;
}

int testBST_3(){
	binTree* bst;
	bst=createBinTree();
	initializeBinTree(binarySearchTree,bst);
	printInfoBinTree(bst);
	if(bst){
		bst->root=insertElemBST(1,bst->root);
		bst->root=insertElemBST(2,bst->root);
		bst->root=insertElemBST(-1,bst->root);
		bst->root=insertElemBST(-2,bst->root);
		bst->root=insertElemBST(3,bst->root);
		bst->root=insertElemBST(41,bst->root);
		bst->root=insertElemBST(-11,bst->root);
		
		postOrderGetHeight(bst->root);
		getBalanceFactor(bst->root);
		postOrderTraversal_BinTree(bst->root);
	}
	
	return 0;
}

int testBST_2(){
	binTree* bst;
	bst=createBinTree();
	initializeBinTree(binarySearchTree,bst);
	printInfoBinTree(bst);
	if(bst){
		bst->root=insertElemBST(1,bst->root);
		bst->root=insertElemBST(2,bst->root);
		bst->root=insertElemBST(-1,bst->root);
		printInfoBinTree(bst);
		postOrderTraversal_BinTree(bst->root);
		
		bst->root=deleteElemBST(1,bst->root);
		printInfoBinTree(bst);
		postOrderTraversal_BinTree(bst->root);
		
		bst->root=deleteElemBST(0,bst->root);
		printInfoBinTree(bst);
		postOrderTraversal_BinTree(bst->root);

		bst->root=deleteElemBST(2,bst->root);
		printInfoBinTree(bst);
		postOrderTraversal_BinTree(bst->root);
		
		bst->root=deleteElemBST(-1,bst->root);
		printInfoBinTree(bst);
		postOrderTraversal_BinTree(bst->root);
	}
	return 0;
}

int testBST_1(){
	binTree* bst;
	bst=createBinTree();
	initializeBinTree(binarySearchTree,bst);
	printInfoBinTree(bst);
	if(bst){
		bst->root=insertElemBST(1,bst->root);
		bst->root=insertElemBST(2,bst->root);
		bst->root=insertElemBST(-1,bst->root);
		bst->root=insertElemBST(-1,bst->root);
		printInfoBinTree(bst);
		postOrderTraversal_BinTree(bst->root);
	}
	return 0;
}

//traverse bintree by recursion
//需要先判断是否存在二叉树。
void preOrderTraversal_BinTree(nodeBinTree* btn){
	if(!btn){
		return;
	}else{
		printf("%d ",btn->data);
		preOrderTraversal_BinTree(btn->left);
		preOrderTraversal_BinTree(btn->right);
	}
}
void inOrderTraversal_BinTree(nodeBinTree* btn){
	if(!btn){
		return;
	}else{
		inOrderTraversal_BinTree(btn->left);
		printf("%d ",btn->data);
		inOrderTraversal_BinTree(btn->right);
	}
}
void postOrderTraversal_BinTree(nodeBinTree* btn){
	if(!btn){
		return;
	}else{
		postOrderTraversal_BinTree(btn->left);
		postOrderTraversal_BinTree(btn->right);
		printf("%d(%d,%d)\n",btn->data,btn->height,btn->balanceFactor);//data(height)
	}
}//traverse ending

binTree* createBinTree(void){
	binTree* temp=(binTree*)malloc(sizeof(binTree));
	return temp;
}

void initializeBinTree(flagBinTree flag,binTree* bt){
	if(!bt){
		puts("this bintree doesn't exist!");
		return;
	}
	bt->depth=0;
	bt->elemNum=0;
	bt->maxsize=MAXSIZE_BINTREE;
	bt->root=NULL;
	bt->flag=flag;
}

void printInfoBinTree(binTree* bt){
	if(!bt){
		puts("\nthis bintree doesn't exist!\n");
		return;
	}
	printf("\nbt->depth=%d,bt->elemNum=%d,bt->maxsize=%d,bt->root=%d,bt->flag=%d\n"
		   "-------------end------------\n",
			bt->depth,bt->elemNum,bt->maxsize,bt->root,bt->flag);
}
/*
  二叉搜索树（BST,Binary Search Tree）/二叉排序树/二叉查找树

  二叉搜索树：一棵二叉树，可以为空；如果不为空，满足以下性质：
    1.  非空 左子树 的所有 键值小于其根结点 的键值。
    2.  非空 右子树 的所有 键值大于其根结点 的键值。
    3.  左、右子树都是二叉搜索树
*/
nodeBinTree* findElemBST(int data,nodeBinTree* btn){
	if(!btn){
		return NULL;
	}
	if(data<btn->data){
		return findElemBST(data,btn->left);
	}else if(data>btn->data){
		return findElemBST(data,btn->right);
	}else{
		return btn;
 }
}

nodeBinTree* findMinElemBST(nodeBinTree* btn){
	if(!btn){
		puts("this bintree doesn't have elements!");
		return NULL;
	}

	nodeBinTree* temp=btn;
	while(temp->left){
		temp=temp->left;
	}
	return temp;
}

nodeBinTree* findMaxElemBST(nodeBinTree* btn){
	if(!btn){
		puts("this bintree doesn't have elements!");
		return NULL;
	}

	nodeBinTree* temp=btn;
	while(temp->right){
		temp=temp->right;
	}
	return temp;
}

nodeBinTree* insertElemBST(int data,nodeBinTree* btn){
	nodeBinTree* addNode=(nodeBinTree*)malloc(sizeof(nodeBinTree));
	addNode->left=NULL;
	addNode->right=NULL;
	addNode->data=data;
	if(!btn){
		btn=addNode;
		return btn;
	}
	
	nodeBinTree* temp=btn;
	while(1){
		if(temp->data<data){
			if(!temp->right){
				temp->right=addNode;
				break;
			}else{
				temp=temp->right;
			}
		}else if(temp->data>data){
			if(!temp->left){
				temp->left=addNode;
				break;
			}else{
				temp=temp->left;
			}
		}else{
			break;
		}
	}
	
	return btn;
}

nodeBinTree* deleteElemBST(int data,nodeBinTree* btn){//原函数原型传入的是bintree的指针，由于函数构思不合理，传入bintree指针导致不能递推调用此函数，因为想要递推调用，传入的是nodebintree类型的数据！！！！后改写此函数。
	if(!btn){
		puts("empty binTree / don't have this element!");
		return NULL;
	}
	
	nodeBinTree* temp;
	if(btn->data<data){
		btn->right=deleteElemBST(data,btn->right);
	}else if(btn->data>data){
		btn->left=deleteElemBST(data,btn->left);
	}else{
		if(btn->left && btn->right){
			temp=findMinElemBST(btn->right);
			btn->data=temp->data;
			btn->right=deleteElemBST(btn->data,btn->right);
		}else{
			temp=btn;
			if(!btn->left){
				btn=btn->right;
			}else if(!btn->right){
				btn=btn->left;
			}
			free(temp);
		}
	}
	
	return btn;
}


/*
	balanced binary tree
 */
int postOrderGetHeight(nodeBinTree* root){
	int hl,hr,maxH;
	if(root){
		hl=postOrderGetHeight(root->left);
		hr=postOrderGetHeight(root->right);
		maxH=(hl>hr)?hl:hr;
		root->height=maxH+1;
		return maxH+1;
	}else{
		return 0;//空数深度为0
	}
}

void getBalanceFactor(nodeBinTree* root){
	if(root){
		if(root->left&&root->right){
			root->balanceFactor=root->left->height-root->right->height;
		}else if(!root->left && !root->right){
			root->balanceFactor=0;
		}else if(!root->left){
			root->balanceFactor=-root->right->height;
		}else{
			root->balanceFactor=root->left->height;
		}
	}else{
		return;
	}
	getBalanceFactor(root->left);
	getBalanceFactor(root->right);
}

nodeBinTree* findUnbalancedNode_BBT(nodeBinTree* btn){
	nodeBinTree* temp;
	if(!btn){
		return NULL;
	}else if(btn->balanceFactor<2&&btn->balanceFactor>-2){
		if(temp=findUnbalancedNode_BBT(btn->left)){
			return temp;
		}else{
			return findUnbalancedNode_BBT(btn->right);
		}
	}
	return btn;
}


//结束后需要另外计算树的高度和平衡因子。
//传入不平衡的节点。

void singleRotateR_BBT(nodeBinTree* root){
	nodeBinTree* temp;
	if(root){
		printf("right-right\n");
		temp->data=root->data;
		root->data=root->right->data;
		root->right->data=temp->data;
		
		temp=root->right;
		root->right=temp->right;
		temp->right=temp->left;
		temp->left=root->left;
		root->left=temp;
	}
}

void doubleRotateRL_BBT(nodeBinTree* root){
	nodeBinTree* temp;
    if(root){
    	printf("right-left\n");
		temp->data=root->data;
		root->data=root->right->left->data;
		root->right->left->data=temp->data;
		
		temp=root->right->left;
		root->right->left=temp->right;
		temp->right=temp->left;
		temp->left=root->left;
		root->left=temp;
	}
}

void singleRotateL_BBT(nodeBinTree* root){
	nodeBinTree* temp;
	if(root){
		puts("left-left");
		
		temp->data=root->data;
		root->data=root->left->data;
		root->left->data=temp->data;
		
		temp=root->left;
		root->left=temp->left;
		temp->left=temp->right;
		temp->right=root->right;
		root->right=temp;
	}
}

void doubleRotateLR_BBT(nodeBinTree* root){
	nodeBinTree* temp;
	if(root){
		printf("left-right\n");
		temp->data=root->data;
		root->data=root->left->right->data;
		root->left->right->data=temp->data;
		
		
		temp=root->left->right;
		root->left->right=temp->left;
		temp->left=temp->right;
		temp->right=root->right;
		root->right=temp;
	}
}

void adjustUnbalancedNode_BBT(int insertedData,nodeBinTree* unBalanced){
	if(!unBalanced){
		return;
	}
	if(unBalanced->balanceFactor>1){
		printf("left\n");
		if(findElemBST(insertedData,unBalanced->left->left)){
			singleRotateL_BBT(unBalanced);
		}else if(findElemBST(insertedData,unBalanced->left->right)){
			doubleRotateLR_BBT(unBalanced);
		}
	}else if(unBalanced->balanceFactor<-1){
		printf("right\n");
		if(findElemBST(insertedData,unBalanced->right->right)){
   			singleRotateR_BBT(unBalanced);
		}else if(findElemBST(insertedData,unBalanced->right->left)){
			doubleRotateRL_BBT(unBalanced);
		}
	}
}




