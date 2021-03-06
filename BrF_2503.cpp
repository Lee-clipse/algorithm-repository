#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

int N;
int arr[10][10][10];
int num[3];

void a(){int a=0;for(int i=0;i<4000000000;i++)a=i*i;}

void setting () {
	cin >> N;
	memset(arr, 0, sizeof(arr));
	
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			
			if (i == j) {
				for (int k = 1; k <= 9; k++) {
					arr[i][j][k] = -1;
				}
			} 
			
			else {
				for (int k = 1; k <= 9; k++) {
					if (i == k || j == k) {
						arr[i][j][k] = -1;
					}
				}
			}
			
		}
	}
} // SUCCESS

int main () {
	setting();
	
	for (int t = 0; t < N; t++) {
		int tmp;
		int s_count, b_count;
		cin >> tmp;
		num[0] = tmp/100;
		num[1] = (tmp/10)%10;
		num[2] = tmp%10;
		
		cin >> s_count >> b_count;
		
		int s, b;
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				for (int k = 1; k <= 9; k++) {
					
					if (arr[i][j][k] == t) {
						
						if (num[0] == i) s++;
						if (num[1] == j) s++;
						if (num[2] == k) s++;
						
						if (num[0] == j || num[0] == k) b++;
						if (num[1] == i || num[1] == k) b++;
						if (num[2] == i || num[2] == j) b++;
						
						if (b == b_count && s == s_count) {
							arr[i][j][k]++;
							//cout << i << j << k << endl;
						}
						
						b = 0; s = 0;
					}
					
				}
			}
		}
		
	}
	
	int cnt = 0;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			for (int k = 1; k <= 9; k++) {
				if (arr[i][j][k] == N) {
					cout << "*" <<i << j << k << endl;
					cnt++;
				}
			}
		}
	}
	
	cout << cnt;
	
	a();
	return 0;
}
