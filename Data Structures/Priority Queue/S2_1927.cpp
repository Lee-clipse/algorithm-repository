#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;

struct cmp
{
	bool operator()(int a, int b)
	{
		return a > b;
	}
};

void Input()
{
	cin >> N;
}

void Solution()
{
	priority_queue <int, vector<int>, cmp> pq;
	
	for (int i = 0; i < N; i++)
	{
		int x;
		scanf("%d", &x);
		
		if (x == 0)
		{
			if (pq.empty())
			{
				printf("0\n");
			}
			else
			{
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
		else
		{
			pq.push(x);
		}
	}
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

