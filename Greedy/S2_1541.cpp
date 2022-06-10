#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    string str; cin >> str;
    int str_size = str.size();
    int sum = 0, num = 0, sign = 0;
    for (int i = 0; i < str_size; i++) {
        if ('0' <= str[i] && str[i] <= '9') {
            num *= 10; 
            num += (str[i] - '0');
        } else {
            if (sign) {
                sum -= num;
            } else {
                sum += num;
                if (str[i] == '-') sign = 1;
            }
            num = 0;
        }
    }

    sign == 0 ? sum += num : sum -= num;

    cout << sum << "\n";
}