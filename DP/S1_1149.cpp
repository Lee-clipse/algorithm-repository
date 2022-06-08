#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 1000;
const int INF  = 10000000;

int N;

int dp[maxN+1][4];
int cost[maxN+1][3];
// start from 0 to N-1

void Input ()
{
    memset(dp, -1, sizeof(dp));

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> cost[i][j];
        }
    }
}

int func (int pos, int prev = 3)
{
    int& ret = dp[pos][prev];

    if (ret != -1)
    {
        return ret;
    }

    if (pos == N)
    {
        return 0;
    }

    ret = INF;

    for (int i = 0; i < 3; i++)
    {
        if (i != prev)
        {
            ret = min(ret, func(pos+1, i) + cost[pos][i]);
        }
    }

    return ret;
}

void Solution ()
{
    cout << func(0);
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
