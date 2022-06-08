#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 100;

typedef unsigned long long ull;

int N;
int val[maxN+1][maxN+1];
ull dp[maxN+1][maxN+1];

void Input()
{
	cin >> N;
	
	memset(val, 0, sizeof(val));
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> val[i][j];
		}
	}
	// start in (1, 1)
}

void map()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << dp[i][j] << " ";
		} cout << endl;
	}cout << endl;
}

void Solution()
{
	dp[1][1] = 1;
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (dp[i][j] != 0)
			{
				if (val[i][j] == 0)
				{
					continue;
				}

				if (i + val[i][j] <= N)
				{
					
					dp[i + val[i][j]][j] += dp[i][j];
				}
				if (j + val[i][j] <= N)
				{
					dp[i][j + val[i][j]] += dp[i][j];
				}
			}
		}
	}
	
	cout << dp[N][N];
}

void Solve()
{
	Input();
	Solution();
}

int main (void)
{
	Solve();
 	return 0;
}

