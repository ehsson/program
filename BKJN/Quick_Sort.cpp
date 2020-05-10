#include <stdio.h>

int arr1[15] = { 14, 2, 4, 1, 7, 6, 5, 10, 19, 13, 11, 17, 20, 16, 18 };

void swap(int arr[], int idx1, int idx2)
{
	int temp;

	temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int partition(int arr[], int left, int right)
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
			swap(arr, low, high);
	}

	swap(arr, left, high);

	return high;
}

void QuickSort(int arr[], int left, int right)
{
	if (left > right) {
		return;
	}

	int pivot;

	pivot = partition(arr, left, right);

	QuickSort(arr, left, pivot - 1);
	QuickSort(arr, pivot + 1, right);

}

int main(void)
{

	int len, i;

	len = sizeof(arr1) / sizeof(int);

	QuickSort(arr1, 0, sizeof(arr1) / sizeof(int) - 1);

	for (int i = 0; i < len; i++) {
		printf("%d ", arr1[i]);
	}

	printf("\n");

	return 0;
}
