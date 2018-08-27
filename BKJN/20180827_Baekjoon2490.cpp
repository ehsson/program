#include <stdio.h>

int main(void)
{
	int arr[4];
	int cnt ;

	for (int i = 0; i < 3; i++) {

		cnt = 0;

		for (int t = 0; t < 4; t++) {
			scanf_s("%d", &arr[t]);
		}

		for (int k = 0; k < 4; k++) {
			if (arr[k] == 0) cnt++;
		}

		switch (cnt) {
		case 0:
			printf("%c\n", 'E');
			break;
		case 1:
			printf("%c\n", 'A');
			break;
		case 2:
			printf("%c\n", 'B');
			break;
		case 3:
			printf("%c\n", 'C');
			break;
		case 4:
			printf("%c\n", 'D');
			break;
		}
	}

	return 0;
}