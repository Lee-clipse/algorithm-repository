#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

const int maxN = 1000;
const ll mod = 1000000000;

int N, K;
ll dp[maxN+1][maxN+1];

void Input ()
{
    memset(dp, -1, sizeof(dp));
    cin >> N >> K;
}

ll func (int times, int got)
{
    ll& ret = dp[times][got];

    if (times == N+K-1)
    {
        return (got == K-1);
    }

    if (ret != -1)
    {
        return ret;
    }

    ret = (func(times+1, got+1) + func(times+1, got)) % mod;

    return ret;
}

void Solution ()
{
    cout << func(0, 0) << endl;
}

void Solve ()
{
    Input();
    Solution();
}

int main ()
{
    Solve();

    return 0;
}
