#include <stdio.h>

int num[10];

int bobble_sort(int delimiter, int start, int end)
{
	int temp;
	
	
	for (int i = 9; i > 0; i--) {
		for		
	}	

}

int chk_sorted(int delimiter, int start, int end)
{
	
	




}

int main(void)
{
	int temp, temp1 = 0;

	for (int k = 0; k <= 9; k++)
		scanf_s("%d", &num[k]);

	temp = chk_sorted(1, 3, 6);

	if (temp == 0) {
		temp1 = bobble_sort(0, 9);
	}
	printf("%d\n", temp1);
	return 0;
}
