#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *left;
	int data;
	struct node *right;
};

struct node *_add_node(int data) {
	struct node *new_node;
	new_node = (struct node*)malloc(sizeof(struct node));

	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}

int main(void) {

	struct node *root = _add_node(1);

	root->left = _add_node(2);
	root->right = _add_node(3);

	printf("%d<-", root->data);
	printf("%d<-", root->left->data);
	printf("%d", root->right->data);

	return 0;
}