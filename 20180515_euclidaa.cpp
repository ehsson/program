#include <stdio.h>

int main(void)
{
	int x, y, z, w;
	printf("숫자 두개를 입력하시오.\n");
	scanf_s("%d %d", &x, &y);

	if (x < y) {
		z = x;
		x = y;
		y = z;
	}
	
	while (x % y != 0) {
		w = x % y;
		x = y;
		y = w;
	}
	printf("두 수의 최소공배수는 %d이다.\n", w);
	return 0;
}