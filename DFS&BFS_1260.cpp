#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

void a(){int a=0;for(int i=0;i<40000000000;i++)a=i*i;}

const int maxN = 1000;
const int maxM = 10000;

int N, M, V;
bool visited[maxN];
vector <int> v[maxN];

// OK
void input () {
	cin >> N >> M >> V;
	memset(visited, 0, sizeof(visited));
	
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	for (int i = 0; i < N; i++) {
		sort(v[i].begin(), v[i].end());
	}
}

// OK
void DFS (int start) {
	stack <int> s;
	
	visited[start] = true;
	s.push(start);
	
	printf("%d ", start);
	
	while (!s.empty()) {
		int cur = s.top();
		s.pop();
		
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			
			if (visited[next] != true) {
				visited[next] = true;
				
				s.push(cur);
				s.push(next);
				
				printf("%d ", next);
				break;
			}
		}
	}
	
	memset(visited, 0, sizeof(visited));
	cout << endl;
}

// OK
void BFS (int start) {
	queue <int> q;
	
	visited[start] = true;
	q.push(start);
	printf("%d ", start);
	
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			
			if (visited[next] != true) {
				visited[next] = true;
				q.push(next);
				
				printf("%d ", next);
			}
		}
	}
	
	memset(visited, 0, sizeof(visited));
	cout << endl;
}

int main () {
	input();
	
	DFS(V);
	BFS(V);
	
	a();
	return 0;
}
