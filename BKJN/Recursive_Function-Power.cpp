#include <stdio.h>

int power(int x, int y);

int main(void)
{
	int x, y;

	scanf_s("%d %d", &x, &y);

	printf("%d ^ %d = %d\n", x, y, power(x, y));

	return 0;
}

int power(int x, int y)
{
	if (y == 0) return 1;

	return x * power(x, y - 1);
}