#include <iostream>

using namespace std;

const int maxN = 2187;

int N;
int arr[maxN][maxN];

// [0]: -1 / [1]: 0 / [2]: 1
int paper[3] = {0, 0, 0};

void a(){int a=0;for(int i=0;i<4000000000;i++)a=i*i;}

bool isFull (int x, int y, int s) {
	if (s == 1) return true;
	
	int p = arr[x][y];
	
	// (i, j, x, y, s) need well control !!!
	for (int i = x; i < x+s; i++) {
		for (int j = y; j < y+s; j++) {
			if (p != arr[i][j]) return false;
			p = arr[i][j];
		}
	}
	return true;
} // SUCCESS

void func (int x, int y, int s) {
	// Satisfied || Base case
	if (isFull(x, y, s) == true || s == 1) {
		int num = arr[x][y];
		paper[num+1]++;
		return ;
	}
	
	int p = s/3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			//printf("(%d, %d) size %d in \n", x+i*p, y+j*p, p);
			func(x+i*p, y+j*p, p);
		}
	}
}

int main () {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	
	func(0, 0, N);
	
	for (int i = 0; i < 3; i++) cout << paper[i] << endl;	
	
	a();
	return 0;
}
