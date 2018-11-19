#include "ADT_BST.h"

BST_TREE* create_bst(){

	BST_TREE* new_tree = (BST_TREE*)malloc(sizeof(BST_TREE));

	new_tree->count = 0;
	new_tree->root = NULL;

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
		printf("%d ", root->data);
		traverse_inorder(root->right);
	}
}

void traverse_postorder(T_NODE* root){

	if(root != NULL){
		traverse_postorder(root->left);
		traverse_postorder(root->right);
		printf("%d ", root->data);
	}
}


T_NODE* find_smallest_node(T_NODE* root){

	if(root->left == NULL)
		return root;

	return find_smallest_node(root->left);

}

T_NODE* find_largest_node(T_NODE* root){

	if(root->right == NULL)
		return root;

	return find_largest_node(root->right);

}

T_NODE* search_bst(T_NODE* root, int key){

	if(root == NULL)
		return NULL;

	if(root->data < key)
		return search_bst(root->right, key);

	else if(root->data > key)
		return search_bst(root->left, key);

	else
		return root;

}

T_NODE* add_bst(T_NODE* root, int data){
	
	if(root == NULL){
		
		T_NODE* new_node = (T_NODE*)malloc(sizeof(T_NODE));

		new_node->data = data;
		new_node->left = NULL;
		new_node->right = NULL;

		return new_node;
	}

	else if(data >= root->data){
		root->right = add_bst(root->right, data);
		return root;
	}

	else{
		root->left = add_bst(root->left, data);
		return root;
	}
}

	


T_NODE* delete_bst(T_NODE* root, int key, bool* success){
	
	

	if(root == NULL){

	
	if(root->data > data){

		root->left = delete_bst(root->left, key, success);

	}

	else if(root->data < data){

		root->right = delete_bst(root->right , key, success);

	}

	else{
		
		T_NODE* temp = root;
		T_NODE* new_root;
		
		if(root->left == NULL){

			new_root = root->right;
			free(temp);

			*success = true;
			return new_root;

		}

		else{

			if(root->right == NULL){
				
				T_NODE* temp = root;
				new_root = root->left;
				free(temp);

				*success = true;
				return new_root;

			}

			else{

				T_NODE* search = root->left;

				while(search->right != NULL){

					search = search->right;

				}

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

	else{

		tree->root = newRoot;
		tree->count ++;

		return true;
	}
}


bool BST_delete(BST_TREE* tree, int data){
	
	bool success=false;
	T_NODE* newRoot = delete_bst(tree->root, data, &success);

	if(success){

		tree->root = newRoot;
		tree->count --;

		if(tree->count == 0)
			tree->root = NULL;

	}

	return success;

}
