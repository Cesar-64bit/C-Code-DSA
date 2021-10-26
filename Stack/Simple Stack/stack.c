#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "engine.h"

int valinum(int longitud);
float valifloat(int longitud);
void valitext(char *nombre, int longitud);
void valifecha(char *fecha);

struct articulos {
	int ID;
	float peso;
	char nombre[15];
	char fecha[10];
	struct articulos *siguiente;
};

typedef struct articulos *NODO;

void agregar(NODO *superior, int ID, float peso, char *nombre, char *fecha) {
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
		memset(fecha, 0, 10);

		nuevo->siguiente = *superior;
		*superior = nuevo;

		puts("\n\n Se ha agregado");
	}
}

int vacio(NODO *superior) { 
	return (*superior == NULL); 
}

struct articulos *buscar(NODO *superior, int ID) {
	struct articulos *auxiliar;
	auxiliar = *superior;

	while(auxiliar->siguiente != NULL) {
		if(auxiliar->ID == ID)
			return auxiliar;
		auxiliar = auxiliar->siguiente;
	}

	if(auxiliar->ID == ID)
		return auxiliar;

	return auxiliar->siguiente;
}

void modificar(NODO *superior) {
	if(vacio(superior) == 0) {
		struct articulos *direccion;
		int ID;
		printf("\n Ingrese el ID: ");
		ID = valinum(5);
		direccion = buscar(superior, ID);

		if(direccion != NULL) {
			float peso;
			char nombre[15];
			char fecha[10];
			printf("\n Peso: ");
			peso = valifloat(10);
			direccion->peso = peso;
			printf("\n Nombre: ");
			valitext(nombre, 15);
			strcpy(direccion->nombre, nombre);
			memset(nombre, 0, 15);
			printf("\n Fecha: ");
			valifecha(fecha);
			strcpy(direccion->fecha, fecha);
			memset(fecha, 0, 10);
		}
		else
			puts("\n No se encontro");
	}
	else
		puts("\n No hay elementos");
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
			printf("%p", auxiliar);
			printf("\t\t%d", auxiliar->ID);
			printf("\t\t%0.2f", auxiliar->peso);
			printf("\t\t%s", auxiliar->nombre);
			printf("\t\t%s", auxiliar->fecha);
			printf("\t\t%p", auxiliar->siguiente);
			printf("\n");

			auxiliar = auxiliar->siguiente;
		}
		printf("%p", auxiliar);
		printf("\t\t%d", auxiliar->ID);
		printf("\t\t%0.2f", auxiliar->peso);
		printf("\t\t%s", auxiliar->nombre);
		printf("\t\t%s", auxiliar->fecha);
		printf("\t\t%p", auxiliar->siguiente);
	}
	else
		puts("\n No hay elementos");
}