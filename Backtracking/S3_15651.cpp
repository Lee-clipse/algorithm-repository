#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

// 2:56 ~ 2:58

using namespace std;

int N, M;
int arr[8];

void permutation(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) cout << arr[i] << " ";
		cout << "\n";
		return ;
	}

	for (int i = 1; i <= N; i++) {
		arr[cnt] = i;
		permutation(cnt+1);
	}
}

int main() {
	fastio;
    cin >> N >> M;
	permutation(0);
}