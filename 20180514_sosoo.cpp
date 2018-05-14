#include <stdio.h>

int main(void)
{
	int a, b, c = 1, temp;
	for (int a = 2; a <= 100; a++)
	{
		temp = 0;
		for (int b = 2; b <= (int)(a / 2); b++)
		{
			if (a % b == 0)
			{
				temp = 1;
				break;
			}
			
		}
		if (temp == 0 && c <= 10)
		{
			printf("%d\n", a);
			c++;
		}
	}




	return 0;
}