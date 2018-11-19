#include "stack.h"

int main(){

	ST* s1 = create();
	ST* s2 = create();
	ST* temp = create();

	if(s1 == NULL || s2 == NULL || temp == NULL) {
		printf("not create\n");
		return 0;
	}


	int a[10], i;
	void* t;

	for(i=0; i<10; i++){

		a[i]=i+1;

		if(i<5){
			if(!push(s1, a+i)){
				printf("not push\n");
				return 0;
			}
		}

		else{
			if(!push(s2, a+i)){
				printf("not push\n");
				return 0;
			}
		}

	}


	for(i=0; i<10; i++){

		if(i%2 == 0){
			t = pop(s2);
		}

		else
			t = pop(s1);

		if(t==NULL){
			printf("not pop\n");
			return 0;
		}
		
		if(!push(temp, t)){

			printf("not temp push\n");
			return 0;
		}
	}

	printf("s1 : %d s2 : %d temp : %d\n",s1->number, s2->number, temp->number);
	
	for(i=0; i<10; i++){

		t=pop(temp);

		if(t==NULL){
			printf("not temp pop \n");
			return 0;

		}

		if(!push(s1, t)){
			printf("not temp pop\n");
			return 0;
		}

	}

	printf("s1 : %d\n", s1->number);

	for(i=0; i<10; i++){
		
		t=pop(s1);
		if(t==NULL){
			printf("not s1 pop\n");
			return 0;
		}

		printf("%d ", *(int*)t);
	}

	printf("||\n");

	
			
}
	

















