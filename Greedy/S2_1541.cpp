#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    string str; cin >> str;
    int str_size = str.size();
    int sum = 0, num = 0;
    int idx = 0;
    for (int i = 0; i < str_size; i++) {
        if ('0' <= str[i] && str[i] <= '9') {
            num *= 10; 
            num += (str[i] - '0');
        } 
        else {
            sum += num;
            num = 0;
            if (str[i] == '-') {
                idx = i+1;
                break;
            } 
        }
    }
    if (num != 0) {
        sum += num;
        num = 0;
    }
    if (idx == 0) {
        cout << sum << "\n";
        return 0;
    }
    for (int i = idx; i < str_size; i++) {
        if ('0' <= str[i] && str[i] <= '9') {
            num *= 10; num += (str[i] - '0');
        }
        else {
            sum -= num;
            num = 0;
        }
    }
    if (num != 0) {
        sum -= num;
    }
 
    cout << sum << "\n";
}