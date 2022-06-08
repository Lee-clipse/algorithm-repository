#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int maxN = 100010;

int N, M;
int arr[maxN];

vector <int> MinTree;
vector <int> MaxTree;

void Input()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	int height = (int)ceil(log2(N));
    int size   = (1 << (height + 1));
    
    MinTree.resize(size);
    MaxTree.resize(size);
}

int makeMinTree(int node, int beg, int end)
{
    if (beg == end) 
	{
    	return MinTree[node] = arr[beg];
	}
	
    int mid = (beg + end) / 2;
    int left_res  = makeMinTree(node * 2, 	   beg,  	mid);
    int right_res = makeMinTree(node * 2 + 1, mid + 1, end);
    
    MinTree[node] = min(left_res, right_res);
 
    return MinTree[node];
}

int makeMaxTree(int node, int beg, int end)
{
    if (beg == end) 
	{
    	return MaxTree[node] = arr[beg];
	}
	
    int mid = (beg + end) / 2;
    int left_res  = makeMaxTree(node * 2, 	   beg,  	mid);
    int right_res = makeMaxTree(node * 2 + 1, mid + 1, end);
    
    MaxTree[node] = max(left_res, right_res);
 
    return MaxTree[node];
}

int getMinMax(int node, int beg, int end, int left, int right, int sign)
{
    if (left > end || right < beg) 
	{
		return 0;
	}
	
    if (left <= beg && end <= right)
	{
		if (sign == 0)
		{
			return MinTree[node];
		}	
		return MaxTree[node];
	} 
 
    int mid = (beg + end) / 2;
    int left_res  = getMinMax(node * 2,     beg, 	 mid, left, right, sign);
    int right_res = getMinMax(node * 2 + 1, mid + 1, end, left, right, sign);
    
    if (sign == 0)
	{
		if (left_res == 0)
		{
			return right_res;
		}
		
		else if (right_res == 0)
		{
			return left_res;
		}
		
		else
		{
			return min(left_res, right_res);
		}
	}	
	return max(left_res, right_res);
}

void Solution()
{
	makeMinTree(1, 0, N-1);
    makeMaxTree(1, 0, N-1);
    
	for (int i = 0; i < M; i++)
	{
		int beg, end;
		scanf("%d %d", &beg, &end);
		
		printf("%d %d\n", getMinMax(1, 0, N-1, beg-1, end-1, 0),
						  getMinMax(1, 0, N-1, beg-1, end-1, 1));
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
}


