#include <stdio.h>

int main(void)
{
	int arr[26] = { 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10};
	char in[16] = { 0 };
	int k = 0, sum = 0;

	scanf_s("%s", in, 16);

	while (in[k] != NULL) {
		sum += arr[in[k] - 'A'];
		k++;
	}

	printf("%d", sum);

	return 0;
}