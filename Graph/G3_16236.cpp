#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

void a(){int a=0;for(int i=0;i<4000000000;i++)a=i*i;}

using namespace std;

// start from (0, 0)
const int maxN = 20;

int N, Y, X;
int map[maxN][maxN];
bool visited[maxN][maxN];
int cnt[maxN][maxN];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int Momcall = 0;

struct Fish
{
	// dist = 0 -> ERROR 
	int y, x, dist;
	
	bool operator < (const Fish &b) const
	{
		if (dist == b.dist)
		{
			if (y == b.y)
			{
				return x > b.x;
			}
			return y > b.y;
		}
		return dist > b.dist;
	}
};

void Input()
{
	memset(visited, 0, sizeof(visited));
	memset(cnt, 0, sizeof(cnt));
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			
			if (map[i][j] == 9)
			{
				Y = i; X = j;
			}
		}
	}
}

void BFS(int y, int x, int bite, priority_queue <Fish> &pq)
{
	memset(cnt, 0, sizeof(cnt));
	memset(visited, 0, sizeof(visited));
	queue < pair<int, int> > q;
	
	visited[y][x] = true;
	map[y][x] = 0;
	q.push({y, x});
	
	while (!q.empty())
	{
		int yy = q.front().first;
		int xx = q.front().second;
		
		q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int ny = yy + dy[i];
			int nx = xx + dx[i];
			
			if (0<=ny && ny<N && 0<=nx && nx<N && !visited[ny][nx] && map[ny][nx]<=bite)
			{
				visited[ny][nx] = true;
				cnt[ny][nx] = cnt[yy][xx] + 1;
				q.push({ny, nx});
				
				if (0<map[ny][nx] && map[ny][nx]<bite)
				{
					pq.push({ny, nx, cnt[ny][nx]});
				}
			}
		}
	}
}

void Solution()
{
	priority_queue <Fish> pq;
	
	int yy = Y, xx = X;
	int bite = 2, ate = 0;
	
	while (true)
	{
		BFS(yy, xx, bite, pq);
		
		if (pq.empty())
		{
			cout << Momcall;
			return ;
		}
		
		Fish feed = pq.top();
		yy = feed.y;
		xx = feed.x;
		Momcall += feed.dist;
		ate++;
		
		if (bite == ate)
		{
			bite++;
			ate = 0;
		}
		
		while (!pq.empty())
		{
			pq.pop();
		}
	}
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
