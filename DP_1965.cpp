#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int dp[1010];
int arr[1010];

int main() {
	fastio;
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        dp[i] = 1;
    }
    
    int ans = 1;
    dp[0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if (arr[i] < arr[j]) {
                dp[j] = max(dp[j], dp[i]+1);
            }
        }
        ans = max(ans, dp[i]);
    }
	
    cout << ans << "\n";
}