#include <iostream>
#include <cstring>

using namespace std;

void a(){int a=0;for(int i=0;i<40000000000;i++)a=i*i;}

const int maxN = 11;

int T, N;
int dp[maxN];

int main () {
	cin >> T;
	memset(dp, 0, sizeof(dp));
	
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	
	for (int i = 4; i < maxN; i++) 
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
	
	for (int i = 0; i < T; i++) {
		cin >> N;
		cout << dp[N] << "\n";
	}
	
	a();
	return 0;
}
