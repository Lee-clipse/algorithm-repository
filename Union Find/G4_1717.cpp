#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

const int maxN = 1000010;

int n, m;

int parent[maxN];

// 배열 초기화
void init() {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
}

// u의 부모를 반환
int find(int u) {
    if (parent[u] == u) {
        return u;
    }
    else {
        return parent[u] = find(parent[u]);
    }
}

// u와 v가 속한 집합을 합침
void merge(int u, int v) {
    u = find(u);
    v = find(v);

    // 작은 u가 부모로 들어감
    if (u < v) {
        parent[v] = u;
    }
    else if (u > v) {
        parent[u] = v;
    }
}

int main() {
	fastio;
    cin >> n >> m;

    while (m--) {
        int sig, a, b;
        cin >> sig >> a >> b;

        if (sig == 0) {
            merge(a, b);
        }

        else {
            if (find(a) == find(b)) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }
}