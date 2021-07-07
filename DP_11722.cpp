#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 1000;

int N;
int dp[maxN+1];
int arr[maxN+1];

void Input ()
{
    memset(dp, 0, sizeof(dp));

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
}

void Solution ()
{
    dp[1] = 1;
    for (int i = 1; i <= N; i++)
    {
        int mymax = 0;
        for (int j = 1; j < i; j++)
        {
            if (arr[j] > arr[i])
            {
                mymax = max(dp[j], mymax);
            }
        }

        dp[i] = mymax + 1;
    }

    int ans = -1;
    for (int i = 1; i <= N; i++)
    {
        ans = max(ans, dp[i]);
    }

    cout << ans;
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
