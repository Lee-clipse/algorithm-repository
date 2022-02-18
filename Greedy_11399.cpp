#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;

int N;

vector <P> v;

bool cmp(P a, P b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	return a.second < b.second;
}

void Input()
{
	cin >> N;
	
	int p;
	for (int i = 1; i <= N; i++)
	{
		cin >> p;
		v.push_back({i, p});
	}
	
	sort(v.begin(), v.end(), cmp);
}

void Solution()
{
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += (v[i].second * (N - i));
	}
	
	cout << sum;
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

