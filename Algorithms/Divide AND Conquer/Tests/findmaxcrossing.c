/*Find Max Crossing Subarray, ALGORITHM*/
#include <stdio.h>

int find_max_subarray(int A[], int low, int mid, int high) {
	int left_sum = 0, sum = 0, max_left;

	for(int i = mid; i >= low; i--) {
		sum+=A[i];
		if(sum>left_sum) {
			left_sum = sum;
			max_left = i;
		}
	}

	int right_sum = 0, max_right;
	sum = 0;

	for(int j = mid+1; j <= high; j++) {
		sum+=A[j];
		if(sum>right_sum) {
			right_sum = sum;
			max_right = j;
		}
	}

	printf(" max_left: %d\n", max_left);
	printf(" max_right: %d\n", max_right);

	return (left_sum+right_sum);
}


int main(void) {
	int A[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

	printf(" %d", fin_max_subarray(A, 0, (0+19)/2, 19));

	return 0;
}