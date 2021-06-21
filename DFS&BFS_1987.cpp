#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

void a(){int a=0;for(int i=0;i<4000000000;i++)a=i*i;}

// start from (0, 0)
const int maxR = 20;

int R, C;
int myAns = 0;

// A: 0, B: 1 ... Z: 25;
// checking like visited[][]
bool alpha[26];
string map[maxR];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

// OK
void Input () 
{
	memset(alpha, 0, sizeof(alpha));
	
	
	cin >> R >> C;
	for (int i = 0; i < R; i++) 
	{
		cin >> map[i];
	}
}

void DFS (int y, int x, int cnt) 
{
	myAns = max(myAns, cnt);
		
	for (int i = 0; i < 4; i++) 
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if (0<=ny && ny<R && 0<=nx && nx<C) 
		{
			char c = map[ny][nx];
			
			if (!alpha[c - 'A']) 
			{
				alpha[c - 'A'] = true;
				DFS(ny, nx, cnt+1);
				alpha[c - 'A'] = false;
			}
		}
	}
}

void Solution () 
{
	alpha[map[0][0] - 'A'] = true;
	DFS(0, 0, 1);
	
	cout << myAns;
}

void Solve ()
{
	Input();
	Solution();	
}

int main () 
{
	Solve();	

	a();
	return 0;
}


