#include "ADT_STACK.h"


STACK* create_stack(){

	STACK* stack = (STACK*)malloc(sizeof(STACK));

	if(!stack) return NULL;

	stack -> count = 0;
	stack -> top = NULL;

	return stack;
}

bool push(STACK* stack, void* in){

	STACK_NODE* new_node = (STACK_NODE*)malloc(sizeof(STACK_NODE));

	if(!new_node) return false;

	new_node -> data_ptr = in;
	new_node -> link = stack->top;

	stack -> top = new_node;
	stack -> count++;

	return true;
}

void* pop(STACK* stack){

	STACK_NODE* temp = stack->top;

	if(stack -> count == 0)
		return NULL;

	void* data_out = stack->top->data_ptr;

	stack -> top =  stack->top->link;

	free(temp);
	stack -> count --;

	return data_out;
}
