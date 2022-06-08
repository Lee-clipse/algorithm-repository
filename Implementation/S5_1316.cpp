#include <iostream>
#include <cstring>

using namespace std;

void a(){int a=0;for(int i=0;i<4000000000;i++)a=i*i;}

int N;
int alpha[26] = {0, };

bool Check (string str)
{
	char prev = str[0];
	string str_;
	
	str_ += prev;
	
	for (int i = 0; i < str.size(); i++)
	{
		if (prev != str[i])
		{
			str_ += str[i];
		}
		prev = str[i];
	}
	
	memset(alpha, 0, sizeof(alpha));
	
	for (int i = 0; i < str_.size(); i++)
	{
		if (alpha[str_[i] - 'a'] != true)
		{
			alpha[str_[i] - 'a'] = true;
		}
		else
		{
			return false;
		}
	}
	
	return true;
}


void Solution ()
{
	int myAns = 0;
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		
		myAns += Check(str);
		
		memset(alpha, 0, sizeof(alpha));
	}
	
	cout << myAns << endl;
}

int main ()
{
	Solution();
	
	a();	
	return 0;
} 
