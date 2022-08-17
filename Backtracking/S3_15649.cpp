#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

// 2:25 ~ 

using namespace std;

int N, M;
int arr[9];
bool visited[9];

void permutation(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return ;
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			arr[cnt] = i;
			visited[i] = true;
			permutation(cnt+1);
			visited[i] = false;
		}
	}
}

int main() {
	fastio;
    cin >> N >> M;
	permutation(0);
}