#include <iostream>
#include <cstring>

using namespace std;

void a(){int a=0;for(int i=0;i<4000000000;i++)a=i*i;}

const int maxS = 100;

int S, N;
int arr[maxS+1];
// start from 1 

void Input ()
{
	cin >> S;
	for (int i = 1; i <= S; i++)
	{
		cin >> arr[i];
	}
	cin >> N;
}

void Change (int s, int p)
{
	if (s == 1)
	{
		int k = 1;
		
		while (p*k <= S)
		{
			arr[p*k] ^= 1;
			k++;
		}
	}

	if (s == 2)
	{
		int l = p, r = p;
		
		while (1<=l-1 && r+1<=S)
		{
			if (arr[l-1] != arr[r+1])
			{
				break;
			}
			l--; r++;
		}

		for (int i = l; i <= r; i++)
		{
			arr[i] ^= 1;
		}
	}
}

void Output ()
{
	int idx = 1;
	for (int i = 0; i < S/20; i++)
	{
		for (int j = idx; j < idx+20; j++)
		{
			cout << arr[j] << " ";
		}
		
		cout << "\n";
		idx += 20;
	}
	
	for (int i = idx; i <= S; i++)
	{
		cout << arr[i] << " ";
	}
}

void Solve ()
{
	Input();
	
	int s, p;
	for (int i = 0; i < N; i++)
	{
		cin >> s >> p;
		
		Change(s, p);
	}
	
	Output();
}

int main ()
{
	Solve();
	
	a();
	return 0;
}
