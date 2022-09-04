/*Para que el algoritmo de búsqueda binaria funcione,
	el arreglo debe estar ordenado ascendentemente. */

#include <stdio.h>


/*Retorna la posición del elemento encontradom sino, retorna -1*/
int binary_search(int A[], int low, int high, int n) {
	int mid = (low+high)/2;

	if(low==high && n!=A[mid])
		return -1;
	else  {
		if(n == A[mid])
			return mid;
		else if(n<A[mid])
			return binary_search(A, low, mid-1, n);
		else
			return binary_search(A, mid+1, high, n);
	}
}

int main(void) {
	int A[10] = {1,2,3,4,5,6,7,8,9,10};

	int position = binary_search(A, 0, 9, 3);

	printf(" Position: %d", position);

	return 0;
}