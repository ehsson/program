#include <stdio.h>

void sosoo(int M, int N)
{
	int chk, cnt = 0, sum = 0, temp;

	for (int k = M; k <= N; k++) {

		if (k == 1) {
			continue;
		}

		chk = 1;

		for (int i = 2; i <= (int)(k / 2); i++) {

			if (k % i == 0) {
				chk = 0;
				break;
			}
		}

		if (chk == 1) {
			printf("%d\n", k);
		}
	}
}

int main(void)
{
	int M, N;

	scanf_s("%d %d", &M, &N);

	sosoo(M, N);

	return 0;
}