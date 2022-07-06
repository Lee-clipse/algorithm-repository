#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define MAX_SIZE 1000002

using namespace std;

int parent[MAX_SIZE];

// u의 부모를 반환
int find(int u) {

    // 음수면 루트 노드이므로 자신을 반환
    if (parent[u] < 0) {
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

    if (u == v) {
        return ;
    }

    // 양수 < 양수 일 경우 더 작은 쪽이 루트가 됨
    // 음수 < 음수 일 경우 트리 사이즈가 더 큰 쪽이 루트가 됨 (트리가 점점 깊어짐을 막기 위함)
    if (parent[u] < parent[v]) {
        parent[u] += parent[v];
        parent[v] = u;
    }
    else {
        parent[v] += parent[u];
        parent[u] = v;
    }
}

int main() {
    fastio;
    int n, m;
    cin >> n >> m;

    // 초기화
    for (int i = 0; i <= n; i++) {
        parent[i] = -1;
    }

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