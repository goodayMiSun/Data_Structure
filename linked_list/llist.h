#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{

	void* d;
	struct node* next;

}NODE;

typedef struct llist{

	int number;
	NODE* front;
	NODE* rear;
	NODE* pos;

}LLIST;

LLIST* create();
bool inlist(LLIST* l, int num, void* in);
bool delist(LLIST* l, int num);

