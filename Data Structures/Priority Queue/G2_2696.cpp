#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;
    int T; cin >> T;

    priority_queue <int> PQ1;
    priority_queue <int, vector<int>, greater<int>> PQ2;

    while (T--) {
        int N; cin >> N;
        PQ1 = priority_queue<int>();
        PQ2 = priority_queue <int, vector<int>, greater<int>>();

        vector <int> middle;
        for (int i = 1; i <= N; i++) {
            int t; cin >> t;
            if (PQ1.size() > PQ2.size()) PQ2.push(t);
            else PQ1.push(t);
            
            if (PQ1.size() && PQ2.size() && PQ1.top() > PQ2.top()) {
                int p = PQ1.top();
                PQ1.pop(); PQ1.push(PQ2.top());
                PQ2.pop(); PQ2.push(p);
            }

            if (i%2 == 1) middle.push_back(PQ1.top());
        }

        cout << middle.size() << "\n";
        for (int i = 0; i < middle.size(); i++) {
            cout << middle[i] << " ";
            if ((i+1)%10 == 0) cout << "\n";
        }
        cout << "\n";
        middle.clear();
    }
}