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
		puts("Insufficient memory");
	else {
		new_node->data = data;

		if(*head == NULL) {
			*head = new_node;
			new_node->previous = *head;
			new_node->next = *head;
		}
		else {
			struct node *last, *ini;
			ini=last=*head;

			while(last->next != *head)
				last = last->next;

			last->next = new_node;
			new_node->previous = last;
			new_node->next = *head;
			ini->previous = new_node;
		}
	}
}

void _print_list(NODE *head) {
	struct node *ini, *last;
	ini = *head;

	printf("\n Forward: ");

	while(ini->next != *head) {
		printf("%d->", ini->data);
		ini = ini->next;
	}
	printf("%d->%d", ini->data, ini->next->data);

	last = ini;

	printf("\n Backward: ");
	while(ini->previous != last) {
		printf("%d->", ini->data);
		ini = ini->previous;
	}
	printf("%d->%d", ini->data, ini->previous->data);
}

int main(void) {
	NODE head = NULL;

	_add_node(&head, 1);
	_add_node(&head, 2);
	_add_node(&head, 3);

	_print_list(&head);

	return 0;
}