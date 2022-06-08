#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 1000000;
const int MOD  = 15746;

int N;
long long dp[maxN+1];

void Input ()
{
    memset(dp, 0, sizeof(dp));

    cin >> N;
}

void Solution ()
{
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= N; i++)
    {
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }

    cout << dp[N] << endl;
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
