#include <stdio.h>

/*Aún no lo termino*/

int FIND_LARGEST(int A[], int low, int high, int largest) {
	int mid = (low+high)/2;
	int a, b;

	if(A[mid]>largest)
		largest = A[mid];
	if(low!=high)
		FIND_LARGEST(A, low, mid, largest); 
	else
		return largest;
}

int main(void) {
	int A[] = {3,13,89,34,21,44,99,56,9};

	int largest = FIND_LARGEST(A, 0, 8, 0);

	printf("\n Largest: %d", largest);

	return 0;
}