#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

const int maxN = 100001;

int N;
int dp[maxN];

void Input ()
{
    memset(dp, 0, sizeof(dp));

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        dp[i] = i;
    }
}

void Solution ()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= sqrt(i); j++)
        {
            int jj = j*j;
/*
            if (jj > i)
            {
                break;
            }*/

            if (jj == N)
            {
                cout << 1;
                return ;
            }

            dp[i] = min(dp[i], dp[i-jj] + 1);
        }
    }
    cout << "*";
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
