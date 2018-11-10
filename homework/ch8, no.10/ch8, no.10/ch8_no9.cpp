#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int b_rand()
{
	int temp;

	temp = rand() % 2;
	return temp;
}

int main(void)
{
	int in;
	char yn = 'y';

	srand(time(NULL));

	while (yn == 'y') {

		printf("앞면 또는 뒷면(1 or 0): ");
		scanf_s("%d", &in);

		for (;;) {					//0 또는 1 숫자 뒤에 연속되는 공백 또는 숫자 글자가 들어오는 것을 삭제하는 로직
			scanf_s("%c", &yn);
			if (yn == '\n')
				break;
		}


		if (b_rand() == in) {
			printf("맞았습니다.\n");
		}
		else {
			printf("틀렸습니다.\n");
		}

		printf("계속하시겠습니까?(y 또는 n): ");

		for (;;) {					//y 또는 n 글자가 입력되기 전에 다른 글자가 입력되어 있는 경우, 삭제함
			scanf_s("%c", &yn);
			if (yn == 'y' || yn == 'n')
				break;
		}

	}

	return 0;
}