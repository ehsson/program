#include <stdio.h>

#define swap(a, b) (a ^= b ^= a ^= b)

int num[10] = { 0 };

void sequential_sorting(int start, int end)
{
	if (start > end) {
		swap(start, end);
	}
	for (int k = start; k <= end; k++) {
		for (int i = k + 1; i <= end; i++) {
			if (num[k] > num[i]) {
				swap(num[k], num[i]);
			}
		}
	}
}

int main(void)
{
	for (int k = 0; k <= 9; k++) 
		scanf_s("%d", &num[k]);

	sequential_sorting(0, 9);

	return 0;
}
