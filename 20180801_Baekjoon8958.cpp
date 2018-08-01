#include <stdio.h>

int main(void)
{
	int TC, score, cnt, t;
	char arr[81] = { 0 };

	scanf_s("%d", &TC);

	for (int k = 0; k < TC; k++) {
		for (int i = 0; i < 81; i++) arr[i] = 0;
		score = 0;
		cnt = 0;
		t = 0;
		scanf_s("%s", arr, 81);
		while (arr[t] != NULL) {
			if (arr[t] == 'O') {
				cnt++;
				score += cnt;
			}
			else if (arr[t] == 'X') {
				cnt = 0;
			}
			t++;
		}
		printf("%d\n", score);
	}

	return 0;
}