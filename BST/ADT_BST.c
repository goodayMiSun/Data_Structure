#include "ADT_BST.h"

BST_TREE* create_bst(){

	BST_TREE* new_tree = (BST_TREE*)malloc(sizeof(BST_TREE));

	if(!new_tree)
		return NULL;

	new_tree -> count = 0;
	new_tree -> root = NULL;

	return new_tree;

}

void traverse_preorder(T_NODE* root){

	if(root != NULL){
		printf("%d ", root->data);
		traverse_preorder(root->left);
		traverse_preorder(root->right);

	}
}

void traverse_inorder(T_NODE* root){

	if(root != NULL){
		traverse_inorder(root->left);
		printf("%d ", root->data);// when void*, *(int*)
		traverse_inorder(root->right);
	}

}

void traverse_postorder(T_NODE* root){

	if(root != NULL){
		traverse_postorder(root->left);
		traverse_postorder(root->right);
		printf("%d ", root->data);// when void*, *(int*)
	}
}

T_NODE* find_smallest_node(T_NODE* root){

	if(root->left == NULL)
		return root;

	else
		return find_smallest_node(root->left);

}

T_NODE* find_largest_node(T_NODE* root){

	if(root->right == NULL)
		return root;
	
	else
		return find_largest_node(root->right);

}

T_NODE* search_bst(T_NODE* root, int key){

	if(root == NULL) 
		return NULL;
	
	else if(root->data > key)
		return search_bst(root->left, key);

	else if(root->data < key)
		return search_bst(root->right, key);
	
	else 
		return root;

}


T_NODE* add_bst(T_NODE* root, int data){

	if(root == NULL){//leaf
	
		T_NODE* new_ptr = (T_NODE*)malloc(sizeof(T_NODE));

		new_ptr -> data = data;
		new_ptr -> left = NULL;
		new_ptr -> right = NULL;

		return new_ptr;

	}


	else if(root->data > key){
		
		root->left = add_bst(root->left, data);
		return root;
	
	}

	else {

		root->right = add_bst(root->right, key);
		return root;

	}

}

T_NODE* delete_bst(T_NODE* root, int data, bool* success){
	
	T_NODE* newRoot,*search;

	if(root == NULL){

		*success = false;
		return NULL;

    :wq

	//treverse

	else if(root->data > data)
		root->left = delete_bst(root->left, data, success);

	else if(root->data < data)
		root->right = delete_bst(root->right, data, success);

	else {
		
		T_NODE* deleted_node = root;

		if(root-> left == NULL){
			
			newRoot = root->right;
			free(deleted_node);
			*success =true;
			return newRoot;

		}

		else {
			
			if(root->right == NULL){
			
				newRoot = root->left;
				free(deleted_node);
				return newRoot;

			}

			else {

				search = root->left;

				while(search->right != NULL)
					search = search->right;

				root->data = search->data;
				root->left = delete_bst(root->left, search->data, success);

			}

		}

	}

	return root;

}




bool BST_insert(BST_TREE* tree, int data){

	T_NODE* newRoot = add_bst(tree->root, data);
	
	if(newRoot == NULL) return false;
	
	else {

		tree->root = newRoot;
		tree->count ++;

		return true;

	}

}

bool BST_delete(BST_TREE* tree, int data){

	bool success;
	T_NODE* newRoot;

	newRoot = delete_bst(tree->root, data, &success);

	if(success){

		tree->root = newRoot;
		tree->count--;

		if(tree->count == 0)// this need?
			tree->root = NULL;

	}

	return success;
}

		
