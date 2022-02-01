#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 100000;
const int MODN = 9901;

typedef unsigned long long ull;

int N;
ull dp[maxN+1][2];

void Input()
{
	cin >> N;
	memset(dp, 0, sizeof(dp));
}

void Solution()
{
	dp[0][0] = 1;
	dp[0][1] = 1;
	
	for (int i = 1; i <= N; i++)
	{
		dp[i][0] = (dp[i-1][0] + dp[i-1][1] * 2) % MODN;
		dp[i][1] = (dp[i-1][0] + dp[i-1][1]) % MODN;
	}
	
	cout << dp[N][0];
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

