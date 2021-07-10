#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;

const int maxN = 100;

string S;
int N;
string A[maxN+1];
int dp[maxN+1];

void Input ()
{
    memset(dp, -1, sizeof(dp));

    cin >> S >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
}

bool func (int pos)
{
    int& ret = dp[pos];

    if (ret != -1)
    {
        return ret;
    }

    if (pos == S.size())
    {
        return true;
    }

    for (int i = 0; i < N; i++)
    {
        if (S.size() < A[i].size() + pos)
        {
            continue;
        }

        bool flag = false;
        for (int j = 0; j < A[i].size(); j++)
        {
            if (A[i][j] != S[j+pos])
            {
                flag = true;
                break;
            }
        }

        if (!flag)
        {
            ret = ret | func(pos+A[i].size());
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
