#include <stdio.h>

int factorial(int N);

int main(void)
{
	int N;

	scanf_s("%d", &N);

	printf("%d팩토리얼은 %d입니다.", N, factorial(N));

	return 0;
}

int factorial(int N)
{
	if (N == 0) return 1;

	return N * factorial(N - 1);
}