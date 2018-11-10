#include <stdio.h>

int arr[3][5] = {
	{ 12, 56, 32, 16, 98 },
{ 99, 56, 34, 41, 3 },
{ 65, 3, 87, 78, 21 }
};

void row_sum(int row_num)
{
	int temp = 0;

	for (int a = 0; a < 5; a++) {
		temp += arr[row_num][a];
	}

	printf("%d행의 합계 : %d\n", row_num, temp);
}

void column_sum(int col_num)
{
	int temp = 0;

	for (int a = 0; a < 3; a++) {
		temp += arr[a][col_num];
	}

	printf("%d열의 합계 : %d\n", col_num, temp);
}

int main(void)
{
	row_sum(0);
	row_sum(1);
	row_sum(2);

	column_sum(0);
	column_sum(1);
	column_sum(2);
	column_sum(3);
	column_sum(4);

	return 0;
}