#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main()
{
	fastio;
	
	string str, bomb; 
	cin >> str >> bomb;
	
	string S; // stack
	int str_size = str.size();
	for (int i = 0; i < str_size; i++)
	{
		S.push_back(str[i]);
		while (S.size() >= bomb.size() && S.substr(S.size() - bomb.size(), bomb.size()) == bomb)
		{
			for (int j = 0; j < bomb.size(); j++) S.pop_back();
		}
	}
	
	cout << (S.empty() ? "FRULA" : S) << "\n";
}

