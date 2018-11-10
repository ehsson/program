#include <stdio.h>

int main(void)
{
	char arr[1000001] = { 0 };
	int alp[26] = { 0 };
	int k = 0, bi, te = 0, st;

	scanf_s("%s", arr, 1000001);

	while (arr[k] != NULL) {
		if (arr[k] < 'a') {
			alp[arr[k] - 'A']++;
		}
		else {
			alp[arr[k] - 'a']++;
		}
		k++;
	}

	bi = 0;

	for (int t = 0; t < 26; t++) {
		if (alp[t] > bi) {
			bi = alp[t];
			st = t;
		}
	}

	for (int i = 0; i < 26; i++) {
		if (i == st) continue;
		if (bi == alp[i]) {
			printf("%c", '?');
			te = 1;
			break;
		}
	}

	if (te == 0) printf("%c", st + 'A');

	return 0;
}