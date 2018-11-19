#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct st_node{

	void* d;
	struct st_node * next;

}ST_NODE;

typedef struct st{

	int number;

	ST_NODE * first;

}ST;


ST* create();

bool push(ST* st, void * insert);

void* pop(ST* st);



