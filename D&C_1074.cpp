#include <iostream>
#include <cmath>

using namespace std;

const int maxN = 32768;

int N, R, C;

void a(){int a=0;for(int i=0;i<4000000000;i++)a=i*i;}

void func (int row, int col, int num, int size) {
	// Base case
	if (size == 1) {
		if (row == R && col == C){
			cout << num;
			return ;
		}
	}
	
	// jump term m 
	int m = size*size / 4;
	
	// half line index
	int half_row = row + size/2;
	int half_col = col + size/2;
	
	// find (R, C)'s quadrant and divide
	if (R >= half_row) {
		if (C >= half_col) func(half_row, half_col, num+3*m, size/2);
		else func(half_row, col, num+2*m, size/2);
	} else {
		if (C >= half_col) func(row, half_col, num+m, size/2);
		else func(row, col, num, size/2);
	}
}

int main () {
	cin >> N >> R >> C;
	
	func (0, 0, 0, pow(2, N));
	
	a();
	return 0;
}
