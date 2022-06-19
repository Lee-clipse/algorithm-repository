#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

const int maxN = 100010;

int N;
vector <vector <int>> tree(maxN);
int parent[maxN];

void BFS(int start) {
    queue <int> Q;
    parent[start] = start;
    Q.push(1);

    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();

        for (auto node : tree[cur]) {
            if (parent[node] == 0) {
                parent[node] = cur;
                Q.push(node);
            }
        }
    }
}

int main() {
	fastio;
    cin >> N;
    for (int i = 0; i < N-1; i++) {
        int p, q;
        cin >> p >> q;
        tree[p].push_back(q);
        tree[q].push_back(p);
    }

    BFS(1);

    for (int i = 2; i <= N; i++) {
        cout << parent[i] << "\n";
    }
}