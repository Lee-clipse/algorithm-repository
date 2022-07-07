#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

// 10:27 ~ 10:59 (32)

const int maxN = 505;

int N, M, answer = 0;
int arr[maxN][maxN];

vector<vector<pair<int, int>>> dV = {
    {{1, 0}, {2, 0}, {3, 0}}, {{0, 1}, {0, 2}, {0, 3}},
    {{1, 0}, {0, 1}, {1, 1}}, {{1, 0}, {1, 1}, {1, 2}},
    {{0, 1}, {0, 2}, {1, 2}}, {{1, 0}, {0, 1}, {0, 2}},
    {{1, 0}, {1, 1}, {2, 1}}, {{0, 1}, {1, 1}, {1, 2}},
    {{1, 0}, {2, 0}, {2, 1}}, {{0, 1}, {1, 1}, {2, 1}},
    {{0, 1}, {1, 0}, {2, 0}}, {{0, 1}, {0, 2}, {1, 1}},
    {{1, 0}, {2, 0}, {1, 1}},
    {{0, 1}, {0, 2}, {-1, 2}}, {{0, 1}, {-1, 1}, {-2, 1}},
    {{1, 0}, {0, 1}, {-1, 1}}, {{0, 1}, {-1, 1}, {-1, 2}},
    {{0, 1}, {-1, 1}, {0, 2}}, {{0, 1}, {-1, 1}, {1, 1}}
};

int shape(int y, int x) {
    int result = -1;
    for (int i = 0; i < dV.size(); i++) {
        int value = arr[y][x];

        for (int j = 0; j < 3; j++) {
            int ny = y + dV[i][j].first;
            int nx = x + dV[i][j].second;

            if (0 < ny && ny <= N && 0 < nx && nx <= M) {
                value += arr[ny][nx];
            }
            else {
                value = -1;
                break;
            }
        }
        if (value != -1) {
            result = max(result, value);
        }
    }
    return result;
} 

int main() {
	fastio;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            answer = max(answer, shape(i, j));
        }
    }
    cout << answer << "\n";
}