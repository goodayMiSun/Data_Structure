#include "ADT_BST.h"

int main(void){

	BST_TREE* tree=create_bst();

	if(!tree){

		puts("not Create tree");

		return 0;

	}

	puts("Create tree");

	if(!BST_insert(tree, 1)){

		puts("not insert");

		return 0;
	}

	puts("insert succes");
	printf("Tree count : %d\n", tree->count);

	if(!BST_delete(tree, 1)){

		puts("not delete");
		return 0;

	}

	puts("delete succes");
	printf("Tree count : %d\n", tree->count);

	return 0;
}
		

