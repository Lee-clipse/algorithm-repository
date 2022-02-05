#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 1010;

int N, M;
int dp[maxN][maxN];

void Input()
{
	cin >> N >> M;
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%1d", &dp[i][j]);
		}
	}
}

void Solution()
{
	int ans = 0;
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (dp[i][j] != 0)
			{
				dp[i][j] = min(dp[i][j-1], min(dp[i-1][j-1], dp[i-1][j])) + 1;
				
				ans = max(ans, dp[i][j]);
			}
		}
	}
	
	cout << ans * ans << endl;
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

