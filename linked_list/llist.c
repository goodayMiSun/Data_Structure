#include "llist.h"

LLIST* create(){

	LLIST* new = (LLIST*)malloc(sizeof(LLIST));

	if(!new) return NULL;

	new->number=0;
	new->front = NULL;
	new->rear = NULL;
	new->pos = NULL;

	return new;
}


bool inlist(LLIST* l, int num, void* in){


	NODE* new = (NODE*)malloc(sizeof(NODE));
	int i;

	if(!new || num > l->number)
		return false;

	new->d=in;

	if(l->number == 0){

		l->front = new;
		l->rear = new;
		new->next = NULL;
		l->number++;
		return true;
	}

	l->pos = l->front;
	i=1;

	while(i!=num){
		
		l->pos = l->pos->next;
		i++;	
	}

	if(num == 0){
		new->next = l->front;
		l->front = new;
		l->number++;

		return true;
	}

	else if(num == l->number){
		new->next = NULL;
		l->rear->next = new;
		l->rear = new;
		l->number ++;

		return true;
	}

	else{

		new->next = l->pos->next;
		l->pos = new;
		l->number++;

		return true;
	}


	return false;


}


bool delist(LLIST* l, int num){

	NODE* pre=NULL;
	int i;
	if(l->number >= num) return false;
	
	l->pos = l->front;
	i=0;
	if(l->number == 1){
		
		free(l->front);
		l->front = NULL;
		l->rear = NULL;
		l->number --;

	}

	while(num!=i){
		pre = l->pos;
		l->pos=l->pos->next;
		i++;
	}

	if(num == 0){
		
		l->front = l->front->next;
		free(l->pos);
		l->number--;

		return true;
	}

	else if(num == l->number-1){

		pre->next = NULL;
		free(l->pos);
		l->number--;

		return true;

	}

	else{

		pre= l->pos->next;
		free(l->pos);
		l->number--;

		return true;
	}
	return false;

}















