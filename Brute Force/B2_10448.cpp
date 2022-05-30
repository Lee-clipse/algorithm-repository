#include <iostream>

using namespace std;

int triNum[50];
int arr[50][50][50];

void a(){int a=0;for(int i=0;i<4000000000;i++)a=i*i;}

void setting () {
	for (int i = 1; i < 50; i++) triNum[i] = i*(i+1)/2;
	
	for (int i = 1; i < 50; i++) {
		for (int j = 1; j < 50; j++) {
			for (int k = 1; k < 50; k++) {
				arr[i][j][k] = triNum[i] + triNum[j] + triNum[k];
			}
		}
	}	
}

int isEureka (int num) {
	for (int i = 1; i < 50; i++) {
		for (int j = 1; j < 50; j++) {
			for (int k = 1; k < 50; k++) {
				if (arr[i][j][k] == num) return 1;
			}
		}
	}
	return 0;
}

int main () {
	int T, K;
	setting();

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> K;
		cout << isEureka(K) << "\n";
	}
	
	a();
	return 0;
}
