#include <stdio.h>

int gcd(int A, int B)
{
	int temp;

	if (A > B) {
		temp = A;
		A = B;
		B = temp;
	}

	while (1) {
		temp = B % A;
		if (temp == 0) break;
		B = A;
		A = temp;
	}

	return A;
}

int main(void)
{
	int A, B, result;

		scanf_s("%d %d", &A, &B);

		result = A * B / gcd(A, B);

		printf("%d\n", gcd(A, B));
		printf("%d\n", result);

	return 0;
}