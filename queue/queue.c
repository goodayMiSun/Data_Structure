#include "queue.h"

QU* create(){

	QU* new =(QU*)malloc(sizeof(QU));
	
	if(!new) return NULL;

	new->number=0;
	new->front=NULL;
	new->front=NULL;
	
	return new;

}

bool enqueue(QU* q, void* insert){

	QU_NODE* new = (QU_NODE*)malloc(sizeof(QU_NODE));
	
	if(!new) return false;

	new->d = insert;
	new->next=NULL;

	if(q->number ==0)
		q->front = new;
		
	else
		q->rear->next = new;

	q->rear = new;
	
	q->number++;
	return true;

}

void* dequeue(QU* q){

	QU_NODE* temp;

	if(q->number == 0)
		return NULL;

	void* out = q->front->d;

	temp = q->front;

	if(q->number == 1){

		q->front = NULL;
		q->rear = NULL;
	}

	else{

		q->front = q->front->next;
	}


	free(temp);
	q->number--;
	return out;


}

















