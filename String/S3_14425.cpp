#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;

    set<string> set;
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        set.insert(str);
    }

    int count = 0;
    for (int i = 0; i < M; i++) {
        string str;
        cin >> str;
        if (set.find(str) != set.end()) {
            count++;
        }
    }

    cout << count << "\n";
}