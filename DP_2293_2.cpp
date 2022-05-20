#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int dp[10010];
int arr[101];

int main() {
	fastio;
    int N, K; cin >> N >> K;

    dp[0] = 1;
    for (int i = 0; i < N; i++) {
        int v; cin >> v;
        for (int j = 1; j <= K; j++) {
            if (j >= v) {
                dp[j] += dp[j-v];
            }
        }
    }

    cout << dp[K] << "\n";


}