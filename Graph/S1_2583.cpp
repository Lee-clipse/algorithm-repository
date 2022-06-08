#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

const int maxN = 105;

int N, M, K;
int grid[maxN][maxN];

int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

vector <int> ans;

void drawSquare(int x1, int y1, int x2, int y2) {
    for (int i = y1; i <= y2; i++) {
        for (int j = x1; j <= x2; j++) {
            grid[i][j] = 1;
        }
    }
}

int BFS(int y, int x) {
    queue < pair<int, int> > Q;
    grid[y][x] = 1;
    Q.push({y, x});

    int cnt = 1;
    while (!Q.empty()) {
        int yy = Q.front().first;
        int xx = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = yy + dy[i];
            int nx = xx + dx[i];

            if (0 <= ny && ny < N && 0 <= nx && nx < M && !grid[ny][nx]) {
                grid[ny][nx] = 1;
                Q.push({ny, nx});
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
	fastio;
    cin >> N >> M >> K;
    for (int i = 0; i < K; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        drawSquare(x1, y1, x2-1, y2-1);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!grid[i][j]) {
                ans.push_back(BFS(i, j));
            }
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for (auto n : ans) {
        cout << n << " ";
    }

}