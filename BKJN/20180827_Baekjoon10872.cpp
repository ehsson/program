#include <stdio.h>

int main(void)
{
	int n, temp = 1;

	scanf_s("%d", &n);

	for (int k = 1; k <= n; k++) {
		temp *= k;
	}

	printf("%d\n", temp);

	return 0;
}