#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *previous;
	int data;
	struct node *next;
};

typedef struct node *NODE;

void _add_node(NODE *head, int data) {
	struct node *new_node;
	new_node = (struct node*)malloc(sizeof(struct node));

	if(new_node == NULL)
		puts("Insufficient memory...");
	else {
		new_node->data = data;
		new_node->next = NULL;

		if(*head == NULL) {
			*head = new_node;
			new_node->previous = NULL;
		}
		else {
			struct node *search;
			search = *head;

			while(search->next != NULL)
				search = search->next;

			search->next = new_node;
			new_node->previous = search;
		}
	}
}

void _print_list(NODE *head) {
	struct node *last;
	last = *head;

	printf("\n Forward: ");

	while(last->next != NULL) {
		printf("%d->", last->data);
		last = last->next;
	}
	printf("%d", last->data);

	printf("\n Backward: ");
	while(last->previous != NULL) {
		printf("%d->", last->data);
		last = last->previous;
	}
	printf("%d", last->data);

}

int main(void) {
	NODE head = NULL;

	/*add node*/
	_add_node(&head, 1);
	_add_node(&head, 2);
	_add_node(&head, 3);

	/*print node*/
	_print_list(&head);

	return 0;
}