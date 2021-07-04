#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 1000000;

int N;
int dp[maxN+1];

int func (int n)
{
    int &ret = dp[n];

    if (n == 1 || n == 0)
    {
        return 0;
    }

    if (ret != -1)
    {
        return ret;
    }

    ret = func(n-1) + 1;

    if (n%3 == 0)
    {
        ret = min(ret, func(n/3) + 1);
    }

    if (n%2 == 0)
    {
        ret = min(ret, func(n/2) + 1);
    }

    return ret;
}

void Solve ()
{
    cin >> N;
    memset(dp, -1, sizeof(dp));

    cout << func(N);
}

int main ()
{
    Solve();

    return 0;
}
