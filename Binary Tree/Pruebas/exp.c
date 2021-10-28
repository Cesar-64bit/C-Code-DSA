#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

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

/*Function to print a tree*/
void _preorder(NODE *root) {
	if(*root != NULL) {
		struct node *current;
		current = *root;

		printf("%d ", current->data);
		_preorder(&current->left);
		_preorder(&current->right);
	}
}

void _inorder(NODE *root) {
	if(*root != NULL){
		struct node *current;
		current = *root;

		_inorder(&current->left);
		printf("%d ", current->data);
		_inorder(&current->right);
	}
}

void _postorder(NODE *root) {
	if(*root != NULL) {
		struct node *current;
		current = *root;

		_postorder(&current->left);
		_postorder(&current->right);
		printf("%d ", current->data);
	}
}

int main(void) {
	NODE root = NULL;
	
	char option;
	int data;

	do {
		system("cls");
		printf(" 1. Insert\n");
		printf(" 2. View tree\n");
		printf(" 3. Exit\n\n");
		printf(" Insert an option: ");
		scanf("%c", &option);

		switch(option) {
			case '1':
				printf("\n Insert node: ");
				scanf("%d", &data);

				_create_node(&root, data);

				getch();
				break;

			case '2':
				printf("\n\n Preorder: ");
				_preorder(&root);

				printf("\n Inorder: ");
				_inorder(&root);

				printf("\n Postorder: ");
				_postorder(&root);

				getch();
				break;
		}

	}while(option != '3');
	return 0;
}