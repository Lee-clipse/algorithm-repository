#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

const int maxW = 1010;

int t, w, h;

// 빌딩 지도
string maps[maxW];

// 방문 배열
int visited[maxW][maxW];
int fire_visited[maxW][maxW];

int dY[4] = {-1, 0, 1, 0};
int dX[4] = {0, 1, 0, -1};


int BFS(pair<int, int> start, queue<pair<int, int>> fire) {
    int result = -1;

    // 이동가능한 좌표를 저장할 큐
    queue<pair<int, int>> Q;
    Q.push(start);

    while (!Q.empty()) {
        
        // 붙 붙이기
        int fire_count = fire.size();

        // 불이 붙은 칸과 불이 붙을 칸을 구분하기 위해 fire_count만큼 실행
        for (int i = 0; i < fire_count; i++) {
            int yy = fire.front().first;
            int xx = fire.front().second;
            fire.pop();

            for (int j = 0; j < 4; j++) {
                int ny = yy + dY[j];
                int nx = xx + dX[j];

                // 범위 내에서
                if (0 <= ny && ny < h && 0 <= nx && nx < w) {

                    // 미방문이고 벽이 아니라면 불 붙이기
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

        // 이동한 칸과 이동할 칸을 구분하기 위해 move_count만큼 실행
        for (int i = 0; i < move_count; i++) {
            int yy = Q.front().first;
            int xx = Q.front().second;
            Q.pop();

            // 탈출 성공
            if (yy == 0 || yy == h-1 || xx == 0 || xx == w-1) {
                return visited[yy][xx] + 1;
            }

            for (int j = 0; j < 4; j++) {
                int ny = yy + dY[j];
                int nx = xx + dX[j];

                // 범위 내에서
                if (0 <= ny && ny < h && 0 <= nx && nx < w) {
                    
                    // 미방문이고 벽과 불이 아닌 칸이라면 방문
                    if (visited[ny][nx] == 0 && maps[ny][nx] != '#' && maps[ny][nx] != '*') {
                        Q.push({ny, nx});
                        visited[ny][nx] = visited[yy][xx] + 1;
                    }
                }
            }
        }
    }
    return result;
}

int main() {
	fastio;
    cin >> t;
    while (t--) {
        cin >> w >> h;

        // 출발 좌표, 불 좌표 저장
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

        // 방문 배열 초기화
        memset(visited, 0, sizeof(visited));
        memset(fire_visited, 0, sizeof(fire_visited));

        // 탈출에 걸리는 시간 반환
        int result = BFS(start_place, fire_place);
        if (result == -1) {
            cout << "IMPOSSIBLE\n";
        }
        else {
            cout << result << "\n";
        }
    }
}