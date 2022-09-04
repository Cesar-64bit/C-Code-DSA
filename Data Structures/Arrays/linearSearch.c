/* Aplicación de un algoritmo de busqueda lineal
	en un arreglo unidimensional. */

#include <stdio.h>
#include <stdlib.h>

/* En caso de que si se encuentre el número buscado
	entonces se retorna true. */
bool search(int A[], int n) {
	int length = sizeof(A)/sizeof(A[0]); /* Obtención de la longitud del arreglo */
	int i = 0;

	while(i<length && A[i]!=n)
		i++;

	if(A[i] == n)
		return true;

	return false;
}

int main(void) {
	int A[] = {3,9,8,1,2,3,28,39};

	bool found = search(A, 9);

	if(found == true)
		printf(" Yes");
	else
		printf(" No");
}