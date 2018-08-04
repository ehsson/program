#include <stdio.h>

#define MAX 1000000

int arr[1000000] = { 0 };
int counter[2000002] = { 0 };


void counter_sort(int N)
{
	int rm_num = 0;

	for (int k = 0; k < N; k++) {
		counter[arr[k] + MAX]++;
	}

	for (int t = 0; t < MAX * 2 + 2; t++) {
		for (int i = 0; i < counter[t]; i++) {
			arr[rm_num] = t;
			rm_num++;
		}
	}
}

int main(void)
{
	int N;

	scanf_s("%d", &N);

	for (int k = 0; k < N; k++) {
		scanf_s("%d", &arr[k]);
	}

	counter_sort(N);

	for (int k = 0; k < N; k++) {
		printf("%d", arr[k] - MAX);
		if (k != N - 1)
			printf("\n");
	}

	return 0;
}