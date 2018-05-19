#include <stdio.h>

int num[10];

int sort(int start, int end)
{
	int temp, cnt = 0;
	if (start < end) {
		temp = start;
		start = end;
		end = temp;
	}

	for (int k = end; k > start; k--) {
		for (int i = start; i < k; i++) {
			if (num[i] > num[k + 1]) {
				temp = num[i];
				num[i] = num[i + 1];
				num[i + 1] = temp;
				cnt++;
			}
		}
	}
	return cnt;
}

int chk_sorted(int check, int start, int end)
{
	int temp = 1;
	if (start > end) {
		temp = start;
		start = end;
		end = temp;
	}
	switch (check) {
	case 1:			
		for (int i = start; i < end; i++) {
			if (num[i] > num[i + 1]) {
				temp = 0;
				break;
			}
		}
		break;
	case 2:				
		for (int i = start; i < end; i++) {
			if (num[i] < num[i + 1]) {
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
		temp1 = sort(0, 9);
	}
	printf("%d\n", temp1);
	return 0;
}