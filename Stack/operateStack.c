#include<stdlib.h>
#include<stdio.h>

#define MAX_OP 5
#define operator(ch) ((c=='+')||(c=='-')||(c=='*')||(c=='/'))?1:0
#define operands(ch) ((c)>='a' && (c)<='z')?1:0
#define MAX_ITEM 100

typedef struct tagStack{
	int item[MAX_ITEM];
	int top;
}Stack;
Stack S;

char op[MAX_OP]={'(', '+', '-', '*', '/'};
char prio[MAX_OP]={0, 1, 1, 2, 2};

void Push(int);
void Pop(int *);
int priority(char ch);
void	in_to_post(char *,char *);

int main(void){
	int i;
	char infix[MAX_ITEM];
	char postfix[MAX_ITEM];
	S.top = -1;
	
	
	return 0;
}


void Push(int x){
	if(S.top < MAX_ITEM - 1){
		S.top++;
		S.item[S.top] = x;
	}
}

void Pop(int *x){
	if(S.top >= 0){
		*x = S.item[S.top];
		S.top--;
	}
}

int priority(char ch){
	int i;
	for(i = 0; i < MAX_OP; i++){
		if(op[i] == ch){
			return prio[i];
		}
	}	
	return -1;
}

void in_to_post(char *infix, char *postfix){
	int i, j, element;
	char token;
	i = j =0;
}









