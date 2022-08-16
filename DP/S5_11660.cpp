#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

// 11:08 ~ 11:24

using namespace std;

const int maxN = 1025;

int N, M;

int sum[maxN][maxN];

int main() {
	fastio;
    cin >> N >> M;

    int p;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> p;
            sum[i][j] = p + sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1];
        }
    }

    int y1, x1, y2, x2;
    while (M--) {
        cin >> y1 >> x1 >> y2 >> x2;
        cout << (
            sum[y2][x2] - sum[y1-1][x2] - sum[y2][x1-1] + sum[y1-1][x1-1]
        ) << "\n";
    }
}