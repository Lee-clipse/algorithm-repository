#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int N, M;

vector <int> graph[1001];
bool visited[1001];

void BFS(int start) {
    queue <int> Q;
    visited[start] = true;
    Q.push(start);

    while (!Q.empty()){
        int cur = Q.front();
        Q.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];

            if (!visited[next]) {
                Q.push(next);
                visited[next] = true;
            }
        }
    }
}

int main() {
	fastio;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int answer = 0;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            BFS(i);
            answer++;
        }
    }
    cout << answer << "\n";
}