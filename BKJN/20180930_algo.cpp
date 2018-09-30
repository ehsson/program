#include <stdio.h>
#define VALUE 10

typedef struct Element {
	int vlu;
	int chk;
} ELEMENT;

ELEMENT arr[] = { { 6, 0 },{ 2, 0 },{ 8, 0 },{ 9, 0 },{ 4, 0 },{ 7, 0 },{ 1, 0 } };

int len;

void DFS(int depth, int sum)
{
	int temp;

	if (sum > VALUE) {
		return;
	}

	if (depth >= len) {
		if (sum < VALUE) {

			temp = 0;

			for (int i = 0; i < len; i++) {
				if (arr[i].chk == 1) {

					if (temp != 0) {
						printf(" ");
					}

					temp = 1;

					printf("%d", arr[i].vlu);
				}
			}

			printf("\n");
		}

		return;
	}

	arr[depth].chk = 1;
	DFS(depth + 1, sum + arr[depth].vlu);

	arr[depth].chk = 0;
	DFS(depth + 1, sum);
}

int main(void)
{
	len = sizeof(arr) / sizeof(ELEMENT);

	DFS(0, 0);

	return 0;
}