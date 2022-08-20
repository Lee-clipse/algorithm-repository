#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int N, K;
int arr[100001];

int main() {
	fastio;
    cin >> N >> K;

	int answer = -100001;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		arr[i] += arr[i-1];
	}
	for (int i = K; i <= N; i++) {
		answer = max(answer, arr[i] - arr[i-K]);
	}
	cout << answer << "\n";
}