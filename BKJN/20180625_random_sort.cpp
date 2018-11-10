#include <stdio.h>
#include <stdlib.h>

#define MAX_ARR	100		//배열의 크기의 최대값 정의
#define MAX_NUM 1000		//랜덤 생성 숫자의 최대값 정의

#define swap(a, b) (a ^= b ^= a ^= b)

int sel[MAX_ARR];		//배열 최대값으로 배열 생성
int bub[MAX_ARR];
int seq[MAX_ARR];
int cnt[MAX_ARR];

void selection_sort(int start, int end)
{
	int min, pos;
	if (start > end) {
		swap(start, end);
	}

	for (int k = start; k <= end; k++) {
		min = MAX_NUM + 1;			//min 값을 랜덤 숫자의 최대값 + 1 로 초기화
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
	int counter[MAX_NUM] = { 0 };				//랜덤 값의 최대값으로 배열 생성
	int rm_num = 0;

	for (int k = start; k <= end; k++) {
		counter[cnt[k]]++;
	}

	for (int k = 0; k < MAX_NUM; k++) {			//랜덤 값의 최대값까지 for 루프
		for (int i = 0; i < counter[k]; i++) {
			cnt[rm_num] = k;
			rm_num++;
		}
	}
}

int main(void)
{
	srand(1);

	for (int k = 0; k < MAX_ARR; k ++) {				//배열의 크기의 최대값까지 for 루프
		sel[k] = bub[k] = seq[k] = cnt[k] = rand() % MAX_NUM;	//100을 MAX_NUM 으로 수정
	}

	selection_sort(0, sizeof(sel)/sizeof(int) - 1;			//99를 "sizeof(sel)/sizeof(int) - 1" 로 수정
	bubble_sort(0, sizeof(bub)/sizeof(int) - 1);
	sequential_sort(0, sizeof(seq)/sizeof(int) - 1);
	counter_sort(0, sizeof(cnt)/sizeof(int) - 1);

	return 0;
}
