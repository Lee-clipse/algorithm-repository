#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int num[10] = {0, };

int main() {
	fastio;
    string N;
    cin >> N;
    for (auto i : N) {
        num[i - '0']++;
    }

    if ((num[6] + num[9]) % 2) {
        num[6] = (num[6] + num[9]) / 2 + 1;
        num[9] = 0;
    }
    else {
        num[6] = (num[6] + num[9]) / 2;
        num[9] = 0;
    }
    
    int answer = 0;
    for (auto i : num) {
        answer = max(answer, i);
    }
    cout << answer << "\n";
}