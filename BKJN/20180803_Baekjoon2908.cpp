#include <stdio.h>

int rotate(int num)
{
	int temp = 0, na;

	while (num != 0) {
		na = (int)(num % 10);
		num = (int)(num / 10);
		temp = (temp * 10) + na;
	}

	return temp;
}

int main(void)
{
	int A, B;

	scanf_s("%d%d", &A, &B);

	if (rotate(A) > rotate(B)) {
		printf("%d", rotate(A));
	}
	else {
		printf("%d", rotate(B));
	}

	return 0;
}