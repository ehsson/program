#include <stdio.h>

int map[100][100];
int coo[100][1000];
int temp[2][1000];
int result, map_x, map_y, pos, add;
int save_pos;					//아빠 추가

void DFS(int x, int y, int len)
{
	temp[0][pos] = x;
	temp[1][pos] = y;

	pos++;
	
	if (x < 0 || x >= map_x || y < 0 || y >= map_y) {
		pos--;
		return;
	}

	if (map[y][x] >= 10) {
		pos--;
		return;
	}

	if (len + map[y][x] + (map_x - 1 - x) + (map_y - 1 - y) > result) {
		pos--;
		return;
	}

	if (x == map_x - 1 && y == map_y - 1) {
		if (len + map[y][x] == result) {

			add += 2;

			for (int k = 0; k < pos; k++) {
				coo[add][k] = temp[0][k];
				coo[add + 1][k] = temp[1][k];
			}
		}

		if (len + map[y][x] < result) {
			add = 0;
			result = len + map[y][x];
			save_pos = pos;			//아빠 추가
			for (int i = 0; i < pos; i++) {
				coo[0][i] = temp[0][i];
				coo[1][i] = temp[1][i];
			}
		}
		pos--;						//아빠 추가
		return;
	}
	
	map[y][x] += 10;

	DFS(x, y + 1, len + (map[y][x] - 10));
	DFS(x + 1, y, len + (map[y][x] - 10));

	DFS(x, y - 1, len + (map[y][x] - 10));
	DFS(x - 1, y, len + (map[y][x] - 10));

	map[y][x] -= 10;

	pos--;							//아빠 추가
	return;
}

int main(void)
{
	int TC;

	FILE *pf;
	freopen_s(&pf, "input.txt", "r", stdin);

	scanf_s("%d", &TC);

	for (int t = 1; t <= TC; t++) {

		pos = 0;
		add = 0;

		scanf_s("%d %d", &map_x, &map_y);

		for (int y = 0; y < map_y; y++) {
			for (int x = 0; x < map_x; x++) {
				scanf_s("%d", &map[y][x]);
			}
		}
		result = map_x * map_y * 10;

		DFS(0, 0, 0);

		for (int i = 0; i < save_pos; i++) {
			printf("(%d, %d, %d)\n", coo[0][i], coo[1][i], map[coo[1][i]][coo[0][i]]);
		}
		printf("\n");

		if (add > 1) {
			for (int r = 2; r <= add; r += 2) {
				for (int e = 0; e < save_pos; e++) {
					printf("(%d, %d, %d)\n", coo[r][e], coo[r + 1][e], map[coo[r + 1][e]][coo[r][e]]);
				}
				printf("\n");
			}
		}

		printf("# %d case Min length = %d\n", t, result);
	}

	return 0;
}