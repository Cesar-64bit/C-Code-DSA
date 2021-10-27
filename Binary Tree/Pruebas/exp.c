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
		else {
			current = current->left;
			_add_node(&current, data, new_node);
		}
	}
	else if(data > current->data) {
		if(current->right == NULL)
			current->right = new_node;
		else
			_add_node(root, data, new_node);
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

int main(void) {
	NODE root = NULL;

	_create_node(&root, 10);
	_create_node(&root, 11);
	_create_node(&root, 9);
	_create_node(&root, 8);

	struct node *auxiliar;
	auxiliar = root;

	printf("%d\n", auxiliar->data);
	printf("%d\n", auxiliar->left->data);
	printf("%d\n", auxiliar->right->data);
	printf("%d", auxiliar->left->left->data);

	return 0;
}