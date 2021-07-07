#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 1000;

int N;
int arr[maxN+1];
int dpL[maxN+1];
int dpR[maxN+1];

void Input ()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        dpL[i] = dpR[i] = 1;
    }
}

void getIncrease ()
{
    dpL[1] = 1;
    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                dpL[i] = max(dpL[i], dpL[j] + 1);
            }
        }
    }
}

void getDecrease ()
{
    dpR[1] = 1;
    for (int i = N; i > 0; i--)
    {
        for (int j = N; j > i; j--)
        {
            if (arr[j] < arr[i])
            {
                dpR[i] = max(dpR[i], dpR[j] + 1);
            }
        }
    }
}

void Solution ()
{
    getIncrease();
    getDecrease();

    int myans = 0;
    for (int i = 1; i <= N; i++)
    {
        myans = max(myans, dpL[i] + dpR[i]);
    }

    cout << myans-1 << endl;
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
