#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main(void)
{
	fastio;
	int N; cin >> N;
	
	queue <int> Q;
	
	int t = 1;
	while (t <= N) Q.push(t++);
	
	while(Q.size() != 1)
	{
		Q.pop();
		int n = Q.front(); cout << n << " ";
		Q.pop();
		Q.push(n);
	}
	cout << Q.front() << "\n";
	
 	return 0;
}

