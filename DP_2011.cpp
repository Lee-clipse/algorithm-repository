#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

const int MOD  = 1000000;
const int maxS = 5000;

string code;
ll dp[maxS];

void Input ()
{
    cin >> code;
}

void Setting ()
{
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= maxS; i++)
    {
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }
}

void Solution ()
{
    int cnt = 0, prev = 0;
    ll sum = 1;

    for (int i = 0; i < code.size(); i++)
    {
        int cur = code[i] - '0';

        if (cur == 0)
        {
            // 3
            if (prev == 1 || prev == 2)
            {
                sum = (sum * dp[cnt-1]) % MOD;
                cnt = -1;
            }

            // 4
            else
            {
                cout << 0 << endl;
                return ;
            }
        }

        // 1, 2
        if (prev*10 + cur > 26)
        {
            sum = (sum * dp[cnt]) % MOD;
            cnt = 0;
        }


        cnt++;
        prev = cur;
    }

    if (cnt >= 2)
    {
        sum = (sum * dp[cnt]) % MOD;
    }

    cout << sum << endl;
}

void Solve ()
{
    Input();
    Setting();
    Solution();
}

int main ()
{
    while (true)
    {
        Solve();
    }

    return 0;
}
