#include <stdio.h>
#include "engine.h"

void menu(void) {
	puts("\n 1. Agregar");
	puts(" 2. Modificar");
	puts(" 3. Eliminar");
	puts(" 4. mostrar");
	puts(" 5. Salir");
	printf("\n\n Seleccione una opcion: ");
}

int main(void) {
	NODO superior = NULL;
	char nombre[15];
	char fecha[10];
	char opcion;
	int ID;
	float peso;

	do {
		menu();
		scanf("%c", &opcion);
		system("cls");

		switch(opcion) {
			case '1':
				printf("\n --- AGREGAR ---");

				printf("\n Ingrese el ID: ");
				ID = valinum(5);

				printf("\n Ingrese el peso: ");
				peso = valifloat(10);

				printf("\n Ingrese el nombre: ");
				valitext(nombre, 15);

				printf("\n Ingrese la fecha: ");
				valifecha(fecha);

				agregar(&superior, ID, peso, nombre, fecha);

				printf("\n\n Presione cualquier tecla para continuar...");
				getch();
				break;

			case '2':
				printf("\n\n Presione cualquier tecla para continuar...");
				getch();
				break;

			case '3':
				eliminar(&superior);

				printf("\n\n Presione cualquier tecla para continuar...");
				getch();
				break;

			case '4':
				mostrar(&superior);	

				printf("\n\n Presione cualquier tecla para continuar...");
				getch();
				break;
		}
	}while(opcion != '5');

	return 0;
}