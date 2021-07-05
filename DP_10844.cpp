#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 100;
const int mod = 1000000000;

int N;
int dp[maxN+1][maxN+1];

typedef unsigned long long ull;

void Input ()
{
    memset(dp, 0, sizeof(dp));

    cin >> N;
    for (int i = 1; i <= 9; i++)
    {
        dp[1][i] = 1;
    }
}

void Solution ()
{
    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (j != 0) dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % mod;
            if (j != 9) dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % mod;
        }
    }

    ull sum = 0;
    for (int i = 0; i <= 9; i++)
    {
        sum = (sum + dp[N][i]) % mod;
    }

    cout << sum;
    return ;
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
