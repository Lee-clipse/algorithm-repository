#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

void a(){int a=0;for(int i=0;i<4000000000;i++)a=i*i;}

const int maxN = 101;
const int notFound = -1;

int N, M, A, B;
bool visited[maxN];
vector <int> net[maxN];

void setting () {
	cin >> N >> A >> B >> M;
	memset(visited, 0, sizeof(visited));
	
	int x, y;
	for (int i = 1; i <= M; i++) {
		cin >> x >> y;
		net[x].push_back(y);
		net[y].push_back(x);
	}
}

int DFS (int start) {
	stack <int> s;
	visited[start] = true;
	s.push(start);
	
	while (!s.empty()) {
		int cur = s.top();
		s.pop();
		
		for (int i = 0; i < net[cur].size(); i++) {
			int next = net[cur][i];
			if (visited[next] != true) {
				visited[next] = true;
				s.push(cur);
				s.push(next);
				
				if (s.top() == B) return s.size()-1;
				
				break;
			}
		}
	}
	
	return notFound;
}

int main () {
	setting();
	cout << DFS(A);
	
	a();
	return 0;
}
