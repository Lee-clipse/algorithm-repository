#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 1000;

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
        dp[i] = arr[i];
    }
}

void Solution ()
{
    int myans = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }

        myans = max(myans, dp[i]);
    }

    cout << myans << endl;
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
