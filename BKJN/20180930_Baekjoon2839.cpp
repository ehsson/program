#include <stdio.h>

int main(void)
{
	int N, chk = 0, sol;

	scanf_s("%d", &N);

	for (int k = (int)(N / 5); k >= 0; k--) {
		sol = N - (5 * k);
		if (sol % 3 == 0) {
			printf("%d", k + (int)(sol / 3));
			chk = 1;
			break;
		}
	}

	if (chk == 0) printf("%d", -1);

	return 0;
}