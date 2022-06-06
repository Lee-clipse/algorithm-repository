#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

const int maxN = 22;

int N;
int arr[maxN][maxN];
int visited[maxN];

int diff_team = INT16_MAX;

void getDiff() {
    // calc home, away (visited 0 , 1)
    int home_team = 0;
    int away_team = 0;

    for (int i = 1; i <= N; i++) {
        if (visited[i]) {
            for (int j = 1; j <= N; j++) {
                if (visited[j]) home_team += arr[i][j];
            }
        } else {
            for (int j = 1; j <= N; j++) {
                if (!visited[j]) away_team += arr[i][j];
            }
        }
    }

    diff_team = min(diff_team, abs(home_team - away_team));
}

void setTeam(int pos, int cnt) {
    if (cnt == N/2) {
        getDiff();
        return ;
    }

    if (pos > N) {
        return ;
    }

    // pick 
    visited[pos] = 1;
    setTeam(pos+1, cnt+1);
    visited[pos] = 0;

    // not pick 
    setTeam(pos+1, cnt);
}


int main() {
	fastio;
    cin >> N;
    /* [1][1] to [N][N] */
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }

    setTeam(1, 0);

    cout << diff_team << "\n";
}