#include <stdio.h>

int main(void)
{
	int N, cnt = 0, ten, one, temp, sto;

	scanf_s("%d", &N);

	sto = N;

	do {
		if (N / 10 == 0) {
			ten = 0;
			one = N;
		}
		else {
			one = N % 10;
			N /= 10;
			ten = N % 10;
		}

		temp = (one + ten) % 10;
		N = (one * 10) + temp;

		cnt++;
	} while (N != sto);

	printf("%d\n", cnt);

	return 0;
}