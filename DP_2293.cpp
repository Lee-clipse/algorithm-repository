#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 100;
const int maxK = 10000;

int N, K;
int val[maxN+1];
long dp[maxK+1];

void Input()
{
	cin >> N >> K;
	memset(dp, 0, sizeof(dp));
	
	for (int i = 0; i < N; i++)
	{
		cin >> val[i];
	}
	// val[], dp[] start from 0
}


void m()
{
	for (int i = 0; i <= K; i++)
	{
		cout << dp[i] << " ";
	}
}


void Solution()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			int p = j - val[i];
			
			long sum = 0;
			
			if (p == 0)
			{
				sum = 1;
			}
			
			if (p > 0)
			{
				sum += dp[p];
			}
			
			dp[j] += sum;
		}
	}
	
	cout << dp[K] << endl;
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

