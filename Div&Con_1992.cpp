#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 150;

int N;
int arr[maxN][maxN];
int ans[2];

void Input()
{
	scanf("%d", &N);
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}
}

bool isFilled(int y, int x, int len)
{
	int eql = arr[y][x];
	
	for (int i = y; i < len+y; i++)
	{
		for (int j = x; j < len+x; j++)
		{
			if (eql != arr[i][j])
			{
				return false;
			}
		}
	}
	
	return true;
}

void Func(int y, int x, int len)
{
	if (len == 1)
	{
		printf("%d", arr[y][x]);
		return ;
	}
	
	if (isFilled(y, x, len))
	{
		printf("%d", arr[y][x]);
	}
	else
	{
		int size = len/2;
		
		printf("(");
		
		Func(y, x, size);
		Func(y, x+size, size);
		Func(y+size, x, size);
		Func(y+size, x+size, size);
		
		printf(")");
	}
}

void Solution()
{
	Func(1, 1, N);
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

