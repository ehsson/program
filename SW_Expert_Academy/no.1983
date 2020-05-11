#include <stdio.h>

int arr[101] = { 0 };
char * grade[] = {"D0", "C-", "C0", "C+", "B-", "B0", "B+", "A-", "A0", "A+"};

void swap(int idx1, int idx2)
{
	int temp;

	temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int partition(int left, int right)
{
	int pivot, low, high;

	pivot = arr[left];
	low = left + 1;
	high = right;

	while (low <= high) {
		while (pivot >= arr[low])
			low++;

		while (pivot <= arr[high] && left < high)
			high--;

		if (low < high)
			swap(low, high);
	}

	swap(left, high);

	return high;
}

void QuickSort(int left, int right)
{
	if (left > right) {
		return;
	}

	int pivot;

	pivot = partition(left, right);

	QuickSort(left, pivot - 1);
	QuickSort(pivot + 1, right);

}

int main(void)
{
	int T, N, K, mid, fin, task, K_val, pos;
	double per;
	
	scanf("%d", &T);
	
	for(int t = 0; t < T; t++) {
		scanf("%d %d", &N, &K);
		
		for(int n = 1; n <= N; n++) {
			scanf("%d %d %d", &mid, &fin, &task);
			
			arr[n] = mid * 35 + fin * 45 + task * 20;
			
			if(n == K)
				K_val = arr[n];
		}
		
		QuickSort(1, N);
		
		for(int i = 0; i < N; i++) {
			if(K_val == arr[i]) {
				pos = i;
				break;
			}
		}
		
		per = (double)pos * 100.0 / (double)N;
		
		if((int)per % 10 == 0) {
			per = per / 10.0 - 1.0;
		}
		
		printf("#%d %s\n", t + 1, grade[(int)per]);
	}
	
	return 0;
}
