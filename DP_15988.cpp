#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 1000000;

const int MOD = 1000000009;

int T;
long long dp[maxN+1];

void Input()
{
	scanf("%d", &T);
}

void Solution()
{
	int *arr = new int[T+1];

	int mymax = -1;
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &arr[i]);
		mymax = max(mymax, arr[i]);
	}
	
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	
	for (int i = 3; i <= mymax; i++)
	{
		dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]);
	}
	
	for (int i = 0; i < T; i++)
	{
		printf("%ld\n", dp[arr[i]] % MOD);
	}
	
	delete[] arr;
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

