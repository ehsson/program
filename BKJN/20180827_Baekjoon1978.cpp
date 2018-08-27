#include <stdio.h>

int sosoo(int num)
{
	int chk = 1;

	if (num == 1) return 0;

	for (int k = 2; k <= (int)(num / 2); k++) {
		if (num % k == 0) {
			chk = 0;
			break;
		}

	}

	return chk;
}

int main(void)
{
	int N, cnt = 0;
	int arr[100] = { 0 };

	scanf_s("%d", &N);

	for (int t = 0; t < N; t++) {
		scanf_s("%d", &arr[t]);
	}

	for (int k = 0; k < N; k++) {
		if (sosoo(arr[k]) == 1) {
			cnt++;
		}
	}

	printf("%d\n", cnt);

	return 0;
}