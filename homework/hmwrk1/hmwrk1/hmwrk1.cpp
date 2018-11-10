#include <stdio.h>

int even(int n)
{
	if (n < 0) {
		n = -n;
	}

	if (n % 2 == 1) {
		return 0;
	}
	else {
		return 1;
	}
}

int absolute(int n)
{
	if (n < 0) {
		n = -n;
	}

	return n;
}

int sign(int n)
{
	if (n < 0) {
		return -1;
	}
	else if (n > 0){
		return 1;
	}
	else {
		return 0;
	}
}

int main(void)
{
	int n;

	printf("������ �Է��Ͻÿ�: ");
	scanf_s("%d", &n);

	if (even(n) == 1) {
		printf("even()�� ���: ¦��");
	}
	else {
		printf("even()�� ���: Ȧ��");
	}

	printf("\n");

	printf("absolute()�� ���: %d", absolute(n));

	printf("\n");
	
	if (sign(n) == 1) {
		printf("sign()�� ���: ���");
	}
	else if (sign(n) == 0) {
		printf("sign()�� ���: 0");
	}
	else {
		printf("sign()�� ���: ����");
	}

	return 0;
}