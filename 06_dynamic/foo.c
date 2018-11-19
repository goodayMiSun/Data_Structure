#include <stdio.h>
#include <stdlib.h>

struct human{
	
	char name[100];
	int age;
};

typedef struct human HUMAN;

void update_age(HUMAN* h){
		h->age++;
}


int main(){

	struct human h1 = {"misun", 23};
	struct human h2 = {"enji", 23};
	
	h1.age = 21;	
	h2.age = 25;

	
	struct human* hp1 = (struct human*)malloc(sizeof(struct human));

	HUMAN* hp2 = (struct human*)malloc(sizeof(struct human));

	hp1->age=12;
	hp2->age=16;

	update_age(hp1);
	printf("hp1's age : %d\n", hp1->age);
}
