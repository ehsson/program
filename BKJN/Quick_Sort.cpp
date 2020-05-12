#include <stdio.h>

int arr[101] = { 0 };
char * grade[] = {"D0", "C-", "C0", "C+", "B-", "B0", "B+", "A-", "A0", "A+"};

void QuickSort(int arr[], int start, int end, int order) {
	if (start >= end)
		return;

	int pivot = start;
	int low = start;
	int high = end;
	int temp;

	if (order == 0) {				//오름차순 정렬
		while (low < high) {
			// pivot 값 보다도 작거나 같은 수를 왼쪽 부터 찾기
			// 단 범위를 끝까지 넘어가면 안됨
			while (arr[low] <= arr[pivot] && low < end)
				low++;

			// pivot 값 보다도 작거나 같은 수를 왼쪽 부터 찾기
			while (arr[pivot] < arr[high])
				high++;

			// pivot 값보다 크고 작은 수의 위치를 바꿈
			if (low < high) {
				temp = arr[low];
				arr[low] = arr[high];
				arr[high] = temp;
			}
		}
	}
	else {						//내림차순 정렬
		while (low < high) {
			while (arr[low] >= arr[pivot] && low < end)
				low++;

			while (arr[pivot] > arr[high])
				high++;

			if (low < high) {
				temp = arr[low];
				arr[low] = arr[high];
				arr[high] = temp;
			}
		}
	}

	// pivot 값과 pivot 값 보다 큰 수의 위치를 바꿈
	temp = arr[pivot];
	arr[pivot] = arr[high];
	arr[high] = temp;

	QuickSort(arr, start, high - 1, order);
	QuickSort(arr, high + 1, end, order);
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
		
		QuickSort(arr, 1, N, 0);
		
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
