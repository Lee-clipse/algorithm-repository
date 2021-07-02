#include <iostream>

using namespace std;

void a(){int a=0;for(int i=0;i<4000000000;i++)a=i*i;}

const int maxN = 999;
// start from (0, 0)

int N, k;
int arr[maxN][maxN] = {0, };

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void Solution()
{
	cin >> N >> k;
	
	int num = 1;
	int p = 2;
	int d = 0;
	int y = N/2; int x = N/2;
	
	arr[y][x] = num++;
	
	while (N*N - num > 0)
	{
		for (int i = 0; i < p/2; i++)
		{
			y += dy[d]; x += dx[d];
			
			if (y<0 || x<0)
			{
				break;
			}
			arr[y][x] = num++;
		}
		
		d = (d+1)%4;
		p++;
	}
}

void Output()
{
	int y, x;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == k)
			{
				y = i+1; x= j+1;
			}
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	
	cout << y << " " << x << endl;
}

void Solve()
{
	Solution();
	Output();
}

int main ()
{
	Solve();
	
	a();	
	return 0;	
} 
