#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

// 4:32 ~ 5:24 로직 설계의 치명적인 오류를 깨닫고 중단

const int maxW = 1010;

int t, w, h;

vector<vector<char>> building_map(maxW, vector<char>(maxW));

int visited[maxW][maxW];
int fire_visited[maxW][maxW];

int dY[4] = {-1, 0, 1, 0};
int dX[4] = {0, 1, 0, -1};

int begin_y, begin_x;

bool isSafe(int y, int x) {
    for (int i = 0; i < 4; i++) {
        if (building_map[y + dY[i]][x + dX[i]] == '*') return false;
    }
    return true;
}

bool isEscape(int y, int x) {
    for (int i = 0; i < 4; i++) {
        if (building_map[y + dY[i]][x + dX[i]] == '*') return false;
    }
    return true;
}

void moveFire() {
    memset(fire_visited, false, sizeof(fire_visited));

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (!fire_visited[i][j] && building_map[i][j] == '*') {
                fire_visited[i][j] = true;

                for (int k = 0; k < 4; k++) {
                    int ny = i + dY[k];
                    int nx = j + dX[k];

                    // 미방문이며 . 이거나 @ 인 칸에 불을 붙임
                    if ((building_map[ny][nx] == '.' || building_map[i + dY[k]][j + dX[k]] == '@')) {
                        building_map[ny][nx] = '*';
                        fire_visited[ny][nx] = true;
                    }
                }
            }
        }
    }
}

int doEscape(int y, int x) {
    int turn = 1;
    memset(visited, false, sizeof(visited));

    queue<pair<int, int>> Q, next_Q;
    Q.push({y, x});
    visited[y][x] = true;
    next_Q = Q;

    while (!next_Q.empty()) {
        Q = next_Q;
        next_Q = queue<pair<int, int>>();

        int yy = Q.front().first;
        int xx = Q.front().second;
        building_map[yy][xx] = '@';
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = yy + dY[i];
            int nx = xx + dX[i];

            // 벽 또는 불로는 이동할 수 없음    
            if (!visited[ny][nx] && building_map[ny][nx] != '#' && building_map[ny][nx] != '*') {
                
                // 탈출 성공
                if (ny == 0 || ny == h+1 || nx == 0 || nx == w+1) {
                    return turn;
                }

                // 불이 붙으려는 칸이 아니라면 이동
                if (isSafe(ny, nx)) {
                    next_Q.push({ny, nx});
                    visited[ny][nx] = true;
                }
            }
        }

        // 불 진행
        building_map[yy][xx] = '.';
        moveFire();
        turn++;
    }


    return turn;
}

int main() {
	fastio;
    cin >> t;
    while (t--) {
        cin >> w >> h;

        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cin >> building_map[i][j];

                if (building_map[i][j] == '@') {
                    begin_y = i;
                    begin_x = j;
                }
            }
        }

        int result = doEscape(begin_y, begin_x);
        if (result == -1) { 
            cout << "IMPOSSIBLE\n"; 
        }
        else cout << result << "\n";
    }   
}