#include <stdio.h>

int main(void)
{
	int x, y, z, w;
	printf("���� �ΰ��� �Է��Ͻÿ�.\n");
	scanf_s("%d %d", &x, &y);

	if (x < y) {
		z = x;
		x = y;
		y = z;
	}
	
	while (x % y != 0) {
		w = x % y;
		x = y;
		y = w;
	}
	printf("�� ���� �ּҰ������ %d�̴�.\n", w);
	return 0;
}