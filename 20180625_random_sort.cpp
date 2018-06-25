#include <stdio.h>
#include <stdlib.h>

#define swap(a, b) (a ^= b ^= a ^= b)

int sel[100];
int bub[100];
int seq[100];
int cnt[100];

void selection_sort(int start, int end)
{
	int min, pos;
	if (start > end) {
		swap(start, end);
	}

	for (int k = start; k <= end; k++) {
		min = 1000000;
		for (int i = k; i <= end; i++) {
			if (min > sel[i]) {
				min = sel[i];
				pos = i;
			}
		}
		sel[pos] = sel[k];
		sel[k] = min;
	}
}

void bubble_sort(int start, int end)
{
	if (start > end) {
		swap(start, end);
	}

	for (int k = end; k >= start; k--) {
		for (int i = start; i <= k; i++) {
			if (bub[i] > bub[i + 1]) {
				swap(bub[i], bub[i + 1]);
			}
		}
	}
}

void sequential_sort(int start, int end)
{
	if (start > end) {
		swap(start, end);
	}

	for (int k = start; k <= end; k++) {
		for (int i = k; i <= end; i++) {
			if (seq[k] > seq[i]) {
				swap(seq[k], seq[i]);
			}
		}
	}
}

void counter_sort(int start, int end)
{
	int counter[100] = { 0 };
	int rm_num = 0;

	for (int k = start; k <= end; k++) {
		counter[cnt[k]]++;
	}

	for (int k = 0; k < 100; k++) {
		for (int i = 0; i < counter[k]; i++) {
			cnt[rm_num] = k;
			rm_num++;
		}
	}
}

int main(void)
{
	srand(1);

	for (int k = 0; k <= 99; k ++) {
		sel[k] = bub[k] = seq[k] = cnt[k] = rand() % 100;
	}

	selection_sort(0, 99);
	bubble_sort(0, 99);
	sequential_sort(0, 99);
	counter_sort(0, 99);

	return 0;
}