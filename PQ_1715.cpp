#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;

priority_queue < int, vector<int>, greater<int> > pq;

void Input()
{
	scanf("%d", &N);
	
	int x;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &x);
		pq.push(x);
	}
}

void Solution()
{
	int sum = 0;
	
	for (int i = 1; i < N; i++)
	{
		int pack1 = pq.top(); pq.pop();
		int pack2 = pq.top(); pq.pop();
		sum += (pack1 + pack2);
		pq.push((pack1 + pack2));
	}
	
	cout << sum;
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

