#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

typedef struct node *NODE;

void enqueue(NODE *tail, int data) {
	struct node *new_node;
	new_node = (struct node*)malloc(sizeof(struct node));

	new_node->data = data;
	new_node->next = NULL;

	if(*tail == NULL)
		*tail = new_node;
	else {
		struct node *search;
		search = *tail;

		while(search->next != NULL)
			search = search->next;

		search->next = new_node;
	}
}

void dequeue(NODE *tail) {
	struct node *aux;
	aux = *tail;

	*tail = aux->next;
	free(aux);
}

void print(NODE *tail) {
	struct node *search;
	search = *tail;

	while(search->next != NULL) {
		printf("[%d]", search->data);
		search = search->next;
	}

	printf("[%d]", search->data);
}

int main(void) {	
	NODE tail = NULL;

	enqueue(&tail, 1);
	enqueue(&tail, 2);
	enqueue(&tail, 3);

	dequeue(&tail);
	dequeue(&tail);

	print(&tail);

	return 0;
}