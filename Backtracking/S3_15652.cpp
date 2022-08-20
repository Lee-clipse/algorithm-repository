#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

// 3:00 ~ 3:02

using namespace std;

int N, M;
int arr[9];

void permutation(int pos, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) cout << arr[i] << " ";
		cout << "\n";
		return ;
	}

	for (int i = pos; i <= N; i++) {
		arr[cnt] = i;
		permutation(i, cnt+1);
	}
}

int main() {
	fastio;
    cin >> N >> M;
	permutation(1, 0);
}