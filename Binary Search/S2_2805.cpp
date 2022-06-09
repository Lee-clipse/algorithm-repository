#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

typedef unsigned long long ull;

const int maxN = 1000001;

int N, M;
int arr[maxN];

ull cutTree(int pos) {
    ull sum = 0;
    for (int i = N-1; i >= 0; i--) {
        if (pos < arr[i]) sum += (arr[i] - pos);
    }
    return sum;
}

int main() {
	fastio;
    int lo = 0, hi = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        hi = max(hi, arr[i]);
    }
    
    int ans;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        ull tree = cutTree(mid);

        if (M > tree) {
            hi = mid-1;
        }
        else {
            ans = mid;
            lo = mid+1;
        }
    }

    cout << ans << "\n";
}