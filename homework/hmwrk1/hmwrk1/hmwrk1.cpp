#include <stdio.h>

int even(int n)
{
	if (n < 0) {
		n = -n;
	}

	if (n % 2 == 1) {
		return 0;
	}
	else {
		return 1;
	}
}

int absolute(int n)
{
	if (n < 0) {
		n = -n;
	}

	return n;
}

int sign(int n)
{
	if (n < 0) {
		return -1;
	}
	else if (n > 0){
		return 1;
	}
	else {
		return 0;
	}
}

int main(void)
{
	int n;

	printf("정수를 입력하시오: ");
	scanf_s("%d", &n);

	if (even(n) == 1) {
		printf("even()의 결과: 짝수");
	}
	else {
		printf("even()의 결과: 홀수");
	}

	printf("\n");

	printf("absolute()의 결과: %d", absolute(n));

	printf("\n");
	
	if (sign(n) == 1) {
		printf("sign()의 결과: 양수");
	}
	else if (sign(n) == 0) {
		printf("sign()의 결과: 0");
	}
	else {
		printf("sign()의 결과: 음수");
	}

	return 0;
}