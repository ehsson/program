#include <stdio.h>

int main(void)
{
	int arr[5] = { 0 };
	int sum = 0, mean;

	for (int k = 0; k < 5; k++) {
		scanf_s("%d", &arr[k]);
	}

	for (int t = 0; t < 5; t++) {
		if (arr[t] < 40) arr[t] = 40;
		sum += arr[t];
	}

	mean = sum / 5;

	printf("%d\n", mean);

	return 0;
}