#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

const int maxN = 16;

int N, ans = 0;
int visited[maxN];

void setQueen(int pos) {
    if (pos == N) {
        ans++;
        return;
    }
    for (int i = 0; i < N; i++) {
        bool flag = true;
        for (int j = i; j < pos; j++) {
            if (visited[j] == i || abs(visited[j]-i) == (pos-j)) {
                flag = false;
                break;
            }
        }
        if (flag) {
            visited[pos] = i;
            setQueen(pos+1);
            visited[pos] = -1;
        }
    }
}

int main() {
	fastio;
    cin >> N;
    memset(visited, -1, sizeof(visited));
    setQueen(0);
    cout << ans << "\n";
}