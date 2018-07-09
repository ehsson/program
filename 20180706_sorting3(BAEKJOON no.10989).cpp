#include <stdio.h>

int arr[10001];

int main(void)
{
	int num, temp;

	scanf_s("%d", &num);

	for (int a = 0; a < num; a++) {
		scanf_s("%d", &temp);
		arr[temp]++;
	}

	for (int k = 0; k <= 10000; k++) {
		for (int i = 0; i < arr[k]; i++) {
			printf("%d\n", k);
		}
	}

	return 0;
}