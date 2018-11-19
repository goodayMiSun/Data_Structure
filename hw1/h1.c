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
	STACK* s2= create_stack();
	STACK* s3= create_stack();

	int i, j, in[10];

	for(i=0; i<10; i++)
		in[i]=i;


	for(i=0; i<5; i++){

		push(s1, in+i);
		push(s2, in+5+i);

	}




	while(s1->count !=0 ){
		
		if(s2->count ==0 )
			push(s3, pop(s1));

		else
			push(s3, pop(s2));
	}


	while(s3->count != 0)
		push(s1, pop(s3));

	while(s1->count != 0)
		printf("%d ", *((int*)pop(s1)));

	printf("\n");
}













