#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

void a(){int a=0;for(int i=0;i<4000000000;i++)a=i*i;}

const int maxN = 101;

int N, M;
bool visited[maxN];
vector <int> net[maxN];

// OK
void setting () {
	cin >> N >> M;
	memset(visited, 0, sizeof(visited));
	
	int a, b;
	for (int i = 1; i <= M; i++) {
		cin >> a >> b;
		net[a].push_back(b);
		net[b].push_back(a);
	}
}

void BFS (int start) {
	queue <int> q;
	visited[start] = true;
	q.push(start);
	
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		
		for (int i = 0; i < net[cur].size(); i++) {
			int next = net[cur][i];
			if (visited[next] != true) {
				visited[next] = true;
				q.push(next);
			}
		}
	}
}

int main () {
	setting();
	
	BFS(1);
	
	int cnt = 0;
	for (int i = 2; i <= N; i++) {
		if (visited[i] == true) cnt++;
	}
	cout << cnt;
	
	/*
	for (int i = 1; i <= N; i++) {
		cout << i << ": ";
		for (int j = 0; j < net[i].size(); j++) {
			cout << net[i][j] << " ";
		} cout << endl;
	}
	*/
	
	a();
	return 0;
}
