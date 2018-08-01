#include <stdio.h>

int main(void)
{
	int arr[8] = { 0 };
	int temp = 7;
	
	for (int k = 0; k < 8; k++) {
		scanf_s("%d", &arr[k]);
	}

	for (int t = 0; t < 7; t++) {
		if (arr[t] < arr[t + 1]) {
			temp++;
		}
		else {
			temp--;
		}
	}

	if (temp == 14) {
		printf("ascending");
	}
	else if (temp == 0) {
		printf("descending");
	}
	else {
		printf("mixed");
	}

	return 0;
}