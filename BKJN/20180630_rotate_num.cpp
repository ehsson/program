#include <stdio.h>

int arr[10000] = { 0 };
int temp[10] = { 0 };

void length(int num)
{
	int aa, len = 1;
	while (1) {
		aa = num % 10;
		num = (int)(num / 10);
		temp[len] = aa;
		if (num == 0) break;
		len++;
	}
	temp[0] = len;
}

int main(void)
{
	int chk, cnt = 0;
	for (int a = 0; a <= 10000; a++) {
		length(a);
		chk = 0;
		for (int b = 0; b <= (int)(temp[0] / 2); b++) {
			if (temp[b + 1] != temp[temp[0] - b]) {
				chk = -1;
				break;
			}
		}
		if (chk == 0) {
			arr[cnt] = a;
			cnt++;
		}
	}
	return 0;
}