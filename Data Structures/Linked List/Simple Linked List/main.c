#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node {
	int data;
	struct node *next;
};

typedef struct node *NODE;

void add_to_list(NODE *head, int data) {
	struct node *new_node;
	new_node = (struct node*)malloc(sizeof(struct node));

	if(new_node == NULL) {
		puts("\n Insufficient memory");
		getch();
	}
	else {
		new_node->data = data;
		new_node->next = NULL;

		if(*head == NULL)
			*head = new_node;
		else {
			struct node *search;
			search = *head;

			while(search->next != NULL)
				search = search->next;
			
			search->next = new_node;
		}
	}
}

bool empty_list(NODE *head) {
	if(*head == NULL)
		return true;
	return false; 
}

void delete_element(NODE *head, int data) {
	bool ban = false;

	if(empty_list(head) == true) {
		puts("\n Empty list");
		getch();
	}
	else {
		struct node *aux_node, *previous;
		aux_node = *head;
		previous = *head;

		if(aux_node->data == data) {
			*head = aux_node->next;
			free(aux_node);
		}
		else {
			while(aux_node->next != NULL) {
				if(aux_node->data == data) {
					previous->next = aux_node->next;
					free(aux_node);
					ban = true;
					break;
				}
				previous = aux_node;
				aux_node = aux_node->next;
			}
			
			if(aux_node->data == data) {
				previous->next = aux_node->next;
				free(aux_node);
			}
			else if(ban != true){
				puts("\n No data found");
				getch();
			}
		}
	}
}

struct node *search(NODE *head, int data) {
	struct node* aux_node;
	aux_node = *head;

	if(empty_list(head) == true) {
		puts("\n Empty list");
		getch();
	}
	else {
		while(aux_node->next != NULL) {
			if(aux_node->data == data)
				return aux_node;
			aux_node = aux_node->next;
		}
		if(aux_node->data == data)
			return aux_node;
	}
	return aux_node->next;
}

void show_list(NODE *head) {
	if(empty_list(head) == true) {
		puts("\n Empty list");
		getch();
	}
	else {
		struct node *aux_node;
		aux_node = *head;

		while(aux_node->next != NULL) {
			printf(" %d <-", aux_node->data);
			aux_node = aux_node->next;
		}
		printf(" %d <-", aux_node->data);
	}
}

int main(void) {
	NODE head = NULL;

	add_to_list(&head, 28);
	add_to_list(&head, 99);
	add_to_list(&head, 1000);

	delete_element(&head, 99);

	show_list(&head);

	struct node *location;
	location = search(&head, 1000);

	if(location != NULL) {
		printf("\n If found");
	}
	else {
		puts("\n The data not found");
		getch();
	}
}