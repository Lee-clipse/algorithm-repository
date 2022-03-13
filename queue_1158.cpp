#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void) {
	fastio;
	int N, K; cin >> N >> K;
	
	queue <int> Q;
	for (int i = 1; i <= N; i++) Q.push(i);
	
	cout << "<";
	while (Q.size() > 1) {
		int cnt = 1;
		while (cnt < K) {
			int n = Q.front();
			Q.pop();
			Q.push(n);
			cnt++;
		}
		cout << Q.front() << ", ";
		Q.pop();
	}
	cout << Q.front() << ">\n";
	
 	return 0;
}

