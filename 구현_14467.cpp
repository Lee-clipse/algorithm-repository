#include <iostream>
#include <cstring>

using namespace std;

void a(){int a=0;for(int i=0;i<4000000000;i++)a=i*i;}

int N;
int arr[11];
// start from 1

void Solve ()
{
	memset(arr, -1, sizeof(arr));
	
	int cnt = 0;
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int n, p;
		cin >> n >> p;
		
		if (arr[n] == -1)
		{
			arr[n] = p;
		}
		
		if (arr[n] != p)
		{
			cnt++;
			arr[n] = p;
		}
	}
	
	cout << cnt << endl;
}

int main ()
{
	Solve();
	
	a();
	return 0;
}
