#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct articulos {
	int ID;
	float peso;
	char nombre[15];
	char fecha[10];
	struct articulos *siguiente;
};

typedef struct articulos *NODO;

void agregar(NODO *superior, int ID, float peso, char *nombre, const char *fecha) {
	struct articulos *nuevo;
	nuevo = (struct articulos*)malloc(sizeof(struct articulos));

	if(nuevo == NULL)
		puts("\n Memoria insuficiente");
	else {
		nuevo->ID = ID;
		nuevo->peso = peso;
		strcpy(nuevo->nombre, nombre);
		memset(nombre, 0, 15);
		strcpy(nuevo->fecha, fecha);

		nuevo->siguiente = *superior;
		*superior = nuevo;

		puts("\n\n Se ha agregado");
	}
}

int vacio(NODO *superior) { 
	return (*superior == NULL); 
}

void eliminar(NODO *superior) {
	struct articulos *auxiliar;
	auxiliar = *superior;

	if(vacio(superior) == 0) {
		*superior = auxiliar->siguiente;
		free(auxiliar);

		puts("\n\n Se ha eliminado");
	}
	else
		puts("\n No hay elementos");
}

void mostrar(NODO *superior) {
	if(vacio(superior) == 0) {
		struct articulos *auxiliar;
		auxiliar = *superior;

		while(auxiliar->siguiente != NULL) {
			printf("\n ID: %d\n", auxiliar->ID);
			printf(" Peso: %0.2f\n", auxiliar->peso);
			printf(" Nombre: %s\n", auxiliar->nombre);
			printf(" Fecha: %s\n", auxiliar->fecha);

			auxiliar = auxiliar->siguiente;
		}

		printf("\n ID: %d\n", auxiliar->ID);
		printf(" Peso: %0.2f\n", auxiliar->peso);
		printf(" Nombre: %s\n", auxiliar->nombre);
		printf(" Fecha: %s\n", auxiliar->fecha);
	}
	else
		puts("\n No hay elementos");
}