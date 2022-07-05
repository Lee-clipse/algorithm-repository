#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

const int maxW = 1010;

int t, w, h;

string maps[maxW];

int visited[maxW][maxW];
int fire_visited[maxW][maxW];

int dY[4] = {-1, 0, 1, 0};
int dX[4] = {0, 1, 0, -1};

int BFS(pair<int, int> start, queue<pair<int, int>> fire) {
    int result = -1;
    queue<pair<int, int>> Q;
    Q.push(start);

    int turn = 1;
    while (!Q.empty()) {
        
        // 붙 붙이기
        int fire_count = fire.size();
        for (int i = 0; i < fire_count; i++) {
            int yy = fire.front().first;
            int xx = fire.front().second;
            fire.pop();

            for (int j = 0; j < 4; j++) {
                int ny = yy + dY[j];
                int nx = xx + dX[j];

                // 벽이 아니고 범위 내라면 불 붙히기
                if (0 <= ny && ny < h && 0 <= nx && nx < w) {
                    if (fire_visited[ny][nx] == 0 && maps[ny][nx] != '#') {
                        maps[ny][nx] = '*';
                        fire.push({ny, nx});
                        fire_visited[ny][nx] = 1;
                    }
                }
            }
        }

        // 탈출 시도
        int move_count = Q.size();
        for (int i = 0; i < move_count; i++) {
            int yy = Q.front().first;
            int xx = Q.front().second;
            Q.pop();

            // 탈출 성공
            if (yy == 0 || yy == h-1 || xx == 0 || xx == w-1) {
                return turn;
            }

            for (int j = 0; j < 4; j++) {
                int ny = yy + dY[j];
                int nx = xx + dX[j];

                // 범위 내에서
                if (0 <= ny && ny < h && 0 <= nx && nx < w) {
                    
                    // 벽과 불이 아닌 곳으로
                    if (visited[ny][nx] == 0 && maps[ny][nx] != '#' && maps[ny][nx] != '*') {
                        Q.push({ny, nx});
                        visited[ny][nx] = 1;
                    }
                }
            }
        }
        
        turn++;
    }

    return result;
}

int main() {
	fastio;
    cin >> t;
    while (t--) {
        cin >> w >> h;

        pair<int, int> start_place;
        queue<pair<int, int>> fire_place;
        for (int i = 0; i < h; i++) {
            cin >> maps[i];

            for (int j = 0; j < maps[i].size(); j++) {
                if (maps[i][j] == '@') {
                    start_place = {i, j};
                    visited[i][j] = 1;
                }
                else if (maps[i][j] == '*') {
                    fire_place.push({i, j});
                    fire_visited[i][j] = 1;
                }
            }
        }

        memset(visited, 0, sizeof(visited));
        memset(fire_visited, 0, sizeof(fire_visited));

        int result = BFS(start_place, fire_place);
        if (result == -1) {
            cout << "IMPOSSIBLE\n";
        }
        else {
            cout << result << "\n";
        }
    }
}