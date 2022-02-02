#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 15;
const int NAN  = -999999999;

int N;
int T[maxN+2];
int P[maxN+2];

int dp[maxN+2];

void Input()
{
	cin >> N;
	memset(dp, -1, sizeof(dp));

	for (int i = 1; i <= N; i++)
	{
		cin >> T[i] >> P[i];
	}

}


void map()
{
	for (int i = 1; i <= N; i++)
	{
		cout << dp[i] << " ";
	}
	cout << "\n*******************************\n\n";
}


int func(int pos)
{
	map();
	int& ret = dp[pos];
	
	if (pos == N+1)
	{
		return 0;
	}
	
	if (pos > N+1)
	{
		return NAN;
	}
	
	if (ret != -1)
	{
		return ret;
	}
	
	ret = max(func(pos + T[pos]) + P[pos], func(pos + 1));

	return ret;
}

void Solution()
{
	cout << func(1) << endl;
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

