#include "stack.h"

ST* create(){

	ST* new = (ST*)malloc(sizeof(ST));

	if(!new) return NULL;

	new->number==0;
	new ->first=NULL;

	return new;

}

bool push(ST* st, void * insert){

	ST_NODE* new = (ST_NODE*)malloc(sizeof(ST_NODE));
	
	if(!new)  return false;

	new->d = insert;
	new->next = st->first;

	st->first = new;

	st->number++;
	
	return true;
}

void* pop(ST* st){

	if(st->number == 0) return NULL;

	ST_NODE* temp = st->first;
	
	void* t = st->first->d;

	st->first=st->first->next;

	free(temp);
	st->number--;

	return t;


}













