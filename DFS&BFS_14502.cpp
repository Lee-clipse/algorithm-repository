#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <windows.h>

using namespace std;

const int maxN = 9;

int answer = -1;
int N, M;
int origin_map[maxN][maxN];
int map[maxN][maxN];

bool wall_visited[maxN*maxN];
bool virus_visited[maxN][maxN];

vector < pair <int, int> > wall;

int dY[4] = {0, -1, 0, 1};
int dX[4] = {-1, 0, 1, 0};


void Input()
{
	cin >> N >> M;
	
	memset(wall_visited, 0, sizeof(wall_visited));
	memset(virus_visited, 0, sizeof(virus_visited));
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int val;
			cin >> val;
			
			origin_map[i][j] = val;
			
			if (val == 0) wall.push_back(make_pair(i, j));
		}
	}
}

void printMap()
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == -1)
			{
				SetConsoleTextAttribute(hConsole, 143);
				map[i][j] = 1;
				cout << 0 << " ";
				SetConsoleTextAttribute(hConsole, 7);
			}
			else if (map[i][j] == 2)
			{
				SetConsoleTextAttribute(hConsole, 204);
				cout << map[i][j] << " ";
				SetConsoleTextAttribute(hConsole, 7);
			}
			else if (map[i][j] == 1)
			{
				SetConsoleTextAttribute(hConsole, 136);
				cout << map[i][j] << " ";
				SetConsoleTextAttribute(hConsole, 7);
			}
			else
			{
				SetConsoleTextAttribute(hConsole, 34);
				cout << map[i][j] << " ";
				SetConsoleTextAttribute(hConsole, 7);
			}
		}cout << endl;
	}
}


int CountArea()
{
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0) cnt++;
		}
	}
	
	return cnt;
}

void ResetMap()
{
	memset(virus_visited, false, sizeof(virus_visited));
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			map[i][j] = origin_map[i][j];	
		}
	}
}

void BFS(int y, int x)
{
	queue < pair <int, int> > q;
	
	virus_visited[y][x] = true;
	q.push(make_pair(y, x));
	
	while (!q.empty())
	{
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int ny = yy + dY[i];
			int nx = xx + dX[i];
			
			if (0<= ny && ny < N && 0 <= nx && nx < M && !virus_visited[ny][nx] && map[ny][nx] == 0)
			{
				virus_visited[ny][nx] = true;
				q.push(make_pair(ny, nx));
				map[ny][nx] = 2;
			}
		}
	}
}

void ActivateVirus()
{
	ResetMap();
	
	int cnt = 0;
	for (int i = 0; i < wall.size(); i++)
	{
		if (cnt == 3) break;
		if (wall_visited[i] == true)
		{
			int wall_y = wall[i].first;
			int wall_x = wall[i].second;
				
			map[wall_y][wall_x] = 1;
			cnt++;
		}
	}
	
	printf("Built Wall!!\n"); 
	printMap();
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 2 && !virus_visited[i][j])
			{
				BFS(i, j);
			}
		}
	}
	
	int tmp = CountArea();
	answer = max(answer, tmp);
	
	printf("VIRUS!!!!\n"); 
	printMap();
}

void BuildWall(int idx, int cnt)
{
	if (cnt == 3)
	{
		ActivateVirus();
		return ;
	}
	
	for (int i = idx; i < wall.size(); i++)
	{
		if (wall_visited[i] == false)
		{
			wall_visited[i] = true;
			BuildWall(idx, cnt+1);
			wall_visited[i] = false;
		}
	}
}

void Solution()
{
	BuildWall(0, 0);
}

void Solve()
{
	Input();
	Solution();
	cout << answer << endl;
}

int main(void)
{
	Solve();
 	return 0;
}

