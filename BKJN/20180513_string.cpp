#include <stdio.h>

int main(void)
{
	char arr[501];

	printf("���� 10���� ���ϸ� �Է��ϼ���.\n");
	scanf_s("%s", arr, 10);

	printf("�Է��� �����ڸ� ��� �ҹ��ڷ� �ٲ���ϴ�.\n");

	for (int k = 0; k < 501; k++) 
	{
		if (arr[k] == 0) break;

		if ( arr[k] >= 'A' && arr[k] <= 'Z')
		{
			arr[k] = arr[k] + ('a' - 'A');
		}

	}

	printf("%s\n", arr);

	return 0;
}