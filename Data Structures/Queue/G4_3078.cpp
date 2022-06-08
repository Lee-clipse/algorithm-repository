#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

queue <int> Q[21]; // lenÀÌ °°Àº idx³¢¸® queue 

int main() {
	fastio;
	int N, K; cin >> N >> K;
	
	long long ans = 0;
	for (int i = 1; i <= N; i++) {
		string str; cin >> str;
		int len = str.size();

		while (Q[len].size() && K < i - Q[len].front()) Q[len].pop();
		
		ans += Q[len].size();
		Q[len].push(i);
	}
	cout << ans << "\n";
}

