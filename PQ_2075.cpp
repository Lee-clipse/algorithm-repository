#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;

priority_queue < int, vector<int>, greater<int> > pq;

void Input()
{
	cin >> N;
}

void Solution()
{
	int x;
	for (int i = 1; i <= N*N; i++)
	{
		scanf("%d", &x);
		pq.push(x);
		
		if (pq.size() > N)
		{
			pq.pop();
		}
	}
	
	cout << pq.top();
}

void Solve()
{
	Input();
	Solution();
}

int main(void)
{
	Solve();
 	return 0;
}

