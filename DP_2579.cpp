#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int dp[3][303];
int arr[303];

int main() {
	fastio;
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        dp[1][i] = dp[2][i] = arr[i];
    }

    dp[2][0] = 0;
    for (int i = 0; i < N; i++) {
        dp[1][i+2] = max(dp[1][i+2], dp[1][i] + arr[i+2]);
        dp[2][i+1] = max(dp[2][i+1], dp[1][i] + arr[i+1]);
        dp[1][i+2] = max(dp[1][i+2], dp[2][i] + arr[i+2]);
    }



    cout << max(dp[1][N-1], dp[2][N-1]);
}