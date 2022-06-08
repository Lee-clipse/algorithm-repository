#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair <int, int> p;

int N;
vector<p> v;

bool cmp(p a, p b)
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
	
	int f, s;
	for (int i = 0; i < N; i++)
	{
		cin >> f >> s;
		v.push_back({f, s});
	}
	
	sort(v.begin(), v.end(), cmp);
}

void Solution()
{
	int cnt = 0;
	p now = make_pair(0, 0);
	
	for (int i = 0; i < N; i++)
	{
		if (now.second <= v[i].first)
		{
			now = v[i];
			cnt++;
			cout << now.first << " ~ " << now.second << endl;
		}
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

