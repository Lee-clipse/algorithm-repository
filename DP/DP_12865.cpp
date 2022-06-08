#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 100;
const int maxK = 100000;

int N, K, W, V;
int w[maxN+1];
int v[maxN+1];
int dp[maxN+1][maxK+1];

void Input ()
{
    memset(dp, 0, sizeof(dp));

    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> w[i] >> v[i];
    }
}

void Solution ()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            if (w[i] > j)
            {
                dp[i][j] = dp[i-1][j];
            }

            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            cout << dp[i][j] << " ";
        } cout << "\n";
    }
    cout << dp[N][K] << endl;
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
