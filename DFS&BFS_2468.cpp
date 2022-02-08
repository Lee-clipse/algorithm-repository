#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int maxN = 110;

int N;

int minTop = 100;
int maxTop = 0;

int map[maxN][maxN];
bool visited[maxN][maxN];

int dY[4] = {0, -1, 0, 1};
int dX[4] = {-1, 0, 1, 0};

void Input()
{
	cin >> N;
	memset(visited, 0, sizeof(visited));
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int top;
			cin >> top;
			map[i][j] = top;
			
			minTop = min(minTop, top);
			maxTop = max(maxTop, top);
		}
	}
}

void Sink(int top)
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (map[i][j] <= top)
			{
				map[i][j] = -1;
			}
		}
	}
}

int BFS(int y, int x)
{
	queue < pair <int, int> > q;
	
	visited[y][x] = true;
	q.push({y, x});
	
	while (!q.empty())
	{
		int yy = q.front().first;
		int xx = q.front().second;
		
		q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int ny = yy + dY[i];
			int nx = xx + dX[i];
			
			if (0 < ny && ny <= N && 0 < nx && nx <= N && !visited[ny][nx] && map[ny][nx] != -1)
			{
				visited[ny][nx] = true;
				q.push({ny, nx});
			}
		}
	}

	return 1;
}

void Solution()
{
	int ans = 0;

	for (int t = 0; t <= maxTop; t++)
	{
		int safezone = 0;
		
		Sink(t);
		
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (!visited[i][j] && map[i][j] != -1)
				{
					safezone += BFS(i, j);
				}
			}
		}
		
		ans = max(ans, safezone);
		
		memset(visited, 0, sizeof(visited));
	}
	
	cout << ans;
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

