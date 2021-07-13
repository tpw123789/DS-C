#include<stdlib.h>
#include<stdio.h>
# define MAX_ITEM 5

typedef struct tagStack{
	int Item[MAX_ITEM];
	int top;
}Stack;

int Push(Stack *, int);
int IsFull(Stack*);
int Pop(Stack *, int *);
int IsEmpty(Stack *);
void PrintStack(Stack *);

int main(void){
	Stack S;
	S.top = -1;
	int choose, data;
	int LoopFlag = 1;
	
	while(LoopFlag){
		printf("--Stack from top to bottom--\n");
		PrintStack(&S);
		printf("\n(1) Push data\n(2) Pop data\n(0) Exit\n=>");
		scanf("%d", &choose);
		
		switch(choose){
			case 0:
				LoopFlag=0;
				break;
			case 1:
				printf("Input push data: ");
				scanf("%d", &data);
				if(Push(&S, data) ==0){
					printf("Stack is full.");
				}
				break;
			case 2:
				if(Pop(&S, &data) == 0){
					printf("Stack is empty.");
				}else{
					printf("Pop data: %d", data);
				}
				break;
			default:
				printf("Wrong option.");
		}
	}
	
	return EXIT_SUCCESS;
}

int Push(Stack *S, int x){
	if(IsFull(S)){
		return 0;
	}
	S -> top += 1;
	S -> Item[S -> top] = x;
	return 1;
}

int IsFull(Stack *S){
	if(S -> top == MAX_ITEM - 1){
		return 1;
	}else{
		return 0;
	}
}

int Pop(Stack *S, int *x){
	if(IsEmpty(S)){
		return 0;
	}
	*x = S -> Item[S -> top];
	S -> top --;
	return 1; 
}

int IsEmpty(Stack *S){
	if(S -> top == -1){
		return 1;
	}else{
		return 0;
	}
}

void PrintStack(Stack *S){
	int i;
	if(IsEmpty(S)){
		return ;
	}
	for(i = S -> top; i >= 0; i--){
		printf("%d\n", S -> Item[i]);
	}
}






