#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void get_dice_face(int num)
{
	static int cnt = 0;
	static int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;

	switch (num) {
	case 1:
		a++;
		break;
	case 2:
		b++;
		break;
	case 3:
		c++;
		break;
	case 4:
		d++;
		break;
	case 5:
		e++;
		break;
	default:
		f++;
		break;
	}

	cnt++;

	if (cnt == 100) {
		printf("1->%d\n", a);
		printf("2->%d\n", b);
		printf("3->%d\n", c);
		printf("4->%d\n", d);
		printf("5->%d\n", e);
		printf("6->%d\n", f);
	}
}

int main(void)
{
	int num;

	srand(time(NULL));

	for (int k = 0; k < 100; k++) {
		num = rand() % 6 + 1;
		get_dice_face(num);
	}

	return 0;
}