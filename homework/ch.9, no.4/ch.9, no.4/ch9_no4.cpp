#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_random()
{
	static int cnt = 0;

	if (cnt != 0) {
		printf("%d\n", rand());
	}

	cnt++;

	return cnt;
}

int main(void)
{
	if (get_random() == 1) {
		printf("초기화 실행\n");
		srand(time(NULL));
	}

	for (int k = 0; k < 3; k++) {	
		get_random();
	}

	return 0;
}