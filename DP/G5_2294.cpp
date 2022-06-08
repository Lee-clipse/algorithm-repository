#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 100;
const int maxK = 10000;
const int NAN = 100001;

int N, K;
int dp[maxK+1];
int coin[maxN+1];

void Input ()
{
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> coin[i];
    }

    for (int i = 1; i <= K; i++)
    {
        dp[i] = NAN;
    }
}

void Solution ()
{
    dp[0] = 0;
    for (int i = 1; i <= K; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int tmp = i - coin[j];

            if (tmp >= 0)
            {
                if (dp[tmp] != -1)
                {
                    dp[i] = min(dp[i], dp[tmp] + 1);
                }
            }
        }
    }

    if (dp[K] == NAN)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dp[K] << endl;
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
