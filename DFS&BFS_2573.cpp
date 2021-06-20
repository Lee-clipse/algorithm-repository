#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

void a(){int a=0;for(int i=0;i<4000000000;i++)a=i*i;}

const int maxN = 300;

int M, N;
int map[maxN][maxN];
bool visited[maxN][maxN];
// (0, 0)

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

// OK
void setting () {
	
	cin >> M >> N;
	memset(visited, 0, sizeof(visited));
	
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}	
	}
}

// OK
// melt one spot
void melt (int y, int x) {
	
	int cnt = 0;
	
	for (int i = 0; i < 4; i++) {
		
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if (map[ny][nx] == 0 && !visited[ny][nx]) cnt++;
	}
	
	if (cnt > map[y][x]) map[y][x] = 0;
	else map[y][x] -= cnt;
}

// OK
void printMap () {
	
	for (int i = 0; i < M; i++) {
		
		for (int j = 0; j < N; j++) {
			
			cout << map[i][j] << " ";
		} 
		cout << endl;
	}
}

// OK
void BFS (int y, int x) {
	
	queue < pair<int, int> > q;
	visited[y][x] = true;
	q.push({y, x});
	
	while (!q.empty()) {
		
		int yy = q.front().first;
		int xx = q.front().second;
		
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			
			int ny = yy + dy[i];
			int nx = xx + dx[i];
			
			if (map[ny][nx] != 0 && !visited[ny][nx]) {
				
				visited[ny][nx] = true;
				q.push({ny, nx});
			}
		}
	}
}

// OK
// print iceberg mass
int isSeparate () {
	
	int cnt = 0;
	for (int i = 1; i < M; i++) {
		
		for (int j = 1; j < N; j++) {
			
			if (map[i][j] != 0 && !visited[i][j]) {
				
				BFS(i, j);
				cnt++;
			}
		} 
	}
	memset(visited, 0, sizeof(visited));
	return cnt;
}

void iceberg () {
	
	int year = 0;
	// true 로 바꾸자 
	while (true) {
		
		int state = isSeparate();
		cout << "state: " << state << endl;
		if (state != 1) {
			// mistake 1
			// if run this part, 'isSeparate() function run twice!
			// then visited[][] problem occurs
			
			if (state == 0) year = 0;
			
			cout << "ANS: " << year;
			return ;
		}
		
		for (int i = 0; i < M; i++) {
			
			for (int j = 0; j < N; j++) {
				
				if (map[i][j] != 0) {
					
					melt(i, j);
					visited[i][j] = true;	
				}
			} 
		}
		memset(visited, 0, sizeof(visited));
		year++;
	}
}

int main () {
	
	setting();
	
	iceberg();
	
	a();
	return 0;
}



