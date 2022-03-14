#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
	int N, K, M;
    cin >> N >> K >> M;

    deque <int> DQ;
    for (int i = 1; i <= N; i++) DQ.push_back(i);

    int flip = 1;
    int flip_count = 0;
    while (!DQ.empty()) {
        if (flip_count == M) flip *= -1, flip_count = 0;

        int k = K-1;
        while (k--) {
            if (flip == 1) {
                int t = DQ.front();
                DQ.push_back(t); DQ.pop_front();
            } else {
                int t = DQ.back();
                DQ.push_front(t); DQ.pop_back();
            }
        }
        if (flip == 1) {
            cout << DQ.front() << "\n";
            DQ.pop_front();
        } else {
            cout << DQ.back() << "\n";
            DQ.pop_back();
        }
        flip_count++;
    }
}

