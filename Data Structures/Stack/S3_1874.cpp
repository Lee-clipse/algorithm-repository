#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

const int maxN = 100010;

int N;

int arr[maxN];

string ans;

int main(void)
{
	fastio;
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	
	stack <int> S; S.push(0);
	int a_idx = 0, s_idx = 1;
	while (a_idx != N)
	{
		cout << arr[a_idx] << ", " << S.top() << "\n";
		if (arr[a_idx] > S.top())
		{
			S.push(s_idx++);
			ans += "+\n";
		}
		else if (arr[a_idx] == S.top())
		{
			S.pop();
			ans += "-\n";
			a_idx++;
		}
		else if (arr[a_idx] < S.top())
		{
			ans = "NO\n";
			break;
		}
	}
	cout << ans;
	
 	return 0;
}

