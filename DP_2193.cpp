#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 90;

int N;
long long dp[maxN+1][2];

void Input ()
{
    cin >> N;
    memset(dp, 0, sizeof(dp));
}

void Solution ()
{
    dp[1][1] = 1;
    for (int i = 2; i <= N; i++)
    {
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }

    cout << dp[N][0] + dp[N][1];
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
