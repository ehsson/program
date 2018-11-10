#include <stdio.h>

int sum(int num)
{
	if (num == 0) {
		return 0;
	}

	return num + sum(num - 1);
}

int main(void)
{
	int num;

	printf("정수를 입력하시오: ");
	scanf_s("%d", &num);

	printf("1부터 %d까지의 합 = %d", num, sum(num));

	return 0;
}