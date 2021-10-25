#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*Función para leer solamente números enteros*/
int valinum(int longitud) {
	char caracter;
	int indice = 0;
	char *numero;

	numero = (char*)malloc(sizeof(char));

	do {
		caracter = getch();

		if(caracter>=48 && caracter<=57) {
			printf("%c", caracter);
			*(numero+indice) = caracter;
			indice++;
		}
		else if(caracter==8 && indice>0) {
			indice--;
			printf("\b \b");
			*(numero+indice) = '\0';
		}
	}while(indice == 0 || (caracter!=13 && indice<longitud));

	char copia[indice];

	strcpy(copia, numero);
	free(numero);

	return atoi(copia);
}

/*función para leer solamente números flotantes*/
float valifloat(int longitud) {
	char caracter;
	char *numero;
	int indice = 0, punto = 0;

	numero = (char*)malloc(sizeof(char));

	do {
		caracter = getch();

		if(caracter>=48 && caracter<=57) {
			printf("%c", caracter);
			*(numero+indice) = caracter;
			indice++;
		}
		else if(caracter==46) {
			if(indice==0 && punto==0) {
				printf("0");
				printf("%c", caracter);
				*(numero+indice) = '0';
				*(numero+(indice+1)) = '.';
				indice+=2;
				punto++;
			}
			else if(punto == 0) {
				printf("%c", caracter);
				*(numero+indice) = caracter;
				indice++;
				punto++;
			}
		}
		else if(caracter==8 && indice>0) {
			if(*(numero+(indice-1))==46)
				punto--;
			
			indice--;
			printf("\b \b");
			*(numero+indice) = '\0';
		}
	}while(indice==0 || (caracter!=13 && indice<longitud));

	char copia[indice];

	strcpy(copia, numero);
	free(numero);

	return atof(copia);
}

void valitext(char *nombre, int longitud) {
	int indice = 0;
	char caracter;

	do {
		caracter = getch();

		if((caracter>=65&&caracter<=90)||(caracter>=97&&caracter<=122)||caracter==32) {
			printf("%c", caracter);
			*(nombre+indice) = caracter;
			indice++;
		}
		else if(caracter==8&&indice>0) {
			indice--;
			printf("\b \b");
			*(nombre+indice) = '\0';
		}
	}while(indice==0 || (caracter!=13&&indice<longitud));

	*(nombre+indice) = '\0';
}

/*FECHA*/
int bisiesto(int anio) {
	if(anio%4==0&&(anio%100!=0||anio%400==0))
		return 1;
	return 0;
}

int evaluar(char *anio, int indice) {
	int aa = atoi(anio);

	if(bisiesto(aa) == 1)
		return indice;
	return 0;
}

void copiar(char *fecha, char *anio, int indice) {
	int indanio = 0;

	while(indanio<4) {
		*(fecha+indice) = *(anio+indanio);
		indice++;
		indanio++;	
	}
}

void valifecha(char *fecha) {
	int indice = 0, indanio = 0;
	char caracter, *anio;
	anio = (char*)malloc(sizeof(char));

	do {
		caracter = getch();
		
		if(indice==0&&(caracter>=48&&caracter<=51)) {
			printf("%c", caracter);
			*(fecha+indice) = caracter;
			indice++;
		}
		else if(indice==1&&caracter!=8) {
			if(*(fecha+(indice-1))==48&&caracter>=49&&caracter<=57 ) {
				printf("%c", caracter);
				printf("/");
				*(fecha+indice) = caracter;
				*(fecha+(indice+1)) = '/';
				indice+=2;
			}
			else if(*(fecha+(indice-1))==49&&caracter>=48&&caracter<=57) {
				printf("%c", caracter);
				printf("/");
				*(fecha+indice) = caracter;
				*(fecha+(indice+1)) = '/';
				indice+=2;
			}
			else if(*(fecha+(indice-1))==50&&caracter>=48&&caracter<=57) {
				printf("%c", caracter);
				printf("/");
				*(fecha+indice) = caracter;
				*(fecha+(indice+1)) = '/';
				indice+=2;
			}
			else if(indice==1 && *(fecha+(indice-1))==51&&caracter>=48&&caracter<=49) {
				printf("%c", caracter);
				printf("/");
				*(fecha+indice) = caracter;
				*(fecha+(indice+1)) = '/';
				indice+=2;
			}		
		}
		else if(indice==3&&caracter!=8) {
			/*Si el día es 31*/
			if(((*(fecha+0)==51&&*(fecha+1)==49))&&(caracter>=48&&caracter<=49)) {
				printf("%c", caracter);
				*(fecha+indice) = caracter;
				indice++;
			}
			/*Si el día es 30*/
			else if(((*(fecha+0)==51&&*(fecha+1)==48))&&(caracter>=48&&caracter<=49)) {
				printf("%c", caracter);
				*(fecha+indice) = caracter;
				indice++;
			}
			else if(caracter>=48&&caracter<=49){
				printf("%c", caracter);
				*(fecha+indice) = caracter;
				indice++;
			}
		}
		else if(indice==4&&caracter!=8) {
			if(((*(fecha+0)==51&&*(fecha+1)==49))) {
				if(*(fecha+(indice-1))==48&&(caracter==49||caracter==51||caracter==53||caracter==55||caracter==56)) {
					printf("%c", caracter);
					printf("/");
					*(fecha+indice) = caracter;
					*(fecha+(indice+1)) = '/';
					indice+=2;
				}
				else if(*(fecha+(indice-1))==49&&(caracter==48||caracter==50)){
					printf("%c", caracter);
					printf("/");
					*(fecha+indice) = caracter;
					*(fecha+(indice+1)) = '/';
					indice+=2;	
				}
			}
			else if(((*(fecha+0)==51&&*(fecha+1)==48))) {
				if(*(fecha+(indice-1))==48&&(caracter==52||caracter==54||caracter==57)) {
					printf("%c", caracter);
					printf("/");
					*(fecha+indice) = caracter;
					*(fecha+(indice+1)) = '/';
					indice+=2;
				}
				else if(*(fecha+(indice-1))==49&&(caracter==49)) {
					printf("%c", caracter);
					printf("/");
					*(fecha+indice) = caracter;
					*(fecha+(indice+1)) = '/';
					indice+=2;	
				}
			}
			else if(*(fecha+(indice-1))==48&&(caracter>=49&&caracter<=57)) {
					printf("%c", caracter);
					printf("/");
					*(fecha+indice) = caracter;
					*(fecha+(indice+1)) = '/';
					indice+=2;
			}
			else if(*(fecha+(indice-1))==49&&(caracter>=48&&caracter<=50)) {
					printf("%c", caracter);
					printf("/");
					*(fecha+indice) = caracter;
					*(fecha+(indice+1)) = '/';
					indice+=2;	
			}
		}
		else if(indice>=6&&indice<=9&&caracter!=8) {
			printf("%c", caracter);
			*(fecha+indice) = caracter;
			*(anio+indanio) = caracter;
			indanio++;
			indice++;
		}
		else if(caracter==8&&indice>0) {
			indice--;
			printf("\b \b");
			*(fecha+indice) = '\0';
		}
		if(indice==10&&*(fecha+0)==50&&*(fecha+1)==57&&*(fecha+3)==48&&*(fecha+4)==50) {
			indice = evaluar(anio, indice);

			if(indice==10) {
				copiar(fecha, anio, 6);
				free(anio);
			}
			else {
				printf("\n Fecha no valida, ingrese una nueva: ");
				indanio = 0;
				memset(fecha, 0, 10);
			}
		}
	}while(indice<10);
}

/*Falta borrar y el año biciesto*/
