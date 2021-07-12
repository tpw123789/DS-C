#include<stdlib.h>
#include<stdio.h>

typedef struct tagPListNode{
	float coaf;
	int expo;
	struct tagPListNode *next;
}PListNode;

PListNode *AddTail(PListNode *, float, int);
PListNode *PolyAdd(PListNode *, PListNode *);

int main(void){
	
	return 0;
}

PListNode *AddTail(PListNode *tail, float co, int ex){
	PListNode *p;
	p = (PListNode *)malloc(sizeof(PListNode));
	p -> coaf = co;
	p -> expo = ex;
	p -> next = NULL;
	tail -> next = p;
	
	return tail;
}

PListNode *PolyAdd(PListNode *pa, PListNode *pb){
	PListNode *c, *ctail; // third link
	c = (PListNode *)malloc(sizeof(PListNode));
	ctail = c;
	pa = pa -> next;
	pb = pb -> next;
	
	while(pa && pb){
		if(pa -> expo > pb -> expo){
			ctail = AddTail(ctail, pa -> coaf, pa -> expo);
			pa = pa -> next;
		}else if(pa -> expo < pb -> expo){
			ctail = AddTail(ctail, pb -> coaf, pb -> expo);
			pb = pb -> next;
		}else{
			if(pa -> coaf + pb -> coaf != 0){
				ctail = AddTail(ctail, pa -> coaf + pb -> coaf, pa -> expo);
			}
			pa = pa -> next;
			pb = pb -> next;	
		}
	}
	
	// still have ploy..
	while(pa){
		ctail = AddTail(ctail, pa -> coaf, pa -> expo);
	}
	while(pb){
		ctail = AddTail(ctail, pb -> coaf, pb -> expo);
	}
	
	return c;
}


