#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

int map[8][8];
int for_three[8][8]; // 0: 미방문, 1: 가로 통과, 2: 세로 통과, 3: 가로세로 통과
int placed[8][8]; // 현재 노드에 어떤 선로를 놓을지
int Y, X;
int sum;

bool is_in(int y, int x) {
    if (y >= 0 && y < Y && x >= 0 && x < X)
        return true;
    else
        return false;
}

vector<int> get_yxd(int y, int x, int prev_dir, int idx) {
    int ny = -1;
    int nx = -1;
    int dir = -1;
    vector<int> v;
    
    switch(idx) {
        case 1:
            if (prev_dir == RIGHT) {
                ny = y;
                nx = x + 1;
                dir = RIGHT;
            }
            else if (prev_dir == LEFT) {
                ny = y;
                nx = x - 1;
                dir = LEFT;
            }
            break;
        case 2:
            if (prev_dir == UP) {
                ny = y - 1;
                nx = x;
                dir = UP;
            }
            else if (prev_dir == DOWN) {
                ny = y + 1;
                nx = x;
                dir = DOWN;
            }
            break;
        case 3:
            if (prev_dir == RIGHT) {
                ny = y;
                nx = x + 1;
                dir = RIGHT;
            }
            else if (prev_dir == LEFT) {
                ny = y;
                nx = x - 1;
                dir = LEFT;
            }
            else if (prev_dir == UP) {
                ny = y - 1;
                nx = x;
                dir = UP;
            }
            else if (prev_dir == DOWN) {
                ny = y + 1;
                nx = x;
                dir = DOWN;
            }
            break;
        case 4:
            if (prev_dir == RIGHT) {
                ny = y - 1;
                nx = x;
                dir = UP;
            }
            else if (prev_dir == DOWN) {
                ny = y;
                nx = x - 1;
                dir = LEFT;
            }
            break;
        case 5:
            if (prev_dir == LEFT) {
                ny = y - 1;
                nx = x;
                dir = UP;
            }
            else if (prev_dir == DOWN) {
                ny = y;
                nx = x + 1;
                dir = RIGHT;
            }
            break;
        case 6:
            if (prev_dir == LEFT) {
                ny = y + 1;
                nx = x;
                dir = DOWN;
            }
            else if (prev_dir == UP) {
                ny = y;
                nx = x + 1;
                dir = RIGHT;
            }
            break;
        case 7:
            if (prev_dir == RIGHT) {
                ny = y + 1;
                nx = x;
                dir = DOWN;
            }
            else if (prev_dir == UP) {
                ny = y;
                nx = x - 1;
                dir = LEFT;
            }
            break;
        default:
            break;
    }
    
    v.push_back(ny);
    v.push_back(nx);
    v.push_back(dir);
    
    return v;
}

void DFS(int y, int x, int prev_dir) {
    if (placed[y][x] == 3 && for_three[y][x] == 3)
        return;
    else if (placed[y][x] != 3 && placed[y][x] > 0)
        return;
    
    if (y == Y - 1 && x == X - 1) {
        for (int i = 0; i < Y; i++) {
            for (int j = 0; j < X; j++) {
                if (i == Y - 1 && j == X - 1)
                    continue;
                
                if (placed[i][j] == 3 && for_three[i][j] != 3)
                    return;
                
                if (map[i][j] > 0) {
                    if (map[i][j] == 3 && for_three[i][j] != 3)
                        return;
                    else if (map[i][j] != placed[i][j])
                        return;
                }
            }
        }
        
        if (map[y][x] == 1 && prev_dir == RIGHT)
            sum++;
        else if (map[y][x] == 2 && prev_dir == DOWN)
            sum++;
        
        return;
    }
    
    int cur_idx;
    
    if (placed[y][x] == 3)
        cur_idx = 3;
    else
        cur_idx = map[y][x];
    
    if (cur_idx > 0) { // 현재 노드는 처음부터 선로가 있는데, prev_dir의 방향과 현재 선로가 맞지 않으면 return
        if (prev_dir == UP && !(cur_idx == 2 || cur_idx == 3 || cur_idx == 6 || cur_idx == 7))
            return;
        else if (prev_dir == DOWN && !(cur_idx == 2 || cur_idx == 3 || cur_idx == 4 || cur_idx == 5))
            return;
        else if (prev_dir == LEFT && !(cur_idx == 1 || cur_idx == 3 || cur_idx == 5 || cur_idx == 6))
            return;
        else if (prev_dir == RIGHT && !(cur_idx == 1 || cur_idx == 3 || cur_idx == 4 || cur_idx == 7))
            return;
    }
    
    for (int i = 1; i <= 7; i++) {
        if (cur_idx > 0 && i != cur_idx)
            continue;
        
        vector<int> v = get_yxd(y, x, prev_dir, i);
        int ny = v[0];
        int nx = v[1];
        int dir = v[2];
        v.clear();
        
        if (dir != -1 && is_in(ny, nx) && map[ny][nx] != -1) {
            if (i == 3) {
                if (placed[y][x] == 0) {
                    if (prev_dir == RIGHT || prev_dir == LEFT) {
                        placed[y][x] = 3;
                        for_three[y][x] = 1;
                        DFS(ny, nx, dir);
                        placed[y][x] = 0;
                        for_three[y][x] = 0;
                    }
                    else if (prev_dir == UP || prev_dir == DOWN) {
                        placed[y][x] = 3;
                        for_three[y][x] = 2;
                        DFS(ny, nx, dir);
                        placed[y][x] = 0;
                        for_three[y][x] = 0;
                    }
                }
                else {
                    if (for_three[y][x] == 2 && (prev_dir == RIGHT || prev_dir == LEFT)) {
                        for_three[y][x] = 3;
                        DFS(ny, nx, dir);
                        for_three[y][x] = 2;
                    }
                    else if (for_three[y][x] == 1 && (prev_dir == UP || prev_dir == DOWN)) {
                        for_three[y][x] = 3;
                        DFS(ny, nx, dir);
                        for_three[y][x] = 1;
                    }
                }
            }
            else {
                placed[y][x] = i;
                DFS(ny, nx, dir);
                placed[y][x] = 0;
            }
        }
    }
}

int solution(vector<vector<int>> grid) {
    
    for (int y = 0; y < grid.size(); y++)
        for (int x = 0; x < grid[y].size(); x++)
            map[y][x] = grid[y][x];
    
    Y = grid.size();
    X = grid[0].size();
    
    DFS(0, 0, RIGHT);
    
    int answer = sum;
    return answer;
}
