#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

void Hanoi(int n, int s, int e, int o) {
    if (n == 1) {
        cout << s << " " << e << "\n";
        return ;
    }

    Hanoi(n-1, s, o, e);
    cout << s << " " << e << "\n";
    Hanoi(n-1, o, e, s);
}

int main() {
	fastio;
    int N; cin >> N;
    int arr[21];
    arr[1] = 1;
    for (int i = 2; i <= N; i++) {
        arr[i] = arr[i-1]*2 + 1;
    }
    cout << arr[N] << "\n";
    Hanoi(N, 1, 3, 2);
}