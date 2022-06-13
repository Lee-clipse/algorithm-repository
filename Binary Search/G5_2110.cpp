#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

const int maxN = 200010;

int N, C;
int arr[maxN];

bool isPossible(int space) {
    int cnt = 1;
    int prev = arr[0];
    for (int i = 1; i < N; i++) {
        if (arr[i] - prev >= space) {
            prev = arr[i];
            cnt++;
        }
    }

    /* machine == C or over */
    if (cnt >= C) {
        return true;
    }
    /* too wide */
    return false;
}

int main() {
	fastio;
    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    /* for binary search */
    sort(arr, arr+N);

    /* standard: distance of houses */
    int lo = 0, hi = arr[N-1] - arr[0], mid;
    int ans = 0;
    while (lo <= hi) {
        mid = (lo + hi) / 2;

        /* can install machine */
        if (isPossible(mid)) {
            ans = max(ans, mid);
            lo = mid + 1;
        }
        /* too wide to install */
        else {
            hi = mid - 1;
        }
    }

    cout << ans << "\n";
}