#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

bool compare(string a, string b) {
    int i = 0;
    if (a.length() == b.length()) {
        for (int i = 0; i < a.length(); i++) {
            if (a[i] != b[i])
                return a[i] < b[i];
        }
    }
    return a.length() < b.length();
}

int main() {
    fastio;

    int num;
    cin >> num;

    vector<string> arr;
    for(int i = 0; i < num; i++) {
        string tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end(), compare);

    cout << arr[0] << '\n';
    for (int i = 1; i < num; i++) {
        if (arr[i-1] == arr[i])
            continue;
        cout << arr[i] << '\n';
    }
}