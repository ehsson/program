#include <stdio.h>

void fibonacci(int n)
{
	int a = 0, b = 1, c;

	if (n == 1) {
		printf("%d\n", 1);
		return;
	}

	for (int k = 1; k < n; k++) {
		c = a + b;
		a = b;
		b = c;
	}

	printf("%d\n", c);
}

int main(void)
{
	int n;

	scanf_s("%d", &n);

	fibonacci(n);

	return 0;
}