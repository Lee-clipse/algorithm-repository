#include <iostream>
#include <cstring>
#include <queue>
#include <string>

using namespace std;

void a() {int a=0;for(int i=0;i<4000000000;i++)a=i*i;}

const int maxN = 50;

int M, N;
string map[maxN];
bool visited[maxN][maxN];
int cnt[maxN][maxN];
int treasureMap[maxN][maxN];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0 ,1, 0};

// OK
void setting () {
	memset(visited, 0, sizeof(visited));
	memset(cnt, 0, sizeof(cnt));
	memset(treasureMap, 0, sizeof(treasureMap));
	
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		
		string s;
		cin >> s;
		map[i] = s;
	}
}

void BFS (int y, int x) {
	
	queue < pair<int, int> > q;
	
	visited[y][x] = true;
	q.push({y, x});
	
	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			
			int nx = xx + dx[i];
			int ny = yy + dy[i];
			
			// is movable && is Land && is unvisited
			if (0<=nx && nx<N && 0<=ny && ny<M && map[ny][nx]=='L' && !visited[ny][nx]) {
				
				visited[ny][nx] = true;
				q.push({ny, nx});
				
				cnt[ny][nx] = cnt[yy][xx] + 1;
			}
		}
	}
	
	memset(visited, 0, sizeof(visited));
}

// get one point's biggest shortest paht
// reset cnt[][]
// make treasureMap[][]
int getRoute (int y, int x) {
	
	int myMax = 0;
	
	for (int i = 0; i < M ; i++) {
		
		for (int j = 0; j < N; j++) {
			
			if (cnt[i][j] > myMax) myMax = cnt[i][j];
		}
	}
	
	treasureMap[y][x] = myMax;
	memset(cnt, 0, sizeof(cnt));
	
	return myMax;
}

int main () {
	setting();
	
	int myAns = 0;
	for (int i = 0; i < M; i++) {
		
		for (int j = 0; j < N; j++) {
			
			if (map[i][j] == 'L') {
				
				BFS(i, j);
				int tmp = getRoute(i, j);
				if (myAns < tmp) myAns = tmp;
			}
		} 
	}
	
	cout << myAns;
	
	a();
	return 0;
}
