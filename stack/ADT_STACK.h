#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack_node{

	void* data_ptr;
	struct stack_node* link;

}STACK_NODE;

typedef struct stack {

	int count;
	STACK_NODE* top;

}STACK;

STACK* create_stack();
bool push(STACK* stack, void* in);
void* pop(STACK* stack);


