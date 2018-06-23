#include <stdio.h>

int main(void)
{
	int x = 1, num;

	scanf_s("%d", &num);

	for (int k = num; k >= 1; k--) {
		x *= k;
	}

	printf("%d\n", x);

	return 0;
}