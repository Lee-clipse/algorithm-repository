#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

void a() {int a=0;for(int i=0;i<4000000000;i++) a=i*i;}

const int maxF = 1000000;

int F, S, G, U, D;

bool visited[maxF];
int floor[maxF];

void setting () {
	cin >> F >> S >> G >> U >> D;
	memset(visited, 0, sizeof(visited));
	memset(floor, 0, sizeof(floor));
}

void BFS (int start) {
	queue <int> q;
	visited[start] = true;
	q.push(start);
	
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		
		if (cur == G) return ;
		
		int nextF[2] = {cur + U, cur - D};
		
		for (int i = 0; i < 2; i++) {
			int nex = nextF[i];
			
			if (1<=nex && nex<=F && !visited[nex]) {
				visited[nex] = true;
				q.push(nex);
				floor[nex] = floor[cur] + 1;
			}
		}
	}
	
	floor[G] = -1;
}

int main () {
	setting();	
	
	BFS(S);
	
	if (floor[G] != -1) cout << floor[G];
	else cout << "use the stair\n";
	
	a();
	return 0;
}


