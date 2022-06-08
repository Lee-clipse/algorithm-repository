#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    int N; cin >> N;
    
    int paper[1010];
    for (int i = 1; i <= N; i++) cin >> paper[i];

	deque <int> DQ;
    for (int i = 1; i <= N; i++) DQ.push_back(i);

    cout << DQ.front() << " ";
    int next = paper[DQ.front()];
    DQ.pop_front();
    while (!DQ.empty()) {
        int k = abs(next) - 1;
        while (k--) {
            if (next > 0) DQ.push_back(DQ.front()), DQ.pop_front();
            else DQ.push_front(DQ.back()), DQ.pop_back();
        }
        if (next > 0) {
            cout << DQ.front() << " ";
            next = paper[DQ.front()];
            DQ.pop_front();
        } else {
            cout << DQ.back() << " ";
            next = paper[DQ.back()];
            DQ.pop_back();
        }
    }
}