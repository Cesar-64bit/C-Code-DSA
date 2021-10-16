#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node {
	int data;
	struct node *next;
};

typedef struct node *NODE;

int _add_node(NODE *head, int data)
{
	struct node *new_node;
	new_node = (struct node*)malloc(sizeof(struct node));

	if(new_node == NULL) {
		puts("\n Insufficient memory");
		getch();
	}
	else {
		new_node->data = data;

		if(*head == NULL) {
			*head = new_node;
			new_node->next = *head;
		}
		else {
			struct node *search;
			search = *head;

			while(search->next != *head)
				search = search->next;

			search->next = new_node;
			new_node->next = *head;
		}
	}
}

bool _empty_list(NODE *head)
{
	if(*head == NULL)
		return true;
	return false;
}

void _show_list(NODE *head)
{
	if(_empty_list(head) == true)
		puts("\n Empty list");
	else {
		struct node *aux_node;
		aux_node = *head;

		while(aux_node->next != *head) {
			printf(" \t\t%p \t\t%d\n", aux_node, aux_node->data);
			aux_node = aux_node->next;
		}
		printf(" \t\t%p \t\t%d\n", aux_node->next, aux_node->data);
	}
}

int main(void)
{
	NODE head = NULL;

	_add_node(&head, 28);
	_add_node(&head, 39);
	_add_node(&head, 99);

	printf(" \t\t Memory \t\t Data\n");

	_show_list(&head);

	return 0;
}