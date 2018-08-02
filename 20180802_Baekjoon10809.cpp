#include <stdio.h>

int str_len(char *arr, int len) {
	for (int i = 0; i < len; i++) {
		if (arr[i] == NULL)
			return i;
	}
	return -1;
}

int main(void)
{
	int alp[26] = { 0 };
	char arr[101] = { 0 };
	int k = 0, temp;


	for (int r = 0; r < 26; r++)
		alp[r] = -1;

	scanf_s("%s", arr, 101);

	k = str_len(arr, sizeof(arr) / sizeof(char));


	for (int i = k; k >= 0; k--) {
		alp[arr[k] - 'a'] = k;
	}

	for (int t = 0; t < 26; t++) {
		printf("%d", alp[t]);
	}

	return 0;
}