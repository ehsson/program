#include <stdio.h>

int main(void)
{
	char arr[101] = { 0 };
	int alp[26];
	int N, t, cnt = 0, chk = 1;

	scanf_s("%d", &N);

	for (int k = 0; k < N; k++) {

		//initialize
		for (int a = 0; a < 26; a++)
			alp[a] = -1;
		t = 0;
		chk = 1;

		scanf_s("%s", arr, 101);

		while (arr[t] != NULL) {

			if (alp[arr[t] - 'a'] == -1 || alp[arr[t] - 'a'] == t - 1) {
				alp[arr[t] - 'a'] = t;
			}
			else {
				chk = 0;
				break;
			}
			t++;
		}
		if (chk == 1) {
			cnt++;
		}
	}

	printf("%d", cnt);

	return 0;
}