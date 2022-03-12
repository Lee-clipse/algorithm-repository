#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void)
{
	fastio;
	
	string line;
	cin >> line;
	
	int ans = 0;
	stack <char> S;
	
	int size = line.size();
	for (int i = 0; i < size; i++)
	{
		if (line[i] == '(') S.push('(');
		
		if (line[i] == ')')
		{
			if (line[i-1] == ')')
			{
				S.pop();
				ans++;
			}
			else if (S.top() == '(')
			{
				S.pop();
				ans += S.size();
			}
		}
	}
	cout << ans;
 	return 0;
}

