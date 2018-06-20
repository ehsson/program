#include <stdio.h>

#define swap(a, b) (a ^= b ^= a ^= b)
int num[10] = { 0 };
/*
int euclid(void)
{
	int x, y, z, temp = 1;

	scanf_s("%d %d", &x, &y);

	if (x < y) {
		z = x;
		x = y;
		y = z;
	}

	while (temp != 0) {
		temp = x % y;
		x = y;
		y = temp;
	}
	printf("최대공약수는 %d", x);

	return 0; 
}*/

void selection_sorting (int start, int end)
{
	int pos, min;

	if (start > end) {
		swap(start, end);
	}
	
	for (int k = start; k <= end; k++) {
		min = 100000;
		for (int i = k; i <= end; i++) {
			if (min > num[i]) {
				min = num[i];
				pos = i;
			}
		}
		num[pos] = num[k];
		num[k] = min;
	}
}

void bubble_sorting(int start, int end)
{
	if (start > end) {
		swap(start, end);
	}

	for (int k = end; k >= start; k--) {
		for (int i = start; i < k; i++) {
			if (num[i] > num[i + 1]) {
				swap(num[i], num[i + 1]);
			}
		}
	}
}

void counter_sorting(int start, int end)
{
	int counter[10000];
	int rm_num = 0;
	int cnt_num[100];

	for (int k = start; k <= end; k++) {
		counter[cnt_num[k]]++;
	}

	for (int k = 0; k <= 10000; k++) {
		for (int i = 0; i < counter[k]; i++) {
			cnt_num[rm_num] = k;
			rm_num++;
		}
	}
}

int main(void)
{
	
	for (int k = 0; k <= 9; k++) {
		scanf_s("%d", &num[k]);
	}

	bubble_sorting(0, 9);
	
	return 0;
}

