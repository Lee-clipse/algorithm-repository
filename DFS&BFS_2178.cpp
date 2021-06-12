#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

void a(){int a=0;for(int i=0;i<4000000000;i++)a=i*i;}

const int maxN = 101, maxM = 101;
int N, M;
int map[maxN][maxM];
int cnt[maxN][maxM];
bool visited[maxN][maxM];

int dX[] = {0, 1, 0, -1};
int dY[] = {-1, 0, 1, 0};

// OK
void setting () {
	cin >> N >> M;
	memset(cnt, 0, sizeof(cnt));
	memset(visited, 0, sizeof(visited));
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
}

void BFS (int y, int x) {
	queue < pair<int, int> > q;
	visited[y][x] = true;
	q.push({y, x});
	cnt[y][x]++;
	
	while (!q.empty()) {
		int xx = q.front().second;
		int yy = q.front().first;
		q.pop();
		
		// explore 4 direct
		for (int i = 0; i < 4; i++) {
			int nx = xx + dX[i];
			int ny = yy + dY[i];
			
			// is in Field? && is visited? && is it Road?
			if (1<=nx && nx<=M && 1<=ny && ny<=N && !visited[ny][nx] && map[ny][nx] == 1) {
				visited[ny][nx] = true;
				q.push({ny, nx});
				cnt[ny][nx] = cnt[yy][xx] + 1;
			}
		}
	}
}

int main () {
	setting();
	
	BFS(1, 1);

	cout << cnt[N][M];
	
	a();
	return 0;
}
