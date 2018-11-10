#include <stdio.h>

void is_prime(int num)
{
	int chk = 1;

	for (int t = 2; t <= (int)(num / 2); t++) {
		if (num % t == 0) {
			chk = 0;
			return;
		}
	}

	if (chk == 1) {
		printf("%d ", num);
	}
}

int main(void)
{
	for (int t = 2; t <= 100; t++) {
		is_prime(t);
	}

	return 0;
}