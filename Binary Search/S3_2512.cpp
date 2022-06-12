#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

const int maxN = 10010;

int N, M;
int arr[maxN];

int getBudget(int pos) {
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] <= pos) {
            ans += arr[i];
        }
        else {
            ans += pos;
        }
    }
    return ans;
} 

int main() {
	fastio;
    cin >> N;
    int max_val = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        max_val = max(max_val, arr[i]);
    }
    cin >> M;
    
    int ans, diff = 100000001;
    int lo = 0, hi = max_val, mid;
    while (lo <= hi) {
        mid = (lo + hi) / 2;

        int budget = getBudget(mid);
        if (budget > M) {
            hi = mid-1;
        } 
        else {
            lo = mid+1;
            if (diff > M - budget) {
                diff = M - budget;
                ans = mid;
            }
        }
    }

    cout << ans << "\n";
}