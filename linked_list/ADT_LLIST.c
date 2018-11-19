#include "ADT_LLIST.h"


LLIST* create_list(){

	LLIST* create = (LLIST*)malloc(sizeof(LLIST));

	if(!create)
		return NULL;

	create->count=0;
	create->front=NULL;
	create->rear=NULL;
	create->pos=NULL;

	return create;
}

bool add_node_at(LLIST* list, unsigned int index, void* in){
		
	NODE* new = (NODE*)malloc(sizeof(NODE));

	if(index>list->count || !new){
		free(new);
		return false;
	}

	new->data_ptr = in;
	new->next=NULL;

	if(list->count == 0){

		list->front = new;
		list->rear = new;
		list->pos = NULL;

		list->count++;
		
		return true;
	}

	list->pos = list->front;
	int iter_i=1;

	while(iter_i != index){

		list->pos = list->pos->next;
		iter_i++;
	}

	if(index==0){

		new->next = list->front;
		list->front=new;
		list->pos = NULL;
	
		list->count++;
		
		return true;
	}

	else if(index == list->count){

		list->rear->next=new;
		list->rear=new;
		list->pos = NULL;
		
		list->count++;

		return true;
	}

	else{

		new->next = list->pos->next;
		list->pos->next = new;
		list->pos = NULL;

		list->count++;

		return true;
	}

	return false;

	

}

bool del_node_at(LLIST* list, unsigned int index){

	if(index >= list->count || list->count == 0)
		return false;

	NODE* pre= NULL;
	list->pos = list->front;

	if(list->count == 1){
		
		free(list->pos);
		
		list->front = NULL;
		list->rear = NULL;
		list->pos = NULL;

		list->count--;

		return true;

	}

	int iter_i = 0;

	while(iter_i != index){

		pre = list->pos;
		list->pos = list->pos->next;

		iter_i++;

	}

	if(index == 0){
		
		list->front = list->front->next;
		free(list->pos);

		list->count--;

		return true;
	}

	else if (index == list->count-1){

		pre->next = NULL;
		list->rear = pre;
		
		free(list->pos);

		list->count--;

		return true;
	}

	else{

		pre->next = list->pos->next;
		free(list->pos);

		list->count--;

		return true;
	}

	return false;
}


void print(LLIST* list){

	list->pos = list->front;

	while(list->pos != NULL){
		printf("%d ", *(int*)list->pos->data_ptr);
		list->pos=list->pos->next;
	}

	printf("\n");

}
