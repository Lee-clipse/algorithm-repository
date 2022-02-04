#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 40;

int N, M;

int val[maxN+3];
int dp[maxN+1];

void Input()
{
	scanf("%d %d", &N, &M);
	
	val[0] = 0;
	val[M+1] = N+1;
	
	for (int i = 1; i <= M; i++)
	{
		scanf("%d", &val[i]);
	}
}

void Solution()
{
	dp[0] = 1;
	dp[1] = 1;
	
	for (int i = 2; i <= maxN; i++)
	{
		dp[i] = dp[i-1] + dp[i-2];
	}
	
	long long ans = 1;
	for (int i = 1; i <= M+1; i++)
	{
		ans *= dp[val[i] - val[i-1] - 1];
	}
	
	cout << ans;
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

