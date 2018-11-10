#include <stdio.h>

int main(void)
{
	int arr[10] = { 0 };
	int A, B, C, ans, temp;

	scanf_s("%d %d %d", &A, &B, &C);

	ans = A * B * C;

	while (ans != 0) {
		temp = (int)(ans % 10);
		ans = (int)(ans / 10);
		arr[temp]++;
	}

	for (int k = 0; k < 10; k++) {
		printf("%d\n", arr[k]);
	}

	return 0;
}