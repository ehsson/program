#include <stdio.h>



int func(int num)
{
	int mok, na, temp;

	temp = num;

	while (num != 0) {
		na = (int)(num % 10);
		num = (int)(num / 10);
		temp += na;
	}

	return temp;
}

int main(void)
{
	int arr[10001] = { 0 };
	int temp;

	for (int k = 1; k <= 10000; k++) {
		temp = func(k);
		if (temp < 10001 )
			arr[ temp ] = 1;
	}

	for (int k = 1; k <= 10000; k++) {
		if (arr[k] == 0) {
			printf("%d\n", k);
		}
	}

	return 0;
}