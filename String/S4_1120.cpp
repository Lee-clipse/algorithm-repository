#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    string str1, str2;
    cin >> str1 >> str2;

    int answer = 51;
    for (int i = 0; i <= str2.size() - str1.size(); i++) {
        int cnt = 0;
        for (int j = 0; j < str1.size(); j++) {
            if (str1[j] != str2[i+j]) {
                cnt++;
            }
        }
        answer = min(answer, cnt);
    }
    cout << answer << "\n";
}