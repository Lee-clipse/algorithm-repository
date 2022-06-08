#include <iostream>

using namespace std;

const int maxN = 100000;

int N, M;
int val[maxN+1];
int dp[maxN+1];

void Input()
{
	scanf("%d%d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &val[i]);
	}
	// val start from 1
}

void Solution()
{
	for (int i = 1; i <= N; i++)
	{
		dp[i] = dp[i-1] + val[i];
	}
	
	for (int i = 0; i < M; i++)
	{
		int beg, end;
		scanf("%d%d", &beg, &end);
		
		printf("%d\n", dp[end] - dp[beg-1]);		
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

