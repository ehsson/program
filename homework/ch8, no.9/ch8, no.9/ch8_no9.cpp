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
	srand(time(NULL));

	for (int t = 1; t <= 5; t++) {
		printf("%d ", b_rand());
	}

	return 0;
}