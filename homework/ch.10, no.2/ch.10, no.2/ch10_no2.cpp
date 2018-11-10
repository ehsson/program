#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int min, pos = 0;
	int arr[10] = { 0 };

	srand(time(NULL));

	for (int k = 0; k < 10; k++) {
		arr[k] = rand();
	}

	for (int t = 0; t < 9; t++) {
		min = arr[t];
		for (int i = t; i < 10; i++) {
			if (min > arr[i]) {
				min = arr[i];
				pos = i;
			}
		}

		arr[pos] = arr[t];
		arr[t] = min;
	}

	printf("ÃÖ´ñ°ªÀº %d\n", arr[9]);
	printf("ÃÖ¼Ú°ªÀº %d\n", arr[0]);


	return 0;
}