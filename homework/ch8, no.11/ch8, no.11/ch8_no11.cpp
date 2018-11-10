#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double f_rand()
{
	double temp;

	temp = rand() / 1000000.0;

	return temp;
}

int main(void)
{
	srand(time(NULL));

	for (int t = 1; t <= 5; t++) {
		printf("%lf ", f_rand());
	}

	return 0;
}