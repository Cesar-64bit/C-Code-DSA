#include <stdio.h>

// Obtención del mínimo con n-1 comparaciones, donde n = longitud de A
int MINIMUM(int A[], int length) {
	int min = A[0];
	for(int i = 1; i < length; i++)
		if(min>A[i])
			min = A[i];
	return min;
}
// Obtención del máximo con n-1 comparaciones, donde n = longitud de A
int MAXIMUN(int A[], int length) {
	int max = A[0];
	for(int i = 0; i < length; i++)
		if(max<A[i])
			max = A[i];
	return max;
}

int main(void) {
	int A[] = {9,8,28,6,5,4,3,2,1};
	int min = MINIMUM(A, 9);
	int max = MAXIMUN(A, 9);
	printf("MINIMUM: %d\nMAXIMUM: %d", min, max);
	
	return 0;
}