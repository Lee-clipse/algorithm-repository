#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

// 7:03 ~ 7:20

const int maxN = 205;
const int maxM = 1005;

int N, M;

int travel[maxN];
int plan[maxM];

int find(int u) {
    if (u == travel[u]) {
        return u;
    }
    else {
        return travel[u] = find(travel[u]);
    }
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);

    if (u < v) {
        travel[v] = u;
    }
    else {
        travel[u] = v;
    }
}


int main() {
	fastio;
    cin >> N >> M;

    // 초기화
    for (int i = 1; i <= N; i++) {
        travel[i] = i;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int p;
            cin >> p;

            if (p == 1) {
                merge(i, j);
            }
        }
    }

    
    for (int i = 1; i <= M; i++) {
        cin >> plan[i];
    }

    for (int i = 1; i <= M; i++) {
        for (int j = i+1; j <= M; j++) {
            if (find(plan[i]) != find(plan[j])) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    return 0;
}