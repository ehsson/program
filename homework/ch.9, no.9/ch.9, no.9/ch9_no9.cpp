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

	printf("������ �Է��Ͻʽÿ�: ");
	scanf_s("%d", &num);

	printf("�ڸ����� ��: %d", show_digit(num));

	return 0;
}