#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

void a(){int a;for(int i=0;i<4000000000;i++)a=i*i;}

const int minNum = -1000;
const int maxN = 100001;

int main () {
	int n;
	int arr[maxN];
	int dp[maxN];
	cin >> n;
	memset(dp, 0, sizeof(dp));
	
	int sum = minNum;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i] = arr[i] + dp[i-1];
		if (dp[i] < arr[i]) dp[i] = arr[i];
		
		if (sum < dp[i]) sum = dp[i];
	}
	
	cout << sum;
		
	a();
	return 0;
}
