#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

deque<int> Gear[4];
bool visited[4];

void Rotate(int pos, int dir) {
    int left = Gear[pos][6];
    int right = Gear[pos][2];

    if (dir == -1) {
        int tmp = Gear[pos].front();
        Gear[pos].pop_front();
        Gear[pos].push_back(tmp);
    } else if (dir == 1) {
        int tmp = Gear[pos].back();
        Gear[pos].pop_back();
        Gear[pos].push_front(tmp);
    }

    visited[pos] = true;

    if (pos-1 >= 0 && !visited[pos-1]) {
        if (left ^ Gear[pos-1][2] == 1) {
            Rotate(pos-1, -1*dir);
        }
    }

    if (pos+1 <= 3 && !visited[pos+1]) {
        if (right ^ Gear[pos+1][6] == 1) {
            Rotate(pos+1, -1*dir);
        }
    }
}

int main() {
	fastio;
    for (int i = 0; i < 4; i++) {
        string str; cin >> str;
        for (int j = 0; j < str.size(); j++) {
            Gear[i].push_back(str[j] - '0');
        }
    }

    int K; cin >> K;
    for (int i = 0; i < K; i++) {
        int pos, dir; cin >> pos >> dir;
        Rotate(pos-1, dir);
        memset(visited, 0, sizeof(visited));
    }

    int answer = 0;
    for (int i = 0; i < 4; i++) {
        answer += (Gear[i].front() * (pow(2, i)));
        answer >> 1;
    }

    cout << answer << "\n";
}