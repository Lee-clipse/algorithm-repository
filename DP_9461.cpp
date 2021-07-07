#include <iostream>
#include <cstring>

using namespace std;

typedef unsigned long long ull;

const int maxN = 30;

int T, N;
ull dp[maxN+1];

void Input ()
{
    memset(dp, 0, sizeof(dp));

    cin >> T;
}

void Solution ()
{
    dp[1] = dp[2] = dp[3] = 1;

    for (int i = 4; i <= 100; i++)
    {
        dp[i] = dp[i-2] + dp[i-3];
    }

    for (int i = 0; i < T; i++)
    {
        cin >> N;

        cout << dp[N] << endl;
    }

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
