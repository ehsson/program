#include <stdio.h>
#include <malloc.h>

typedef struct Node_list {
	int x;
	int y;
	struct Node_list *prev;
	struct Node_list *next;
} NODE_LIST;
/*
typedef struct Save_path {
	int x;
	int y;
	int value;
} SAVE_PATH;
*/

NODE_LIST path;
//	SAVE_PATH *save_path;

int map[100][100];
int result, map_x, map_y;

/*
void delete_save_path()
{
	if (save_path == NULL) {
		return;
	}

	free(save_path);
}
*/
/*
void save_short_path()
{
	int temp = 0;

	NODE_LIST *node = path.next;

	while (node != NULL) {
		temp++;
		node = node->next;
	}

	save_path = (SAVE_PATH*)malloc(sizeof(SAVE_PATH) * (temp + 1));

	temp = 0;
	node = path.next;
	while (node != NULL) {
		save_path[temp].x = node->x;
		save_path[temp].y = node->y;
		save_path[temp].value = map[node->y][node->x] - 10;
		node = node->next;

		temp++;
	}

	save_path[temp].x = map_x - 1;
	save_path[temp].y = map_y - 1;
	save_path[temp].value = map[map_y - 1][map_x - 1];
}
*/

NODE_LIST* add_node(int x, int y, NODE_LIST * prev_node)
{
	NODE_LIST* this_node = (NODE_LIST*)malloc(sizeof(NODE_LIST));

	this_node->x = x;
	this_node->y = y;
	this_node->prev = prev_node;
	prev_node->next = this_node;
	this_node->next = NULL;

	return this_node;
}

void delete_node(NODE_LIST* this_node)
{
	this_node->prev->next = NULL;

	free(this_node);
}

void DFS(int x, int y, int len, NODE_LIST * prev_node)
{
	if (x < 0 || x >= map_x || y < 0 || y >= map_y) {
		return;
	}

	if (map[y][x] >= 10) {
		return;
	}

	if (len + map[y][x] + (map_x - 1 - x) + (map_y - 1 - y) > result) {
		return;
	}

	if (x == map_x - 1 && y == map_y - 1) {
		if (len + map[y][x] < result) {
			result = len + map[y][x];
//			delete_save_path();
//			save_short_path();
		}
		return;
	}

	map[y][x] += 10;

	NODE_LIST *this_node = add_node(x, y, prev_node);

	DFS(x, y + 1, len + (map[y][x] - 10), this_node);
	DFS(x + 1, y, len + (map[y][x] - 10), this_node);

	DFS(x, y - 1, len + (map[y][x] - 10), this_node);
	DFS(x - 1, y, len + (map[y][x] - 10), this_node);

	map[y][x] -= 10;

	delete_node(this_node);
}

int main(void)
{
	int TC;

	FILE * pf;
	freopen_s(&pf, "input.txt", "r", stdin);

	scanf_s("%d", &TC);

	for (int t = 1; t <= TC; t++) {
		scanf_s("%d %d", &map_x, &map_y);

		for (int y = 0; y < map_y; y++) {
			for (int x = 0; x < map_x; x++) {
				scanf_s("%d", &map[y][x]);
			}
		}

		result = map_x * map_y * 10;

		path.x = -1;
		path.y = -1;
		path.prev = NULL;
		path.next = NULL;

//		save_path = NULL;

		DFS(0, 0, 0, &path);

/*
		int temp = 0;
		while (1) {
			printf("%d %d %d\n", save_path[temp].x, save_path[temp].y, save_path[temp].value);

			if (save_path[temp].x == map_x - 1 && save_path[temp].y == map_y - 1) {
				break;
			}

			temp++;
		}
*/
		printf("# %d case Min length = %d\n", t, result);

//		delete_save_path();
	}

	return 0;
}