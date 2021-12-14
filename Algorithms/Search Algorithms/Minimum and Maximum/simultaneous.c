#include <stdio.h>

// Obtención del indice
int INDEX(int length) {
	int index;
	(length%2==0) ? index = 2 : index = 1;
	return index;
}

// Asignación de mínimo y máximo
void ASSIGNMENT(int A[], int *min, int *max, int length) {
	if(length%2 == 0) {
		if(A[0] > A[1]) {
			*min = A[1];
			*max = A[0];
		}
		else {
			*min = A[0];
			*max = A[1];
		}
	}
	else {
		*min = A[0];
		*max = A[0];
	}
}

// Obtención del mínimo y máximo con 3[n/2] comparaciones
void MINIMUM_MAXIMUM(int A[], int *min, int *max, int length) {
	ASSIGNMENT(A, min, max, length);
	int index = INDEX(length);

	for(index; index < length-1; index+=2) {
		if(A[index]<A[index+1]) {
			if(A[index]<*min)
				*min = A[index];
			if(A[index+1]>*max)
				*max = A[index+1];
		}
		else {
			if(A[index+1]<*min)
				*min = A[index+1];
			if(A[index]>*max)
				*max = A[index];
		}
	}
}

int main(void) {
	// Longitud par
	int A[] = {9,28,6,5,4,3,2,199};
	int min, max;
	MINIMUM_MAXIMUM(A, &min, &max, 8);
	printf("MINIMUM: %d\nMAXIMUM: %d", min, max);

	return 0;
}