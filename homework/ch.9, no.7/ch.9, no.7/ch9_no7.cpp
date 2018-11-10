#include <stdio.h>

void show_digit(int num)
{
	int temp;

	if (num / 10 == 0) {
		printf("%d ", num);
		return;
	}

	show_digit(num / 10);

	printf("%d ", num % 10);
}

int main(void)
{
	int num;

	printf("������ �Է��Ͻʽÿ�: ");
	scanf_s("%d", &num);

	show_digit(num);

	return 0;
}