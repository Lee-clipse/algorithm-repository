#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 100000;

int T, N;
int val[2][maxN+1];
int dp[maxN+1][3];

void Input ()
{
    memset(dp, -1, sizeof(dp));

    cin >> N;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> val[i][j];
        }
    }
}

int func (int pos, int state)
{
    int& ret = dp[pos][state];

    if (pos == N)
    {
        return 0;
    }

    if (ret != -1)
    {
        return ret;
    }

    ret = max(ret, func(pos+1, 2));

    if (state != 0)
    {
        ret = max(ret, func(pos+1, 0) + val[0][pos+1]);
    }

    if (state != 1)
    {
        ret = max(ret, func(pos+1, 1) + val[1][pos+1]);
    }

    return ret;
}

void Solution ()
{
    cout << func(0, 2) << endl;
}

void Solve ()
{
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        Input();
        Solution();
    }
}

int main ()
{
    Solve();

    return 0;
}
