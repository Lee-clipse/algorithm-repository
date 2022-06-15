#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

typedef long long ll;

const int maxN = 1000010;

int T, N, M;
int A[maxN], B[maxN];
vector <ll> VA, VB;

int main() {
	fastio;
    cin >> T;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }

    for (int i = 0; i < N; i++) {
        ll num = A[i];
        int size = VA.size();
        for (int j = 0; j < i; j++) {
            VA.push_back(VA[size+j - i] + num);
        }
        VA.push_back(num);
    }

    for (int i = 0; i < M; i++) {
        ll num = B[i];
        int size = VB.size();
        for (int j = 0; j < i; j++) {
            VB.push_back(VB[size+j - i] + num);
        }
        VB.push_back(num);
    }

    sort(VA.begin(), VA.end());
    sort(VB.begin(), VB.end());
    
    ll answer = 0;
    for (int i = 0; i < VA.size(); i++) {
        int high = upper_bound(VB.begin(), VB.end(), T - VA[i]) - VB.begin();
        int low  = lower_bound(VB.begin(), VB.end(), T - VA[i]) - VB.begin();
        
        answer += (high - low);
    }

    cout << answer << "\n";
}