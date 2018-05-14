#include <stdio.h>

int main(void)
{
	int num[10];
	int sort[10];
	int min = 100000;
	int min_pos = -1;
	for (int k = 0; k <= 9; k++)
		scanf_s("%d", &num[k]);
/*
	for (int i = 0; i <= 9; i++) {
		for (int p = 0; p <= 9; p++) {
			if (num[p] < min) {
				min = num[p];
				min_pos = p;
			}
		}
		sort[i] = min;
		num[min_pos] = min = 100000;
	}


	for (int i = 0; i < 9; i++) {
		for (int p = i; p <= 9; p++) {
			if (num[p] < min) {
				min = num[p];
				min_pos = p;
			}
		}
		num[min_pos] = num[i];
		num[i] = min;

		min = 100000;
	}
*/
	int temp;
	for (int i = 9; i > 0; i--) {
		for (int p = 0; p < i; p++) {
			if (num[p] > num[p + 1]) {
				temp = num[p];
				num[p] = num[p + 1];
				num[p + 1] = temp;

			}
		}
	}
	return 0;
}