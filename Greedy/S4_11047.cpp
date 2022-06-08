#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 15;

int N, K;
int arr[maxN];

void Input()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[N-i];
	} // start from [1]
}

void Solution()
{
	int ans = 0;
	int k = K;
	
	for (int i = 1; i <= N; i++)
	{
		if (arr[i] <= k)
		{
			int cnt = k/arr[i];
			k -= cnt*arr[i];
			ans += cnt;
		}
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

