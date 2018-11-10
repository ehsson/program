#include <stdio.h>

int main(void)
{
	int TC, R, k = 0;
	char arr[21] = { 0 };

	FILE *pf;
	freopen_s(&pf, "input.txt", "r", stdin);

	scanf_s("%d", &TC);

	for (int t = 0; t < TC; t++) {
		scanf_s("%d", &R);
		scanf_s("%s", arr, 21);
		k = 0;

		while (arr[k] != NULL) {
			for (int i = 0; i < R; i++) {
				printf("%c", arr[k]);
			}
			k++;
		}
		printf("\n");
	}

	return 0;
}