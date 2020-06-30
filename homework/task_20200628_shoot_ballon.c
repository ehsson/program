// 풍선 터트려서 점수 얻기 게임

#include <stdio.h>

typedef struct balloon {
	int point;
	int left;
	int right;
} balloon_s;

balloon_s balloon[7];

void init() {

	balloon[0].left = -1;

	for (int i = 1; i < 7; i++)
		balloon[i].left = i - 1;

	for (int i = 0; i < 6; i++)
		balloon[i].right = i + 1;

	balloon[6].right = -1;
}

int shoot(int num) {

	int temp = balloon[ balloon[num].left ].point + balloon[ balloon[num].right ].point;

	balloon[ balloon[num].left ].right = balloon[num].right;
	balloon[ balloon[num].right ].left = balloon[num].left;

	balloon[num].left = balloon[num].right = -1;

	return temp;
}

int get_point(int shoot_order[]) {

	int point = 0;

	for (int i = 1; i <= 5; i++)
		point += shoot(shoot_order[i]);

	return point;
}

int main(void)
{
	int max_point = 0;
	int shoot[6] = { 0 };

	for (int i = 1; i <= 5; i++)
		scanf_s("%d", &balloon[i].point);


	for (shoot[1] = 1; shoot[1] <= 5; shoot[1]++) {
		for (shoot[2] = 1; shoot[2] <= 5; shoot[2]++) {
			if (shoot[2] == shoot[1])
				continue;

			for (shoot[3] = 1; shoot[3] <= 5; shoot[3]++) {
				if (shoot[3] == shoot[1] || shoot[3] == shoot[2])
					continue;

				for (shoot[4] = 1; shoot[4] <= 5; shoot[4]++) {
					if (shoot[4] == shoot[1] || shoot[4] == shoot[2] || shoot[4] == shoot[3])
						continue;

					for (shoot[5] = 1; shoot[5] <= 5; shoot[5]++) {
						if (shoot[5] == shoot[1] || shoot[5] == shoot[2] ||
							shoot[5] == shoot[3] || shoot[5] == shoot[4])
							continue;

						init();

						int point = get_point(shoot);

						if (point > max_point)
							max_point = point;
					}

				}

			}

		}
	}

	printf("%d\n", max_point);

	return 0;
}


