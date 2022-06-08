#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
const int maxN = 51;
string candy[maxN];

void a(){int a=0;for(int i=0;i<4000000000;i++)a=i*i;}

void input () {
	cin >> N;
	for (int i = 0; i < N; i++) 
		cin >> candy[i];
	
}

int Bomboni () {
	int result = 1;
	
	for (int i = 0; i < N; i++) {
		int tmp = 1;
			
		for (int j = 0; j < N-1; j++) {
			if (candy[i][j] == candy[i][j+1]) {
				tmp++;
			}
			else {
				result = max(result, tmp);
				tmp = 1;
			}
		}
		result = max(result, tmp);
	}
	
	for (int i = 0; i < N; i++) {
		int tmp	= 1;
		
		for (int j = 0; j < N-1; j++) {
			if (candy[j][i] == candy[j+1][i]) {
				tmp++;
			}
			else {
				result = max(result, tmp);
				tmp = 1;
			}
		}
		result = max(result, tmp);
	}
	
	return result;
} // sucess


int main () {
	input();
	
	int maxSum = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N-1; j++) {
			swap(candy[i][j], candy[i][j+1]);
			maxSum = max(maxSum, Bomboni());
			swap(candy[i][j], candy[i][j+1]);
			
			swap(candy[j][i], candy[j+1][i]);
			maxSum = max(maxSum, Bomboni());
			swap(candy[j][i], candy[j+1][i]);
		}
	}

	cout << maxSum;

	a();
	return 0;
}
