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
	int in;
	char yn = 'y';

	srand(time(NULL));

	while (yn == 'y') {

		printf("�ո� �Ǵ� �޸�(1 or 0): ");
		scanf_s("%d", &in);

		for (;;) {					//0 �Ǵ� 1 ���� �ڿ� ���ӵǴ� ���� �Ǵ� ���� ���ڰ� ������ ���� �����ϴ� ����
			scanf_s("%c", &yn);
			if (yn == '\n')
				break;
		}


		if (b_rand() == in) {
			printf("�¾ҽ��ϴ�.\n");
		}
		else {
			printf("Ʋ�Ƚ��ϴ�.\n");
		}

		printf("����Ͻðڽ��ϱ�?(y �Ǵ� n): ");

		for (;;) {					//y �Ǵ� n ���ڰ� �ԷµǱ� ���� �ٸ� ���ڰ� �ԷµǾ� �ִ� ���, ������
			scanf_s("%c", &yn);
			if (yn == 'y' || yn == 'n')
				break;
		}

	}

	return 0;
}