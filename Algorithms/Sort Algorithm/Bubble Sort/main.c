#include <stdio.h>

//Complejidad O(n^2)
void bubble_sort(int A[], int length) {
	for(int i = 1; i < length; i++)
		for(int j = 0; j < (length-i); j++)
			if(A[j]>A[j+1]) {
				int aux = A[j+1];
				A[j+1] = A[j];
				A[j] = aux;
			}
}

int main(void) {
	int A[10] = {16,22,21,19,28,6,1,3,99,11};
	int length = sizeof(A)/sizeof(A[0]);

	bubble_sort(A, length);

	return 0;
}