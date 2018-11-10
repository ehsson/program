#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int max = 0, pos;
	int cnt[10] = { 0 };
	int arr[100][10] = { 0 };

	srand(time(NULL));

	for (int k = 0; k < 100; k++) {
		for (int i = 0; i < 10; i++) {
			arr[k][i] = rand() % 10;
			cnt[arr[k][i]]++;
		}
	}


	for (int s = 0; s < 10; s++) {
		if (max < cnt[s]) {
			max = cnt[s];
			pos = s;
		}
	}

	printf("가장 많이 나온 수 %d", pos);

	return 0;
}