#include "ADT_QUEUE.h"

QUEUE* create_queue(){

	QUEUE* queue = (QUEUE*) malloc(sizeof(QUEUE));
	
	if(!queue) return NULL;
	else printf("ing...\n");
	queue->count=0;

	queue->front=NULL;
	queue->rear=NULL;
	
	return queue;
}


bool enqueue(QUEUE* queue, void* in){

	QUEUE_NODE* new = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE));

	if(!new) return false;

	else printf("ing...\n");
	new-> data_ptr = in;

	new->next=NULL;
	

	if(queue->count == 0)
		queue->front = new;
	
	else
		queue->rear->next=new;
		

	queue->rear=new;
	queue->count++;

	return true;

}

void* dequeue(QUEUE* queue){

	if(queue->count == 0){
		printf("count 0\n");
		return NULL;
	}
	QUEUE_NODE* temp = queue->front;
	void* out = queue->front->data_ptr;
	
	if(queue->count == 1){
		queue->front=NULL;
		queue->rear=NULL;
	}
	else
		queue->front=queue->front->next;
	
	queue->count--;
	free(temp);

	return out;
}
