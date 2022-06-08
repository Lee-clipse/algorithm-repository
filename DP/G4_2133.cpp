#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 30;

int N;
int dp[maxN+1];

void Input ()
{
    memset(dp, 0, sizeof(dp));
    cin >> N;
}

void Solution ()
{
    dp[0] = 1;
    for (int i = 2; i <= N; i+=2)
    {
        int sum = 0;
        for (int j = 0; j <= i-4; j+=2)
        {
            sum += dp[j];
        }

        dp[i] = 3*dp[i-2] + 2*sum;
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
