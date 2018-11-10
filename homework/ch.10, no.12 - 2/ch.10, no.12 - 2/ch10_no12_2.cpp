#include <stdio.h>

int main(void)
{
	int arr[3][3] = {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 }
	};
	int temp[3] = { 0 };

	for (int k = 0; k < 3; k++) {
		for (int i = k; i < 3; i++) {
			temp[i] = arr[i][k];
			arr[i][k] = arr[k][i];
			arr[k][i] = temp[i];
		}
	}

	for (int s = 0; s < 3; s++) {
		for (int r = 0; r < 3; r++) {
			printf("%d ", arr[s][r]);
		}

		printf("\n");
	}

	return 0;
}