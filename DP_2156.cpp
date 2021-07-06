#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 10000;

int N;
int val[maxN+1];
int dp[maxN+1];

void Input ()
{
    memset(dp, -1, sizeof(dp));
    memset(val, 0, sizeof(val));

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> val[i];
    }
}

void Solution ()
{
    dp[1] = val[1];
    dp[2] = dp[1] + val[2];
    for (int i = 3; i <= N; i++)
    {
        dp[i] = max(val[i] + val[i-1] + dp[i-3],
                max(val[i] + dp[i-2], dp[i-1]));
    }

    cout << dp[N];
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
