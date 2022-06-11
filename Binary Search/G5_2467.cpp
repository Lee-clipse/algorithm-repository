#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

const int maxN = 100010;

int N;
long arr[maxN];

int main() {
	fastio;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int left = 0, right = N-1;
    /* for safety */
    int val = abs(arr[left] + arr[right]);
    int res1 = left, res2 = right;

    while (left < right) {
        /* using two pointer instead of 'mid = (lo + hi) / 2' */
        int tmp = arr[left] + arr[right];
        if (abs(tmp) < val) {
            val = abs(tmp);
            res1 = left, res2 = right;
        }
        else if (tmp > 0) {
            right--;
        } else {
            left++;
        }
    }

    cout << arr[res1] << " " << arr[res2] << "\n";
}