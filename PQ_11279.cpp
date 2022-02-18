#include <iostream>
#include <queue>

using namespace std;

int N;

void Input()
{
	cin >> N;
}

void Solution()
{
	priority_queue <int> pq;
	
	while(N--)
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

