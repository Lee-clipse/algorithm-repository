#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

const int maxN = 45;

int n;

ll dp[maxN+1];

void Input()
{
	cin >> n;
	memset(dp, 0, sizeof(dp));
}

void Solution()
{
	dp[1] = 1;
	
	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i-1] + dp[i-2];
	}
	
	cout << dp[n];
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

