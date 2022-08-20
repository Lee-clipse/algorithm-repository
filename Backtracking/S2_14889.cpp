#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

// 3:02 ~ 3:23

using namespace std;

const int maxN = 22;

int N, answer = 10000;
int team[maxN];
int status[maxN][maxN];


int getTeamScore(int flag) {
	int score = 0;
	for (int i = 1; i <= N; i++) {
		if (flag == team[i]) {
			for (int j = 1; j <= N; j++) {
				if (flag == team[j] && i != j) {
					score += status[i][j];
				}
			}
		}
	}
	return score;
}

void permutation(int pos, int cnt) {
	if (cnt == N/2) {
		answer = min(answer, abs(getTeamScore(1) - getTeamScore(0)));
		return ;
	}

	// 1010011 이면 팀 1 vs 팀 0
	for (int i = pos; i <= N; i++) {
		team[i] = 1;
		permutation(i+1, cnt+1);
		team[i] = 0;
	}
}


int main() {
	fastio;
    cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> status[i][j];
		}
	}
	// 1번 선수가 고정으로 들어감
	team[1] = 1;
	permutation(2, 1);

	cout << answer << "\n";
}