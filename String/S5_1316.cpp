#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int alpha[101];

bool isChecker(string str) {
	if (str.size() <= 2) {
		return 1;
	}

    alpha[str[0] - 'a'] = 1;
    for (int i = 1; i < str.size(); i++) {
		if (alpha[str[i] - 'a'] == 1 && str[i-1] != str[i]) {
            return 0;
        }
        alpha[str[i] - 'a'] = 1;
	}
	return 1;
} 

int main() {
	fastio;

	int N;
    cin >> N;

	int answer = 0;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		if (isChecker(str)) {
			answer++;
		}
		memset(alpha, 0, sizeof(alpha));
	}

	cout << answer << "\n";
}