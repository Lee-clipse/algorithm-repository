#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

// 09:03 ~ 09:19

const int maxN = 105;

int N, T;

vector<int> S(maxN);

void OffOnOff(int act, int pos) {
    if (act == 1) {
        for (int i = pos; i <= N; i++) {
            if (i % pos == 0) {
                S[i] ^= 1;
            }
        }
    }
    else {
        int left = pos-1, right = pos+1;
        while (1 <= left && right <= N) {
            if (S[left] != S[right]) {
                break;
            }
            left--; right++;
        }
        for (int i = left+1; i <= right-1; i++) {
            S[i] ^= 1;
        }
    }
}

void print() {
    int idx = 1;
    for (int i = 0; i < N/20; i++) {
        for (int j = idx; j < idx+20; j++) {
            cout << S[j] << " ";
        } 
        cout << "\n";
        idx += 20;
    }

    for (int i = idx; i <= N; i++) {
        cout << S[i] << " ";
    }
}

int main() {
	fastio;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> S[i];
    }

    cin >> T;
    for (int i = 0; i < T; i++) {
        int act, pos;
        cin >> act >> pos;
        OffOnOff(act, pos);
    }

    print();
}