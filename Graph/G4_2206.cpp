#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int maxN = 1010;

int N, M;

char map[maxN][maxN];
int visited[maxN][maxN][2];

int dY[4] = {0, -1, 0, 1};
int dX[4] = {-1, 0, 1, 0};

void Input()
{
	scanf("%d %d", &N, &M);
	
	for (int i = 1; i <= N; i++)
	{
		scanf("%s", &map[i][1]);
	}
}

int BFS(int y, int x, int breakCnt)
{
	queue < pair < pair < int, int >, int > > q;
	
	visited[y][x][breakCnt] = 1;
	q.push({{y, x}, breakCnt});
	
	while (!q.empty())
	{
		int yy = q.front().first.first;
		int xx = q.front().first.second;
		int bbreak = q.front().second;
		
		q.pop();
		
		if (yy == N && xx == M)
		{
			return visited[yy][xx][bbreak];
		}
		
		for (int i = 0; i < 4; i++)
		{
			int ny = yy + dY[i];
			int nx = xx + dX[i];
			
			if (0 < ny && ny <= N && 0 < nx && nx <= M)
			{
				// 다음이 벽 && 벽을 아직 안깼음 
				if (map[ny][nx] == '1' && bbreak == 0)
				{
					visited[ny][nx][bbreak + 1] = visited[yy][xx][bbreak] + 1;
					q.push({{ny, nx}, bbreak + 1});
				}
				
				// 다음이 벽 X && 미방문 지점 
				if (map[ny][nx] == '0' && visited[ny][nx][bbreak] == 0)
				{
					visited[ny][nx][bbreak] = visited[yy][xx][bbreak] + 1;
					q.push({{ny, nx}, bbreak});
				}
			}
		}
	}
	
	return -1;
}

void Solution()
{
	cout << BFS(1, 1, 0);
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

