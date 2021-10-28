#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *left, *right;
	int data;
};

typedef struct node *NODE;

/*Recursive function to add node at the tree*/
void _add_node(NODE *root, int data, struct node *new_node) {
	struct node *current;
	current = *root;

	if(data < current->data) {
		if(current->left == NULL)
			current->left = new_node;
		else
			_add_node(&current->left, data, new_node);
	}
	else if(data > current->data) {
		if(current->right == NULL)
			current->right = new_node;
		else
			_add_node(&current->right, data, new_node);
	}

}

/*Function to create a node*/
void _create_node(NODE *root, int data) {
	struct node *new_node;
	new_node = (struct node*)malloc(sizeof(struct node));

	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;

	if(*root == NULL)
		*root = new_node;
	else
		_add_node(root, data, new_node);
}

/*Funtion to print a tree*/
void _preorder(NODE *root) {
	if(*root != NULL) {
		struct node *current;
		current = *root;

		printf("%d\n", current->data);

		_preorder(&current->left);
		_preorder(&current->right);
	}
}

int main(void) {
	NODE root = NULL;

	_create_node(&root, 10);
	_create_node(&root, 11);
	_create_node(&root, 9);
	_create_node(&root, 8);
	_create_node(&root, 13);
	_create_node(&root, 12);

	_preorder(&root);

	return 0;
}