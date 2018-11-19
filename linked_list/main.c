#include "ADT_LLIST.h"


int main(){

	LLIST* l1=create_list();

	if(l1==NULL){
		printf("not create\n");
		return 0;
	}

	int a[3]={1,2,3}, i;

	if(!add_node_at(l1,0,a)){
		printf("first fail \n");
		return 0;
	}
	
	print(l1);

	if(!add_node_at(l1,1,a+2)){
		printf("second fail \n");
		return 0;
	}

	print(l1);

	if(!add_node_at(l1,1,a+1)){
		printf("3 fail \n");
		return 0;
	}
	print(l1);

	if(!del_node_at(l1,2)){
		printf("3 fail \n");
		return 0;
	}
	print(l1);
	
	if(!del_node_at(l1,1)){
		printf("3 fail \n");
		return 0;
	}
	print(l1);
}
