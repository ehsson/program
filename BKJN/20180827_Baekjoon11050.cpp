#include <stdio.h>

int main(void)
{
	int N, K, temp = 1, mul, p;

	scanf_s("%d %d", &N, &K);

	p = N;

	for (int t = 1; t <= K; t++) {
		temp *= p;
		p = N - t;
	}

	mul = temp;
	temp = 1;

	for (int i = 1; i <= K; i++) {
		temp *= i;
	}

	printf("%d\n", mul / temp);

	return 0;
}