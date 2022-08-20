#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int N, M;
long long prefix_cnt[1010];

int main() {
	fastio;
    cin >> N >> M;
	long long sum = 0;
	for (int p, i = 0; i < N; i++) {
		cin >> p;
		sum += p;
		prefix_cnt[sum % M]++;
	}

	prefix_cnt[0]++;
	long long answer = 0;
	for (auto cnt : prefix_cnt) {
		answer += cnt * (cnt-1) / 2;
	}
	cout << answer << "\n";
}