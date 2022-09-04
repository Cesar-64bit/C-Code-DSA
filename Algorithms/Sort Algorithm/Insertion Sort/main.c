#include <stdio.h>

void insertion_sort(int A[], int length) {
	for(int j = 1; j < length; j++) {
		int key = A[j];
		int i = j-1;
		while(i>=0 && A[i]>key) {
			A[i+1] = A[i];
			i--;
		}
		A[i+1] = key;
	}
}

int main(void) {
	int A[] = {16,22,21,19,28,6,1,3,99,11};
	int length = sizeof(A)/sizeof(A[0]);

	insertion_sort(A, length);

	return 0;
}