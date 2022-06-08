#include <iostream>

using namespace std;

const int maxN = 64;

int N;
int arr[maxN][maxN];

void a(){int a=0;for(int i=0;i<4000000000;i++)a=i*i;}

bool isAll (int x, int y, int size) {
	if (size == 1) return true;
	
	int p = arr[x][y];
	for (int i = x; i < x+size; i++)	{
		for (int j = y; j < y+size; j++) {
			if (p != arr[i][j]) return false;
			p = arr[i][j];
		}
	}
	return true;
} //SUCCESS

void func (int x, int y, int size) {
	int p = arr[x][y];
	
	// Base case || Satisfied case
	if (size == 1 || isAll(x, y, size) == true) {
		cout << p;
		return ;
	}
	
	cout << "(";
	
	int h = size/2;
	
	func (x, y, h);
	func (x, y+h, h);
	func (x+h, y, h);
	func (x+h, y+h, h);
	
	cout << ")";
}

int main () {
	cin >> N;
	for (int i = 0; i < N; i++)	{
		string s;
		cin >> s;
		
		for (int j = 0; j < N; j++) arr[i][j] = s[j] - '0';
	}
	
	func(0, 0, N);

	a();
	return 0;
}
