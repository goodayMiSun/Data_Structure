#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queue_node{

	void* data_ptr;

	struct queue_node * next;

}QUEUE_NODE;

typedef struct queue{

	int count;

	QUEUE_NODE * front;
	QUEUE_NODE * rear;

}QUEUE;


QUEUE* create_queue();
bool enqueue(QUEUE* queue, void* in);
void* dequeue(QUEUE* queue);

