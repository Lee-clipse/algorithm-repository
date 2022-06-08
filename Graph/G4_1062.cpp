#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

void a(){int a=0;for(int i=0;i<40000000000;i++)a=i*i;}

const int maxN = 50;
const int maxK = 26;

string str[maxN];

bool visited[maxK];

string tbl;
bool visited_dfs[maxK];
int myMax = -1;	

int N, K;

// OK
void Preprocessing () {	 
	string my_tbl = "acint";
	
	for (int i = 0; i < N; i++) {
		cin >> str[i];
		
		for (int j = 0; j < my_tbl.size(); j++) {
			str[i].erase(remove(str[i].begin(), str[i].end(), my_tbl[j]), str[i].end());
		} // OK
		
		for (string::iterator iter = str[i].begin(); iter != str[i].end(); ++iter) {
			visited[*iter - 'a'] = true;
		} // OK
	}
	
	for (int i = 0; i < maxK; i++) {
		if (visited[i] == true) 
			tbl.push_back(i + 'a');
	} // OK
}

int learnWord () {
	int cnt = 0;
	
	string letters;
	for (int i = 0; i < maxK; i++) {
		if (visited_dfs[i] == true) {
			letters.push_back(tbl[i]);
		}
	}
	
	for (int i = 0; i < N; i++) {
		bool flag = true;
		for (string::iterator iter = str[i].begin(); iter != str[i].end(); ++iter) {
			if (letters.find(*iter) == string::npos) {
				flag = false;
				break;
			}
		}
		
		if (flag == true) cnt++;
	}
	
	return cnt;
} 

void DFS (int idx, int cnt) {
	if (tbl.size() <= K-5) {
		myMax = N;
		return ;
	}
	
	if (cnt == K-5) {
		int tmp = learnWord();
		if (tmp > myMax) myMax = tmp;
		
		return ;
	}
	
	for (int i = idx; i < tbl.size(); i++) {
		if (visited_dfs[i] == true) continue;
		visited_dfs[i] = true;
		
		DFS(i, cnt+1);
		visited_dfs[i] = false;
	}
	
}

int main () {
	cin >> N >> K;
	memset(visited, 0, sizeof(visited));
	
	if (K < 5) {
		cout << 0 << endl;
		return 0;
	}
	if (K == 26) {
		cout << N << endl;
		return 0;
	}
	
	Preprocessing();
	
	DFS(0, 0);
	
	cout << myMax;
	
	
	a();
	return 0;
}
