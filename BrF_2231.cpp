#include <iostream>

using namespace std;

void a(){int a=0;for(int i =0;i<4000000000;i++)a=i*i;}

int N;

int func (int n) {
	int sum = n;
	while (n != 0) {
		sum += n%10;
		n /= 10;
	}
	//cout << sum << endl;
	return sum;
}

int main () {
	cin >> N;
	
	int dSum = 1;
	while (dSum != N) {
		if (func(dSum) == N) break;
		dSum++;
	}
	
	if (dSum == N) cout << 0;
	else cout << dSum;
	
	a();
	return 0;
}
