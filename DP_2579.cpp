#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 300;

int N;
int arr[maxN+1];
int dp[maxN+1];

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
    dp[1] = arr[1];
    dp[2] = dp[1] + arr[2];

    for (int i = 3; i <= N; i++)
    {
        dp[i] = max(dp[i-3] + arr[i-1] + arr[i],
                    dp[i-2] + arr[i]);
    }

    cout << dp[N] << endl;
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
