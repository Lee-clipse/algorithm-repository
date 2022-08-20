#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

// 12:22 ~ 

using namespace std;

string S;
int Q;

// a:0 ~
int alpha_sum[26][200001];

int main() {
	fastio;
	cin >> S >> Q;
	memset(alpha_sum, 0, sizeof(alpha_sum));

	int size = S.size();
	for (int i = 0; i < size; i++) {
		alpha_sum[S[i] - 'a'][i] = 1;
	}

	for (int i = 0; i < 26; i++) {
		for (int j = 1; j < size; j++) {
			alpha_sum[i][j] += alpha_sum[i][j-1];
		}
	}

	char ch;
	int l, r;
	while (Q--) {
		cin >> ch >> l >> r;
		if (l == 0) {
			cout << alpha_sum[ch - 'a'][r] << "\n";
		} else {
			cout << alpha_sum[ch - 'a'][r] - alpha_sum[ch - 'a'][l-1] << "\n";
		}
	}
}