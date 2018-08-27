#include <stdio.h>

int func(int num)
{
	int na, temp, chk = 0, mok;
	for (int t = 1; t <= 10000; t++) {
		if (t >= num) break;

		temp = t;
		mok = t;
		while (mok != 0) {
			na = (int)(mok % 10);
			mok = (int)(mok / 10);
			temp += na;
		}

		if (temp == num) {
			chk = 1;
			break;
		}
	}

	return chk;
}

int main(void)
{
	for (int k = 1; k <= 10000; k++) {
		if (func(k) == 0) printf("%d\n", k);
	}
	return 0;
}