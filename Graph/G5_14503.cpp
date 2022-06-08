#include <iostream>
#include <cstring>

using namespace std;

void a(){int a=0;for(int i=0;i<4000000000;i++)a=i*i;}

// start from (0, 0)
const int maxN = 50;

int N, M, R, C, D;
int map[maxN][maxN];
bool visited[maxN][maxN];

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int cnt = 0;

void Input()
{
	memset(visited, 0, sizeof(visited));
	
	cin >> N >> M;
	cin >> R >> C >> D;
	for (int i =0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
}

void DFS(int r, int c, int d)
{
	// 1
	if (visited[r][c] != true)
	{
		visited[r][c] = true;
		cnt++;
	}
	
	for (int i = 0; i < 4; i++)
	{
		// 2
		int nd = (d+3)%4;
		int nr = r + dr[nd];
		int nc = c + dc[nd];
		
		if (0<=nr && nr<N && 0<=nc && nc<M && map[nr][nc]!=1 && !visited[nr][nc])
		{
			// 2.a -> 1
			DFS(nr, nc, nd);
			
			return ;
		}
		// 2.b -> 2
		d = nd;
	}
	
	int br = r - dr[d];
	int bc = c - dc[d];
	
	if (0<=br && br<N && 0<=bc && bc<M && map[br][bc]!=1)
	{
		// 2.c -> 2
		DFS(br, bc, d);
	}
	// 2.d
	return ;
}

void Solution()
{
	DFS(R, C, D);
	
	cout << cnt << endl;
}

void Solve()
{
	Input();
	Solution();
}

int main()
{
	Solve();
	
	a();
	return 0;
}
