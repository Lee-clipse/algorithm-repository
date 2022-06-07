#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

/* 07:52 ~ 08:11 */

const int maxN = 13;

int N;
long arr[maxN];
int oper[4];

long max_ans = -1000000001;
long min_ans = 1000000001;

void makeFormula(int pos, long sum) {
    if (pos == N) {
        max_ans = max(max_ans, sum);
        min_ans = min(min_ans, sum);
        return ;
    }

    for (int i = 0; i < 4; i++) {
        if (oper[i] > 0) {
            oper[i]--;
            switch (i) {
            case 0:
                makeFormula(pos+1, sum + arr[pos]);
                break;
            
            case 1:
                makeFormula(pos+1, sum - arr[pos]);
                break;

            case 2:
                makeFormula(pos+1, sum * arr[pos]);
                break;

            case 3:
                makeFormula(pos+1, sum / arr[pos]);
                break;
            }
            oper[i]++;
        }
    }
}

int main() {
	fastio;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    for (int i = 0; i < 4; i++) {
        cin >> oper[i];
    }

    makeFormula(1, arr[0]);

    cout << max_ans << "\n" << min_ans << "\n";
}