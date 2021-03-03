#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void a () {int a=0;for(int i=0;i<4000000000;i++)a=i*i;}

int arr[9];
int sum = 0;

void input () {
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr, arr+9);
}

void func () {
	for (int i = 0; i < 8; i++) {
		for (int j = i+1; j < 9; j++) {
			if (sum - arr[i] - arr[j] == 100) {
				
				for (int k = 0; k < 9; k++) {
					if (k != i && k != j) cout << arr[k] << "\n";
				}
				return ;
			}
		}
	}
}

int main () {
	input();
	func();
	
	a();
	return 0;
}
