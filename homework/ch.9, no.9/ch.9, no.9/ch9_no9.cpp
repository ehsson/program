#include <stdio.h>

int show_digit(int num)
{
	if (num / 10 == 0) {
		return num;
	}

	return ((num % 10) + show_digit(num / 10));
}

int main(void)
{
	int num;

	printf("정수를 입력하십시오: ");
	scanf_s("%d", &num);

	printf("자리수의 합: %d", show_digit(num));

	return 0;
}