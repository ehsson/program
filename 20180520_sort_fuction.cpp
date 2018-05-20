#include <stdio.h>

int num[10];

int sequence_sort(int delimiter, int start, int end) {
	int cnt = 0;

	return cnt;
}

int bubble_sort(int delimiter, int start, int end)
{
	int temp, cnt = 0;

	if (start > end) {
		temp = start;
		start = end;
		end = temp;
	}

	switch (delimiter) {
	case 1:
		for (int k = end; k > start; k--) {
			for (int i = start; i < k; i++) {
				if (num[i] > num[i + 1]) {
					temp = start;
					start = end;
					end = temp;
					cnt++;
				}
			}
		}
		break;
	case 2:
		for (int k = end; k > start; k--) {
			for (int i = start; i < k; i++) {
				if (num[i] < num[i + 1]) {
					temp = start;
					start = end;
					end = temp;
					cnt++;
				}
			}
		}

		break;
	default:
		cnt = -1;
	}

	return cnt;
}

int chk_sorted(int delimiter, int start, int end)
{
	int temp = 1;

	switch (delimiter) {
	case 1:
		for (int k = start; k < end; k++) {
			if (num[k] > num[k + 1]) {
				temp = 0;
				break;
			}
		}
		break;
	case 2:
		for (int k = start; k < end; k++) {
			if (num[k] < num[k + 1]) {
				temp = 0;
				break;
			}
		}
		break;
	default:
		temp = 0;
		break;
	}

	return temp;
}

int main(void)
{
	int temp, temp1 = 0;

	for (int k = 0; k <= 9; k++)
		scanf_s("%d", &num[k]);

	temp = chk_sorted(1, 3, 6);

	if (temp == 0) {
		temp1 = bubble_sort(1, 0, 9);
	}
	printf("%d\n", temp1);
	return 0;
}
