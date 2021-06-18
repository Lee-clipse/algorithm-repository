#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

void a(){int a=0;for(int i=0;i<4000000000;i++)a=i*i;}

const int maxLoc = 100001;

int N, K;
int map[maxLoc];
bool visited[maxLoc];

void setting () {
	cin >> N >> K;
	memset(visited, 0, sizeof(visited));
	memset(map, 0, sizeof(map));
}

void BFS (int start) {
	queue <int> q;
	visited[start] = true;
	q.push(start);
	
	while (!q.empty()) {
		int cur = q.front();
		if (cur == K) return ;
		q.pop();
		
		int nexLoc[3] = {cur-1, cur+1, cur*2};
		for (int i = 0; i < 3; i++) {
			int nex = nexLoc[i];
			
			if (0<=nex && nex<maxLoc && !visited[nex]) {
				q.push(nex);
				visited[nex] = true;
				map[nex] = map[cur] + 1;
			}
		}
	}
}

int main () {
	setting();
	BFS(N);
	cout << map[K] << endl;
	
	a();
	return 0;
}




