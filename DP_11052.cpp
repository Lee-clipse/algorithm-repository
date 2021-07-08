#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 1000;

int N, K;
int P[maxN+1];
int dp[maxN+1];

void Input ()
{
    memset(dp, -1, sizeof(dp));

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> P[i];
    }
}

int func (int K)
{
    int& ret = dp[K];

    if (K == N)
    {
        return 0;
    }

    if (ret != -1)
    {
        return ret;
    }

    for (int i = 1; i <= N; i++)
    {
        if (i > N-K)
        {
            break;
        }

        ret = max(ret, func(K+i) + P[i]);
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
