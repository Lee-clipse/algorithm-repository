#include <iostream>

using namespace std;

const int maxN = 20;

int N, S;
int count = 0;
int arr[maxN]; // start from 0

void a(){int a=0;for(int i=0;i<4000000000;i++)a=i*i;}

void func (int pos, int sum) {
	// 일단 더한다 
	sum += arr[pos];
	
	// 종료 조건 
	if (pos >= N) return ;
	// 만족 조건시 전역변수 count++ 
	if (sum == S) count++;
	
	
	
	// 해당 숫자를 더하지 않았을 경우 
	func(pos+1, sum-arr[pos]);
	// 해당 숫자를 더했을 경우 
	func(pos+1, sum);
}

int main () {
	cin >> N >> S;
	for (int i = 0; i < N; i++) cin >> arr[i];
	
	func(0, 0);
	cout << count;
	
	a();
	return 0;
}
