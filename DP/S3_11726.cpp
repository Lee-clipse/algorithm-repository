#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 1000;
const int mod = 10007;

int N;
int dp[maxN+1];

void Input ()
{
    cin >> N;
    memset(dp, -1, sizeof(dp));
}

int func (int x)
{
    int &ret = dp[x];

    if (x == 1 || x == 0)
    {
        return 1;
    }

    if (ret != -1)
    {
        return ret;
    }

    ret = (func(x-1) + func(x-2)) % mod;

    return ret;
}

void Solution ()
{
    cout << func(N);
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
