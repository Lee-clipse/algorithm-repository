#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

void a(){int a=0;for(int i=0;i<4000000000;i++)a=i*i;}

// start from (0, 0)
const int maxN = 50;

int N, M;
char map[maxN][maxN];
bool visited[maxN][maxN];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool isCycle = false;

void Input()
{
	memset(visited, 0, sizeof(visited));
	
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}	
}

bool DFS(int y, int x, char color)
{
	stack < pair<int, int> > s;
	
	//visited[y][x] = true;
	s.push({y, x});
	
	while (!s.empty())
	{
		int yy = s.top().first;
		int xx = s.top().second;
		
		//printf("im in(%d, %d)\n", yy, xx);
		
		if (s.size() >= 4 && yy == y && xx == x)
		{
			return true;
		}
		
		s.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int ny = yy + dy[i];
			int nx = xx + dx[i];
			
			if (0<=ny && ny<N && 0<=nx && nx<M && map[ny][nx]==color && !visited[ny][nx])
			{
				visited[ny][nx] = true;
				s.push({yy, xx});
				s.push({ny, nx});
				break;
			}
		}
	}
	
	return false;
}

void Solution()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("(%d, %d) START!!!!!!!!!!!", i, j);
			bool isCycle = DFS(i, j, map[i][j]);
			if (isCycle)
			{
				cout << "Yes";
				return ;
			}
			
			memset(visited, 0, sizeof(visited));
		}
	}
	
	cout << "No";
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
