#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

void a(){int a=0;for(int i=0;i<40000000000;i++)a=i*i;}

const int maxN = 25;

int N;
int map[maxN][maxN];
bool visited[maxN][maxN];
int dX[] = {0, 1, 0, -1};
int dY[] = {-1, 0, 1, 0};

// OK
void setting () {
	cin >> N;
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
}

int BFS (int y, int x) {
	queue < pair<int, int> > q;
	visited[y][x] = true;
	q.push({y, x});
	
	int cnt = 1;
	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int ny = yy + dY[i];
			int nx = xx + dX[i];
			
			if (0<=nx && nx<=N && 0<=ny && ny<=N && !visited[ny][nx] && map[ny][nx]==1) {
				visited[ny][nx] = true;
				q.push({ny, nx});
				cnt++;
			}
		}
	}
	return cnt;
}

int main () {
	setting();
	
	vector <int> group;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1 && !visited[i][j]) {
				int members = BFS(i, j);
				group.push_back(members);
			}
		}
	}
	
	sort(group.begin(), group.end());
	
	cout << group.size() << "\n";
	for (int i = 0; i < group.size(); i++) {
		cout << group[i] << "\n";
	}
	

	a();
	return 0;
}
