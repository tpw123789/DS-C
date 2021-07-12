#include<stdlib.h>
#include<stdio.h>

typedef struct tagListNode{
	struct tagListNode *left;
	int data;
	struct tagListNode *right;
}DListNode;

int InsertAfter(DListNode *, int value);
int DeleteNode(DListNode *);

int main(){
	
	return 0;
}

int InsertAfter(DListNode *p, int value){
	DListNode *NewNode;
	NewNode = (DListNode *)malloc(sizeof(DListNode));
	if(NewNode == NULL){
		return 0;
	}
	NewNode -> data = value;
	NewNode -> left = p;
	NewNode -> right = p -> right;
	p -> right -> left = NewNode;
	p -> right = NewNode;
	return 1;
}

int DeleteNode(DListNode *p){
	if(p == NULL){
		return 0;
	}
	p -> left -> right = p -> right;
	p -> right -> left = p -> left;
	free(p);
	
	return 1;
}
