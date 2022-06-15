#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

const int maxN = 10010;

int coin[maxN];
int dp[maxN];

int main() {
	fastio;
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> coin[i];
        }

        int M;
        cin >> M;

        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 0; i < N; i++) {
            for (int j = 1; j <= M; j++) {
                if (j >= coin[i]) {
                    dp[j] += dp[j - coin[i]];
                }
            }
        }

        cout << dp[M] << "\n";
    }
}