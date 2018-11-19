#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct qu_node{

	void* d;
	struct qu_node* next;

}QU_NODE;

typedef struct qu{

	int number;
	
	QU_NODE* front;
	QU_NODE* rear;

}QU;

QU* create();
bool enqueue(QU* q, void* insert);
void* dequeue(QU* q);




