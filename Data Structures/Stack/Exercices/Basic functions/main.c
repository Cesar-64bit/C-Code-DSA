#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

typedef struct node *NODE;

void PUSH(NODE *top, int data) {
	struct node *new_node;
	new_node = (struct node*)malloc(sizeof(struct node));

	new_node->data = data;
	new_node->next = *top;
	*top = new_node;
}

void POP(NODE *top) {
	struct node *aux;
	aux = *top;

	*top = aux->next;
	free(aux);
}

/*Eliminar un nodo especifico en la pila*/
void spc_pop(NODE *top, int data) {
	struct node *search, *previous;
	search = *top;

	if(search->data == data && search == *top)
		POP(top);
	else {
		previous = search;
		search = search->next;

		while(search->next != NULL){
			if(search->data == data) {
				previous->next = search->next;
				free(search);
				break;
			}
			previous = search;
			search = search->next;
		}
	}
	if(search->data == data && search->next == NULL) {
		previous->next = search->next;
		free(search);
	}
}

void PRINT(NODE *top) {
	if(*top != NULL) {
		struct node *search;
		search = *top;

		while(search->next != NULL) {
			printf("[%d]\n", search->data);
			search = search->next;
		}

		printf("[%d]", search->data);
	}
	else
		puts("Pila vacia");
}

int main(void) {
	NODE top = NULL;

	/*Se ingresan elementos en la pila*/
	PUSH(&top, 7); //
	PUSH(&top, 6);
	PUSH(&top, 5);
	PUSH(&top, 4); //
	PUSH(&top, 3);
	PUSH(&top, 2); //
	PUSH(&top, 1); //

	/*Se elimina un elemento específico de la pila*/
	spc_pop(&top, 7);
	spc_pop(&top, 1);
	spc_pop(&top, 4);

	POP(&top);
	POP(&top);
	POP(&top);

	spc_pop(&top, 6);

	/*Se imprime la pila*/
	PRINT(&top);

	return 0;
}