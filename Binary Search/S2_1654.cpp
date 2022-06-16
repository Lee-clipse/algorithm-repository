#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

typedef unsigned long long ull;

const int maxK = 10010;

int arr[maxK];

int main() {
	fastio;
    int K, N;
    cin >> K >> N;

    int max_len = 0;
    for (int i = 0; i < K; i++) {
        cin >> arr[i];
        max_len = max(max_len, arr[i]);
    }

    ull answer = 0;
    ull lo = 1, hi = max_len, mid;
    while (lo <= hi) {
        mid = (lo + hi) / 2;

        ull cut = 0;
        for (int i = 0; i < K; i++) {
            cut += (arr[i] / mid);
        }

        if (cut < N) {
            hi = mid - 1;
        } 
        else {
            lo = mid + 1;
            answer = max(answer, mid);
        }
    }
    
    cout << answer << "\n";
}