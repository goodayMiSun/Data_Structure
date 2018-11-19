#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	
		void* data_ptr;
		struct node* link;
}STACK_NODE;

typedef struct stack{
		int count;
		STACK_NODE * top;
}STACK;

STACK* create_stack() {
	printf("creating a stack ... \n");
	STACK* stack = (STACK*)malloc(sizeof(STACK));
	if( !stack )
			return 0;

	stack->count=0;
	stack->top=NULL;
	return stack;
}

int push(STACK* stack, void* in){
		STACK_NODE* node = (STACK_NODE*)malloc(sizeof(STACK_NODE));
		if(!node)
				return 0;

		node -> data_ptr = in;
		node -> link = stack->top;
		stack -> top = node;
		(stack ->count) ++;

		return 1;
//변수만 바꿔서 냄
}

void* pop(STACK* stack){
	  STACK_NODE* temp = (STACK_NODE*)malloc(sizeof(STACK_NODE));
	  void* data;

	  if(stack->count == 0){
			  printf("Nothing");
			  return 0;
	  }
	  temp=stack->top;
	  data=stack->top->data_ptr;
	  stack->top=stack->top->link;
	  (stack->count)--;
	    
	  
	  free(temp);

	  return data;
}
	
int main(){

	STACK* s1= create_stack();
	printf("stack s1's size: %d\n", s1->count);
	
	int a=10, b=50;

	push(s1, &a);
	push(s1, &b);

	printf("stack s1's size : %d\n", s1-> count);

	printf("pop : %d, stack s1's size : %d\n", *(int*) pop(s1), s1-> count);
	printf("pop : %d, stack s1's size : %d\n", *(int*) pop(s1), s1-> count);
	printf("pop : %d, stack s1's size : %d\n", *(int*) pop(s1), s1-> count);
}
