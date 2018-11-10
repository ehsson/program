#include <stdio.h>

int num[10];

int bubble_sorting(int start, int end)
{
	int temp, cnt = 0;

	if (start > end) {
		temp = start;
		start = end;
		end = temp;
	}

	for (int k = end; k > start; k--) {
		for (int i = start; i < k; i++) {
			if (num[i] > num[i + 1]) {
				temp = num[i];
				num[i] = num[i + 1];
				num[i + 1] = temp;
				cnt++;
			}
		}
	}
	return cnt;
}


int main(void)
{
	for (int k = 0; k <= 9; k++) {
		scanf_s("%d", &num[k]);
	}
	bubble_sorting(4, 8);

	return 0;
}