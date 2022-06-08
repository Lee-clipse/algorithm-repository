#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

void a(){int a=0;for(int i=0;i<4000000000;i++)a=i*i;}

// start from (0, 0)
const int maxN = 50;

int N, M;
int map[maxN][maxN];
int num[maxN][maxN];
bool visited[maxN][maxN];

vector <int> room;
int maxRoomSize = 0;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

// OK
void Input() 
{
	memset(visited, 0, sizeof(visited));
	memset(num, 0, sizeof(num));
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}
	room.push_back(0);
}

// room numbering with mark
// OK
int BFS (int y, int x, int mark)
{
	queue < pair<int, int> > q;
	
	visited[y][x] = true;
	num[y][x] = mark;
	q.push({y, x});
	
	int cnt = 1;
	while (!q.empty())
	{
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int ny = yy + dy[i];
			int nx = xx + dx[i];
			
			if (0<=ny && ny<M && 0<=nx && nx<N && !visited[ny][nx]) // is infield? && is unvisited?
			{
				// USE BRACKET SRICTLY!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
				// check wall in current square
				if ((map[yy][xx] & (1 << i)) == 0) // is not wall?
				{
					visited[ny][nx] = true;
					num[ny][nx] = mark;
					q.push({ny, nx});
					cnt++;
				}
			}
		}
	}
	return cnt;
}

// OK
void Knock (int arr[], int mark)
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (num[i][j] == mark)
			{
				for (int k = 0; k < 4; k++)
				{
					int ny = i + dy[k];
					int nx = j + dx[k];
					
					if (0<=ny && ny<M && 0<=nx && nx<N)
					{
						// check wall in current square (i, j)
						if (((map[i][j]) & (1 << k)) != 0)
						{
							arr[num[ny][nx]] = 1;
						}	
					}
					
				}
			}
		}
	}
}

void Solution ()
{
	int cnt = 1;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j])
			{
				int room_size = BFS(i, j, cnt);
				cnt++;
				room.push_back(room_size);
			}
		}
	}
	
	// number of rooms can over maxN
	int next_room[maxN*maxN+1] = {0, };
	for (int i = 1; i <= room.size(); i++)
	{
		// knock number 'i' room's wall
		Knock(next_room, i);
		
		next_room[i] = 0;
		for (int j = 1; j <= room.size(); j++)
		{
			if (next_room[j] == 1)
			{
				int tmp = room[i] + room[j];
				if (maxRoomSize < tmp)
				{
					maxRoomSize = tmp;
				}
			}
		}
		memset(next_room, 0, sizeof(next_room));
	}
}

void Output ()
{
	// 1
	cout << room.size()-1 << endl;
	
	// 2
	cout << *max_element(room.begin(), room.end()) << endl;
	
	//3
	cout << maxRoomSize;
}

void Solve ()
{
	Input();
	Solution();
	Output();
}

int main () 
{
	Solve();
	
	a();
	return 0;
}
