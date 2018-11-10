#include <stdio.h>

long long factorial(int t)
{
	long long fac = 1;

	for (int k = 1; k <= t; k++) {
		fac *= k;
	}

	return fac;
}

int main(void)
{
	int num;
	double sol = 0;

	printf("������ ����ұ��?: ");
	scanf_s("%d", &num);

	for (int t = 1; t <= num; t++) {
		sol += (1.0 / factorial(t));
	}

	printf("���Ϸ��� ���� %lf�Դϴ�.", 1.0 + sol);

	return 0;
}