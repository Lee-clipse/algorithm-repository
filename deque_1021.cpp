#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
	int N, M; cin >> N >> M;
	
	deque <int> DQ;
	for (int i = 1; i <= N; i++) DQ.push_back(i);
	
	int ans = 0;
	for (int i = 0; i < M; i++) {
		int find; cin >> find;
		int cnt = 0;
		while (DQ.front() != find) {
			int t = DQ.front();
			DQ.push_back(t); DQ.pop_front();
			cnt++;
		}
		ans += min<int>(cnt, DQ.size() - cnt);
		DQ.pop_front();
	}
	cout << ans << "\n";
	
}

