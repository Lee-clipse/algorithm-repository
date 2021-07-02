#include <iostream>

using namespace std;

void a(){int a=0;for(int i=0;i<4000000000;i++)a=i*i;}

int main ()
{
	int arr[31] = {0, };
	
	for (int i = 1; i <= 28; i++)
	{
		int n;
		cin >> n;
		arr[n] = 1;
	}
	
	for (int i = 1; i <= 30; i++)
	{
		if (arr[i] == 0)
		{
			printf("%d\n", i);
		}
	}
	
	a();
	return 0;
}

