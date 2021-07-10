#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 1000;
const int MOD  = 10007;

int N, K;
int dp[maxN+1][maxN+1];

void Input ()
{
    memset(dp, 0, sizeof(dp));

    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        dp[i][0] = 1;
        dp[i][i] = 1;
    }
}

void Solution ()
{
    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j < i; j++)
        {
            dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % MOD;
        }
    }

    cout << dp[N][K] << endl;
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
