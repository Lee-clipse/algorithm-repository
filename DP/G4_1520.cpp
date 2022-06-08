#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 510;

int N, M;
int map[maxN][maxN];
int dp[maxN][maxN];


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
	}
	
	if (ret != -1)
	{
		return ret;
	}
	
	ret = 0;
	
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dY[i];
		int nx = x + dX[i];
		
		if (0 < ny && ny <= N && 0 < nx && nx <= M)
		{
			if (map[ny][nx] < map[y][x])
			{
				ret = ret + DFS(ny, nx);
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

