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

	printf("������ �Է��Ͻÿ�: ");
	scanf_s("%d", &num);

	printf("1���� %d������ �� = %d", num, sum(num));

	return 0;
}