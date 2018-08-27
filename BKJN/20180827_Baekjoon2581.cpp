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

		if (cnt == 0 && chk == 1) {
			temp = k;
			cnt++;
		}

		if (chk == 1) {
			sum += k;
		}
	}

	if (cnt == 0) {
		printf("-1");
		return;
	}

	printf("%d\n", sum);
	printf("%d\n", temp);
}

int main(void)
{
	int M, N, temp;

	scanf_s("%d %d", &M, &N);

	if (M > N) {
		temp = M;
		M = N;
		N = temp;
	}

	sosoo(M, N);

	return 0;
}