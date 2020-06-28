// 풍선 터트려서 점수 얻기 게임

#include <stdio.h>

int balloon[7][3] = { 0 };

void init() {

	balloon[0][1] = -1;

	for (int i = 1; i < 7; i++)
		balloon[i][1] = i - 1;

	for (int i = 0; i < 6; i++)
		balloon[i][2] = i + 1;

	balloon[6][2] = -1;
}

int shoot(int num) {

	int temp = balloon[ balloon[num][1] ][0] + balloon[ balloon[num][2] ][0];

	balloon[ balloon[num][1] ][2] = balloon[num][2];
	balloon[ balloon[num][2] ][1] = balloon[num][1];

	balloon[num][1] = balloon[num][2] = -1;

	return temp;
}

int get_point(int shoot_order[]) {

	int point = 0;

	for (int i = 1; i <= 5; i++)
		point += shoot( shoot_order[i] );

	return point;
}

int main(void)
{
	int max_point = 0;
	int shoot[6] = { 0 };

	for (int i = 1; i <=5; i++)
		scanf("%d", &balloon[i][0]);


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

