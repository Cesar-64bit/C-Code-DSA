#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *left;
	int data;
	struct node *right;
};

typedef struct node *NODE;

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

void _create_node(NODE *root, int data) {
	struct node *new_node;
	new_node = (struct node*)malloc(sizeof(struct node));

	new_node->left = NULL;
	new_node->data = data;
	new_node->right = NULL;

	if(*root == NULL)
		*root = new_node;
	else
		_add_node(root, data, new_node);
}

void _inorder(NODE *root) {
	if(*root != NULL) {
		struct node *current;
		current = *root;

		_inorder(&current->left);
		printf("[%d]", current->data);
		_inorder(&current->right);
	}
}

void _preorder(NODE *root) {
	if(*root != NULL) {
		struct node *current;
		current = *root;

		printf("[%d]", current->data);
		_preorder(&current->left);
		_preorder(&current->right);
	}
}

void _postorder(NODE *root) {
	if(*root != NULL) {
		struct node *current;
		current = *root;

		_postorder(&current->left);
		_postorder(&current->right);
		printf("[%d]", current->data);
	}
}

int main(void) {
	NODE root = NULL;

	_create_node(&root, 18);
	_create_node(&root, 12);
	_create_node(&root, 7);
	_create_node(&root, 4);
	_create_node(&root, 19);
	_create_node(&root, 30);
	_create_node(&root, 23);
	_create_node(&root, 28);
	_create_node(&root, 9);
	
	_inorder(&root);
	puts("");
	_preorder(&root);
	puts("");
	_postorder(&root);


	return 0;
}