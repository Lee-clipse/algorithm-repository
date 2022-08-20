#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

// 3:25 ~ 3:45

using namespace std;

int N;
int A[12];

int calc(vector<int> oper) {
	int result = A[0];
	for (int i = 1; i <= N; i++) {
		switch (oper[i-1]) {
		case 0:
			result += A[i];
			break;
		case 1:
			result -= A[i];
			break;
		case 2:
			result *= A[i];
			break;
		case 3:
			result /= A[i];
			break;
		}
	}
	return result;
}

int main() {
	fastio;
    cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	// (0: +), (1: -), (2: *), (3: %)
	vector<int> oper;
	for (int op, i = 0; i < 4; i++) {
		cin >> op;
		while (op--) oper.push_back(i);
	}
	
	int max_answer = -1000000000;
	int min_answer = 1000000000;
	do {
		int result = calc(oper);
		max_answer = max(max_answer, result);
		min_answer = min(min_answer, result);
	} while (next_permutation(oper.begin(), oper.end()));

	cout << max_answer << "\n" << min_answer << "\n";
}