#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

// 4:06 ~ 4:13

using namespace std;

int N, answer = 0;
int arr[16];
bool visited[16];


bool isSafe(int row, int col) {
	if (visited[col]) return false;
	for (int i = 1; i <= N; i++) {
		if (row - i == abs(col - arr[i])) {
			return false;
		}
	}
	return true;
}


void setQueen(int row, int cnt) {
	if (cnt == N) {
		answer++;
		return ;
	}

	for (int i = 1; i <= N; i++) {
		if (isSafe(row, i)) {
			visited[i] = true;
			arr[row] = i;
			setQueen(row+1, cnt+1);
			visited[i] = false;
			arr[row] = 0;
		}
	}
}


int main() {
	fastio;
    cin >> N;
	setQueen(1, 0);
	cout << answer << "\n";
}