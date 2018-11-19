#include "queue.h"



int main(){

	QU* q1=create();
	QU* q2=create();
	QU* temp=create();

	if(q1==NULL || q2==NULL || temp==NULL){
		printf("not create\n");
		return 0;
	}

	int a[10], i;
	void* t;

	for(i=0; i<10; i++){

		a[i]=i+1;

		if(i<5){
			if(!enqueue(q1, a+i)){
				printf("not enqueue\n");
				return 0;
			}
		}

		else{
			if(!enqueue(q2, a+i)){
				printf("not enqueue\n");
				return 0;
			}

		}

	}

	printf("q1 : %d, q2 %d\n", q1->number, q2->number);

	for(i=0; i<10; i++){
		
		if(i%2==0){
			t = dequeue(q1);

			if(t==NULL){
				printf("not dequeue\n");
				return 0;
			}

		}

		else{
			t= dequeue(q2);

			if(t==NULL){
				printf("not dequeue\n");
				return 0;
			}
		}

		if(!enqueue(temp,t)){
			printf("not temp enqueue\n");
			return 0;

		}

	}

	printf("temp %d\n", temp->number);

	printf("<- ");
	for(i=0; i<10; i++){

		t=dequeue(temp);

		if(t==NULL){

			printf("not temp dequeue\n");
			return 0;
		}

		printf("%d ", *(int*)t);

	}


		printf("<-\n");


}




