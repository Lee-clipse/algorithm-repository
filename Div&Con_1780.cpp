#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 2200;
const int falseNum = -9;

int N;
int arr[maxN][maxN];
int ans[3];

void Input()
{
	scanf("%d", &N);
	memset(ans, 0, sizeof(ans));
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	} // start from [1][1]
}

void Func(int y, int x, int len)
{
	if (len == 1)
	{
		ans[arr[y][x] + 1]++;
		return ;
	}
	
	int eql = arr[y][x];
	for (int i = y; i < len+y; i++)
	{
		for (int j = x; j < len+x; j++)
		{
			if (eql != arr[i][j])
			{
				eql = falseNum;
				break;
			}
		}
	}
	
	if (eql != falseNum)
	{
		ans[eql + 1]++;
		return ;
	} 
	else
	{
		int size = len/3;
		
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				Func(y + size*i, x + size*j, size);
			}
		}
	}
}

void Solution()
{
	Func(1, 1, N);
	
	for (int i = 0; i < 3; i++)
	{
		cout << ans[i] << endl;
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

