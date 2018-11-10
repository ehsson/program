#include <stdio.h>

#define MAX 100000
#define CNT 1000

int arr[CNT] = { 0 };

int rot2(int r_cnt, int se)
{
	int chk = 0;
	
	for (int r1 = 0; r1 < r_cnt; r1++) {
		for (int r2 = r1; r2 < r_cnt; r2++) {
			if (arr[r1] + arr[r2] > se) break;
			if (arr[r1] + arr[r2] == se) {
				printf("%d -> %d  %d %d\n", se, 2, arr[r1], arr[r2]);
				chk = 1;
				break;
			}
		}
		if (chk == 1) break;
	}

	return chk;
}

int rot3(int r_cnt, int se)
{
	int chk = 0;

	for (int r1 = 0; r1 < r_cnt; r1++) {
		for (int r2 = 0; r2 < r_cnt; r2++) {
			for (int r3 = r2; r3 < r_cnt; r3++) {
				if (arr[r1] + arr[r2] + arr[r3] > se) break;
				if (arr[r1] + arr[r2] + arr[r3] == se) {
					printf("%d -> %d  %d %d %d\n", se, 3, arr[r1], arr[r2], arr[r3]);
					chk = 1;
					break;
				}
			}
			if (chk == 1) break;
		}
		if (chk == 1) break;
	}

	return chk;
}

int rotate(int num)
{
	int temp, na, st, chk = 0;

	temp = 0;
	st = num;
	while (num > 0) {
		na = (int)(num % 10);
		num = (int)(num / 10);
		temp = (temp * 10) + na;
	}
	if (temp == st) chk = 1;

	return chk;
}

int search(int num, int end)
{
	int chk = -1;

	for (int a = 0; a < end; a++) {
		if (arr[a] == num) {
			chk = a;
			break;
		}
	}

	return chk;
}

int main(void)
{
	int r_cnt = 0, se;

	for (int k = 1; k < MAX; k++) {
		if (search(k, r_cnt) == -1 && rotate(k)) {
			arr[r_cnt] = k;
			r_cnt++;
		}
	}

	for (int se = 1; se < CNT; se++) {
		if (rotate(se)) {
			printf("%d -> %d  %d\n", se, 1, se);
		}
		else {
			if (rot2(r_cnt, se) == 0) {
				if (rot3(r_cnt, se) == 0) {
					printf("%d -> %d\n", se, 0);
				}
			}
		}
	}

	return 0;
}