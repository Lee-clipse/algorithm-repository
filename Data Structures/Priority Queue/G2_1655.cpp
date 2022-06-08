#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    int N; cin >> N;
    priority_queue <int> PQ1;
    priority_queue <int, vector<int>, greater<int>> PQ2;

    while (N--) {
        int num; cin >> num;
        if (PQ1.size() > PQ2.size()) PQ2.push(num);
        else PQ1.push(num);
        if (PQ1.size() && PQ2.size() && PQ1.top() > PQ2.top()) {
            int a = PQ1.top(); 
            PQ1.pop(); PQ1.push(PQ2.top()); 
            PQ2.pop(); PQ2.push(a);
        }
        cout << PQ1.top() << "\n";
    }
}