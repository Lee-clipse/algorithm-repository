#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int maxR = 55;

int R, C;
int begY, begX;

char map[maxR][maxR];
char nextmap[maxR][maxR];

bool visited[maxR][maxR];

int dY[4] = {0, -1, 0, 1};
int dX[4] = {-1, 0, 1, 0};

void Input()
{
	cin >> R >> C;
	memset(visited, 0, sizeof(visited));
	
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			char p;
			cin >> p; // ±ú´ÞÀ½ 
			map[i][j] = p;
			
			if (p == 'S')
			{
				begY = i;
				begX = j;
			}
		}
	} // start from [1][1] 
}

void p()
{cout << endl;
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			cout << map[i][j];
		}cout << endl;
	}cout << endl;
}

void maybeFlood()
{
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			if (map[i][j] == '*')
			{
				for (int k = 0; k < 4; k++)
				{
					int ny = i + dY[k];
					int nx = j + dX[k];
					
					if (map[ny][nx] != 'D' && map[ny][nx] != 'X')
					{
						nextmap[ny][nx] = '*';
					}
				}
			}
		}
	}
}

void Flood()
{
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			if (nextmap[i][j] == '*')
			{
				map[i][j] = '*';
				
				nextmap[i][j] = '.';
			}
		}
	}
}

int BFS(int y, int x)
{
	queue < pair <int, int> > q;
	queue < pair <int, int> > nextq;
	
	visited[y][x] = true;
	q.push({y, x});
	
	int move = 1;
	
	while (true)
	{
		maybeFlood();
		
		while (!q.empty())
		{
			int yy = q.front().first;
			int xx = q.front().second;
			
			q.pop();
			
			for (int i = 0; i < 4; i++)
			{
				int ny = yy + dY[i];
				int nx = xx + dX[i];
				
				if (0 < ny && ny <= R && 0 < nx && nx <= C && !visited[ny][nx] && map[ny][nx] != '*' && map[ny][nx] != 'X')
				{
					if (map[ny][nx] == 'D')
					{
						return move;
					}
					
					if (nextmap[ny][nx] != '*')
					{
						visited[ny][nx] = true;
						nextq.push({ny, nx});
					}
				}
			}
		}
		
		move++;
		
		Flood();
		
		if (nextq.empty())
		{
			return -1;
		}
		
		while (!nextq.empty())
		{
			q.push(nextq.front());
			nextq.pop();
		}
	}
	
}

void Solution()
{
	int ans = BFS(begY, begX);
	if (ans == -1)
	{
		cout << "KAKTUS";
	}
	else
	{
		cout << ans;
	}
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

