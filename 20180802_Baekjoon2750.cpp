#include <stdio.h>

int main(void)
{
	int N, min, pos;
	int arr[1000] = { 0 };

	scanf_s("%d", &N);

	for (int k = 0; k < N; k++) {
		scanf_s("%d", &arr[k]);
	}

	for (int t = 0; t < N; t++) {
		min = 1001;
		for (int i = t; i < N; i++) {
			if (min > arr[i]) {
				min = arr[i];
				pos = i;
			}
		}
		arr[pos] = arr[t];
		arr[t] = min;
	}

	for (int k = 0; k < N; k++) {
		printf("%d", arr[k]);
		if (k != N - 1)
			printf("\n");
	}

	return 0;
}