#include <iostream>

using namespace std;

const int maxN = 20;

int N, S;
int count = 0;
int arr[maxN]; // start from 0

void a(){int a=0;for(int i=0;i<4000000000;i++)a=i*i;}

void func (int pos, int sum) {
	// �ϴ� ���Ѵ� 
	sum += arr[pos];
	
	// ���� ���� 
	if (pos >= N) return ;
	// ���� ���ǽ� �������� count++ 
	if (sum == S) count++;
	
	
	
	// �ش� ���ڸ� ������ �ʾ��� ��� 
	func(pos+1, sum-arr[pos]);
	// �ش� ���ڸ� ������ ��� 
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
