#include<stdlib.h>
#include<stdio.h>

typedef struct tagListNode{
	int data;
	struct tagListNode *next;
}ListNode;

int ListConcate(ListNode *, ListNode *);
int ListLength(ListNode *);
void ListTraverse(ListNode *);
void PrintList(ListNode *);  //print all node
void FreeAllNode(ListNode *); // free all node moemory
int InsertTail(ListNode *, int);  // add new node in tail
int InsertAfter(ListNode *, int); // insert new node
int DeleteNode(ListNode *, ListNode*); // delete node
ListNode *GetPreNode(ListNode *, ListNode *); // find pre node

int main(void){
	FILE *fin; // FILE -> structure in stdio.h
	ListNode *Head; // head node
	ListNode *p;
	int ReadInData;
	int insertdata;
	int num;
	int choose;
	int i;
	// open file
	fin = fopen("List.in", "r"); 
	if(fin == NULL){
		printf("File cannot be opened, program terminate.");
		return 1;
	}
	// head node memory allocation
	Head = (ListNode*)malloc(sizeof(ListNode));
	Head -> next = NULL;
	// read file
	while(!feof(fin)){
		fscanf(fin, "%d", &ReadInData);
		InsertTail(Head, ReadInData);
	}
	fclose(fin);
	// start
	while(1){
		printf("\nContent of list: ");
		PrintList(Head);
		printf("\n(1)Append new node\n(2)Insert new node\n(3)Delete node\n(0)exit\n=>");
		scanf("%d", &choose);
		switch(choose){
			case 0:
				FreeAllNode(Head);
				exit(0);
			case 1:
				printf("Input new data => ");
				scanf("%d", &insertdata);
				InsertTail(Head, insertdata);
				break;
			case 2:
				printf("Input new data => ");
				scanf("%d", &insertdata);
				printf("New position => ");
				scanf("%d", &num);
				for(i = 1, p = Head; i != num && p != NULL; p = p -> next, i++);
				if(p == NULL){
					printf("Insert Failed.");
				}else if(InsertAfter(p, insertdata) == 0){
					printf("Insert Failed.");
				}	
				
				break;
			case 3:
				printf("Data to be deleted => ");
				scanf("%d", &num);
				for(i = 0, p = Head; p != NULL && p -> data != num; p = p -> next, i++);
				if(p == NULL){
					printf("the data is not in list.");
				}else if(DeleteNode(Head, p) == 0){
					printf("Delete Failed.");
				}
				break;
			default:
				printf("Wrong option !!");
		}
	}
	
	return EXIT_SUCCESS;	
}

// print List content
void PrintList(ListNode *p){
	for(p = p -> next; p != NULL; p = p -> next){
		printf("%d ", p -> data);
	}	
}

// insert item to tail
int InsertTail(ListNode *head, int value){
	ListNode *NewNode, *p = head;
	NewNode = (ListNode *)malloc(sizeof(ListNode)); // memory allocation to newnode
	// malloc fail
	if(NewNode == NULL){
		return 0;
	}
	NewNode -> data = value; // (*NewNode).data = value
	NewNode -> next = NULL; // -1 last one
	while(p -> next != NULL){
		p = p -> next;
	}
	p -> next = NewNode;
	return 1;
}

// add new data
int InsertAfter(ListNode *p, int value){
	ListNode *NewNode;
	NewNode = (ListNode *)malloc(sizeof(ListNode));
	if(NewNode == NULL){
		return 0;
	}
	NewNode -> data = value;
	NewNode -> next = p -> next;
	p -> next = NewNode;
	return 1;
}

// delete data
int DeleteNode(ListNode * head, ListNode *OldNode){
	ListNode *PreNode;
	if(head == OldNode){
		return 0;
	}
	PreNode = GetPreNode(head, OldNode);
	if(PreNode == NULL){
		return 0;
	}
	PreNode -> next = OldNode -> next;
	free(OldNode);
	
	return 1;
}

// find pre node
ListNode *GetPreNode(ListNode *head, ListNode *node){
	ListNode *p, *q;
	p = head;  // left
	q = head -> next; // right
	while((q != NULL) && (q != node)){
		p = q;
		q = q -> next;
	}
	if(q != NULL){
		return p;
	}else{
		return NULL;
	}
	
}

// free all node
void FreeAllNode(ListNode *head){
	ListNode *next_node;
	while(head != NULL){
		next_node = head -> next;
		free(head);
		head = next_node;
	}
}

void ListTraverse(ListNode *head){
	ListNode *p = head;
	p = p -> next;
	while(p){
		printf("\n%d", p-> data);
		p = p -> next;
	}
}

int ListLength(ListNode *head){
	int count;
	ListNode *p = head -> next;
	while(p != NULL){
		count++;
		p = p -> next;
	}
	return count;
}

int ListConcate(ListNode *ListA, ListNode *ListB){
	ListNode *p = ListA;
	while(p -> next != NULL){
		p = p -> next;
	}
	p -> next = ListB -> next;
}




