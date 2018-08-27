#include <stdio.h>

void sosoo(int n)
{
	int chk, cnt = 0, sum = 0, temp;

	for (int k = n + 1; k <= (2 * n); k++) {

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
			cnt++;
		}
	}

	printf("%d\n", cnt);
}

int main(void)
{
	int n = -1;

	while (n != 0) {
		scanf_s("%d", &n);
		sosoo(n);
	}

	return 0;
}