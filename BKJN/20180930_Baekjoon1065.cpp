#include <stdio.h>

int arith(int num)
{
	int x, y, z, cnt = 0;

	x = (int)(num / 100);
	y = (int)((num % 100) / 10);
	z = num % 10;

	while (num != 0) {
		num /= 10;
		cnt++;
	}

	if (cnt == 3) {
		if (x - y != y - z) {
			return 0;
		}
	}

	if (cnt == 4) {
		return 0;
	}

	return 1;
}

int main(void)
{
	int N, cnt = 0;

	scanf_s("%d", &N);

	for (int k = 1; k <= N; k++) {
		if (arith(k)) {
			cnt++;
		}
 	}

	printf("%d", cnt);

	return 0;
}