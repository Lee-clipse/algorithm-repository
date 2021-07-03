#include <iostream>

using namespace std;

void a(){int a=0;for(int i=0;i<4000000000;i++)a=i*i;}

const int N = 25;

int arr[N+1][N+1];
int call[N+1][N+1];
bool board[N+1][N+1] = {0, };
// start from (1, 1)

void Input()
{
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			cin >> arr[i][j];
		}
	}
	
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			cin >> call[i][j];
		}
	}
}

void CheckNum(int num)
{
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			if (arr[i][j] == num)
			{
				board[i][j] = true;
			}
		}
	}
}

int BingoBoard()
{
	int bingosign = 0;
	for (int i = 1; i <= 5; i++)
	{
		bool tmp1 = true, tmp2 = true;
		for (int j = 1; j <= 5; j++)
		{
			tmp1 &= board[i][j];
			tmp2 &= board[j][i];
		}
		
		bingosign += (tmp1 + tmp2);
	}
	
	bool tmp1 = true, tmp2 = true;
	for (int i = 1; i <= 5; i++)
	{
		tmp1 &= board[i][i];
		tmp2 &= board[i][6-i];
	}
	
	bingosign += (tmp1 + tmp2);
	
	return bingosign;
}

void Solution()
{
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			int num = call[i][j];
			CheckNum(num);
			
			if (BingoBoard() >= 3)
			{
				cout << 5*(i-1) + j << endl;
				return ;
			}
		}
	}
}

void Solve()
{
	Input();
	Solution();
}

int main()
{
	Solve();
	
	a();	
	return 0;
} 
