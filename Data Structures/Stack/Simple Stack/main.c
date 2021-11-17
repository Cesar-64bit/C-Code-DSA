#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

typedef struct node *NODE;

void push(NODE *top, int data) {
	struct node *new_node;
	new_node = (struct node*)malloc(sizeof(struct node));

	new_node->data = data;
	new_node->next = *top;
	*top = new_node;
}

void pop(NODE *top) {
	struct node *aux;
	aux = *top;
	*top = aux->next;
	free(aux);
}

void print(NODE *top) {
	struct node *search;
	search = *top;

	while(search->next != NULL) {
		printf("[%d]", search->data);
		search = search->next;
	}
	printf("[%d]", search->data);
}

int main(void) {
	NODE tail = NULL;

	push(&tail, 3);
	push(&tail, 2);
	push(&tail, 1);

	pop(&tail);
	pop(&tail);
				
	print(&tail);

	return 0;
}