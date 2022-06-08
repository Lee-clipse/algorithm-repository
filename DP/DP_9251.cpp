#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

const int maxN = 1000;

string str1, str2;
string tmp1, tmp2;

int dp[maxN+1][maxN+1];

void Input ()
{
    memset(dp, 0, sizeof(dp));

    cin >> tmp1 >> tmp2;
}

void Solution ()
{
    // core difference
    // start from 0
    str1 = '0' + tmp1;
    str2 = '0' + tmp2;

    int len1 = str1.size();
    int len2 = str2.size();

    for (int i = 1; i < len1; i++)
    {
        for (int j = 1; j < len2; j++)
        {
            if (str1[i] == str2[j])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int y = len1-1;
    int x = len2-1;

    // reverse input
    stack <int> s;

    while (dp[y][x] != 0)
    {

        if (dp[y][x] == dp[y][x-1])
        {
            x--;
        }

        else if (dp[y][x] == dp[y-1][x])
        {
            y--;
        }

        else if (dp[y][x] - 1 == dp[y-1][x-1])
        {
            s.push(y);
            y--;
            x--;
        }
    }

    cout << dp[len1-1][len2-1] << endl;

    /*
    while (!s.empty())
    {
        cout << str1[s.top()];
        s.pop();
    }
    */
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
