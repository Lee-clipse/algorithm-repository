#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 510;

int N, M;
int map[maxN][maxN];
int dp[maxN][maxN];

// visited 없는 이유: 최단경로 탐색이 아닌 경로의 수 탐색이기 때문 

int dY[4] = {0, -1, 0, 1};
int dX[4] = {-1, 0, 1, 0};

void Input()
{
	cin >> N >> M;
	memset(dp, -1, sizeof(dp));
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
}

int DFS(int y, int x)
{
	int& ret = dp[y][x];
	
	if (y == N && x == M)
	{
		return 1;
		// 첫 도달시에만 발동 
	}
	
	if (ret != -1)
	{
		return ret;
		// dp의 특징 
	}
	
	ret = 0;
	// dp == -1 이면 아직 미탐색
	// dp == 0 이면 길이 없음 
	
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dY[i];
		int nx = x + dX[i];
		
		if (0 < ny && ny <= N && 0 < nx && nx <= M)
		{
			if (map[ny][nx] < map[y][x])
			{
				ret = ret + DFS(ny, nx);
				// 정지하여 4방향 DFS로 값을 합쳐모음 
			}
		}
	}
	
	return ret;
}

void Solution()
{
	DFS(1, 1);
	cout << dp[1][1];
}

void Solve()
{
	Input();
	Solution();
}

int main(void)
{
	Solve();
 	return 0;
}

