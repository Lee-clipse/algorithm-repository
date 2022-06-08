#include <iostream>

void a(){int a=0;for(int i=0;i<4000000000;i++)a=i*i;}

using namespace std;

int N;

void Input()
{
	cin >> N;
}

int Solution()
{
	if (N%400 == 0)
	{
		return 1;
	}
	if (N%100 == 0)
	{
		return 0;
	}
	if (N%4 == 0)
	{
		return 1;
	}
	return 0;
}

void Solve()
{
	int myAns = 0;
	
	Input();
	myAns = Solution();
	
	cout << myAns;
}

int main()
{
	Solve();
	
	a();
	return 0;
}
