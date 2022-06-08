#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int N;

bool isVPS(string str)
{
	stack <int> s;

	int size = str.size();
	for (int i = 0; i < size; i++)
	{
		if (str[i] == '(') s.push(1);
		if (str[i] == ')') 
		{
			if (s.empty()) return 0;
			s.pop();
		}
	}
	
	if (!s.empty()) return 0;
	else return 1;
}

int main(void)
{
	fastio;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		if (isVPS(str)) cout << "YES\n";
		else cout << "NO\n";
	}
 	return 0;
}

