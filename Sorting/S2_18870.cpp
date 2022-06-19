#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

int main() {
	fastio;

    int N;
    cin >> N;

    // allocate size N
    vector<int> V(N);

    for (int i = 0; i < N; i++) {
        cin >> V[i];
    }

    // for copy of V
    vector <int> cV(V);

    // sort for erase duplicated one by using unique
    sort(cV.begin(), cV.end());

    // unique함수는 중복 인자를 뒤로 보내고, 그들의 첫 주소를 반환한다
    cV.erase(unique(cV.begin(), cV.end()), cV.end());

    for (int i = 0; i < N; i++) {

        // cV에서 V[i]를 찾아 것보다 작은 원소 수를 카운팅
        auto it = lower_bound(cV.begin(), cV.end(), V[i]);

        cout << it - cV.begin() << " ";
    }
    
}