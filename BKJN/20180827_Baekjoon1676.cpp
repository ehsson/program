#include <stdio.h>

int main()
{
	int iFac, iFacCount = 0;
	scanf_s("%d", &iFac);

	for (int i = 5; i <= iFac; i *= 5) {
		iFacCount += iFac / i;
		i = i;
	}

	printf("%d\n", iFacCount);

	return 0;
}
