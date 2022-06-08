#include <iostream>

using namespace std;

typedef unsigned long long ull;

int A, B, C;

void a(){int a=0;for(int i=0;i<40000000000;i++)a=i*i;}

ull func (int n, int m) {
	if (m == 1) return n;
	
	if (m%2 == 1) return func(n, m-1) * n % C;
	
	ull half = func(n, m/2) % C;
	return (half * half) % C;
}

int main () {
	cin >> A >> B >> C;
	
	cout << func(A, B) % C;
	
	a();
	return 0;
}
