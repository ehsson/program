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
	int A, B, result, N;

	scanf_s("%d", &N);
	for (int t = 0; t < N; t++) {
		scanf_s("%d %d", &A, &B);

		result = A * B / gcd(A, B);

		printf("%d\n", result);
	}

	return 0;
}