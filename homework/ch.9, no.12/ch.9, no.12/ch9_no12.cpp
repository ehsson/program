#include <stdio.h>
#include <stdlib.h>

int num;

void fibo(int depth, long long fib[])
{
	if (depth > num) {
		return;
	}

	fib[depth] = fib[depth - 1] + fib[depth - 2];

	fibo(depth + 1, fib);
}

int main(void)
{

	printf("정수를 입력하시오: ");
	scanf_s("%d", &num);

	long long * fib = (long long *)malloc(sizeof(long long) * (num + 1));

	fib[0] = 0;
	fib[1] = 1;

	fibo(2, fib);

	for (int i = 0; i <= num; i++) {
		printf("fib(%d) = %lld\n", i, fib[i]);
	}

	free(fib);

	return 0;
}