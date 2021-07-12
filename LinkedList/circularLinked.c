#include<stdlib.h>
#include<stdio.h>

typedef struct tagListNode{
	int data;
	struct tagListNode *next;
}ListNode;

void CListTraverse(ListNode *);

int main(void){
	ListNode *ListA;
	
	ListA = (ListNode *)malloc(sizeof(ListNode));
	
	ListA -> next = ListA;
	return 0;
}

void CListTraverse(ListNode *head){
	ListNode *p = head -> next;
	while(p != head){
		p = p -> next;
	}
}
