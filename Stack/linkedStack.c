#include<stdlib.h>
#include<stdio.h>

typedef struct tagStackList{
	int data;
	struct tagStackList *next;
}StackList;


int Push(StackList *, int);
int Pop(StackList *);
void PrintStack(StackList *);


int main(void){
	StackList *TopOfS;
	TopOfS = (StackList *)malloc(sizeof(StackList));
	TopOfS -> next = NULL;
	int choose, data; 
	int LoopFlag = 1;
	
	
	while(LoopFlag){
		printf("---Linked stack from top to bottom---\n");
		PrintStack(TopOfS);
		printf("\n(1) Push data\n(2) Pop data\n(0) Exit\n=>");
		scanf("%d", &choose);
		
		switch(choose){
			case 0:
				LoopFlag = 0;
				break;
			case 1:
				printf("Input push data: ");
				scanf("%d", &data);
				if(Push(TopOfS, data) == 0){
					printf("Push fail.");
				}
				break;
			case 2:
				if(Pop(TopOfS) == 0){
					printf("Linked Stack is empty, pop fail.");
				}
				break;
			default:
				printf("Wrong option.");		
		}
	}
	
	
	return EXIT_SUCCESS;
}


void PrintStack(StackList *S){
	StackList *p;
	for(p = S -> next; p != NULL; p = p -> next){
		printf("%d\n", p -> data);
	}
}


int Push(StackList *S, int x){
	StackList *p;
	p = (StackList *)malloc(sizeof(StackList));
	if(p == NULL){
		return 0;
	}
	p -> data = x;
	p -> next = S -> next;
	S -> next = p;
	return 1;
}
int Pop(StackList *S){
	StackList *p;
	p = S -> next;
	if(p == NULL){
		return 0;
	}
	S -> next = p -> next;
	free(p);
	return 1;
}




