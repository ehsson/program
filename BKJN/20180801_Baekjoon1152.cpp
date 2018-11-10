#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int k = 0, cnt = 0;
	char arr[1000000] = { 0 }, temp;

	FILE *pf;
	freopen_s(&pf, "input.txt", "r", stdin);

	while (1) {
		temp = getchar();
		if (temp == '\n' || temp == EOF) {
			arr[k] = 0;
			break;
		} else {
			arr[k] = temp;
		}
		k++;
	}

	for (int t = 0; t < k; t++) {
		if ( 'A' <= arr[t] && arr[t] <= 'z') {
			if (t == 0)
				cnt++;
			else {
				if (arr[t - 1] == ' ')
					cnt++;
			}
		}
	}

	printf("%d\n", cnt);
	return 0;
}