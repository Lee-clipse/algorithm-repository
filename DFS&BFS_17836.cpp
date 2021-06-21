#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

void a(){int a=0;for(int i=0;i<4000000000;i++)a=i*i;}

// start from (1, 1)
const int maxN = 101;

int N, M ,T;
int map[maxN][maxN];
bool visited[maxN][maxN];
int cnt[maxN][maxN];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int planA = 0;
int planB = 0;

void setting () {
	
	memset(visited, 0, sizeof(visited));
	memset(cnt, 0, sizeof(cnt));
	
	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++) {
		
		for (int j = 1; j <= M; j++) {
			
			cin >> map[i][j];
		}
	}
}

int BFS (int y, int x) {
	
	queue < pair<int, int> > q;
	
	visited[y][x] = true;
	q.push({y, x});
	
	while (!q.empty()) {
		
		int yy = q.front().first;
		int xx = q.front().second;
		
		q.pop();
		
		// find (N, M)
		if (yy == N && xx == M) {
			
			planA = cnt[yy][xx];
		}
		
		// find 'GRIM'
		if (map[yy][xx] == 2) {
			
			planB = N-yy + M-xx + cnt[yy][xx];
		}
		
		for (int i = 0; i < 4; i++) {
			
			int ny = yy + dy[i];
			int nx = xx + dx[i];
			
			// 0 or 2
			if (1<=ny && ny<=N && 1<=nx && nx<=M && !visited[ny][nx] && map[ny][nx]!=1) {
				
				visited[ny][nx] = true;
				q.push({ny, nx});
				cnt[ny][nx] = cnt[yy][xx] + 1;
			} 
		}
	}
	
	if (planA == 0 && planB == 0) {
		
		return 0;
	}
	
	if (planA == 0 || planB == 0) {
		
		return max(planA, planB);
	}
	
	return min(planA, planB);
}

int main () {
	
	setting();
		
	int myAns = BFS(1, 1);
	
	if (myAns == 0 || myAns > T) {
		
		cout << "Fail";
		return 0;
	}
	
	cout << myAns;
	
	a();
	return 0;
}



