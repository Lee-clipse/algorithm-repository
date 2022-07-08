#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

// 5:27 ~ 5:48 (21)

int L, C;
string origin;
vector <string> answer;

bool isPossible(string str) {
    int cnt = 0;
    for (int i = 0; i < L; i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            ++cnt;
        }
    }
    if (cnt < 1 || L-cnt < 2) {
        return false;
    }
    return true;
}

void DFS(int pos, string str) {
    // 인덱스가 끝까지 가거나 길이가 L이 되면 종료
    if (pos == C || str.size() == L) {
        if (isPossible(str)) {
            answer.push_back(str);
        }
        return ;
    }

    // 사전순이기 때문에 pos+1
    // pos, i 인덱스 취급 주의
    for (int i = pos+1; i < C; i++) {
        DFS(i, str + origin[i]);
    }
}

int main() {
	fastio;
    cin >> L >> C;

    for (int i = 0; i < C; i++) {
        char c;
        cin >> c;
        origin += c;
    }

    sort(origin.begin(), origin.end());

    for (int i = 0; i < C; i++) {
        DFS(i, origin.substr(i, 1));
    }

    for (auto ans : answer) {
        cout << ans << "\n";
    }
}