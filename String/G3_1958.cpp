#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

const int maxN = 100;

string str1, str2, str3;
string tmp1, tmp2, tmp3;

int dp[maxN+1][maxN+1][maxN+1];

void Input ()
{
    memset(dp, 0, sizeof(dp));

    cin >> tmp1 >> tmp2 >> tmp3;
}

void Solution ()
{
    // core difference
    // start from 0
    str1 = '0' + tmp1;
    str2 = '0' + tmp2;
    str3 = '0' + tmp3;

    int len1 = str1.size();
    int len2 = str2.size();
    int len3 = str3.size();

    for (int i = 1; i < len1; i++)
    {
        for (int j = 1; j < len2; j++)
        {
            for (int k = 1; k < len3; k++)
            {
                if (str1[i] == str2[j] && str2[j] == str3[k])
                {
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                }

                else
                {
                    dp[i][j][k] = max(dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1]));
                }
            }
        }
    }

    int z = len1-1;
    int y = len2-1;
    int x = len3-1;

    while (dp[z][y][x] != 0)
    {
        if (dp[z][y][x] == dp[z][y][x-1])
        {
            x--;
        }

        else if (dp[z][y][x] == dp[z][y-1][x])
        {
            y--;
        }

        else if (dp[z][y][x] == dp[z-1][y][x])
        {
            z--;
        }

        else if (dp[z][y][x] - 1 == dp[z-1][y-1][x-1])
        {
            z--;
            y--;
            x--;
        }
    }

    int lcs = dp[len1-1][len2-1][len3-1];
    cout << lcs << endl;
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
