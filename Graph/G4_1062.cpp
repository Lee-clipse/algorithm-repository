#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

void a(){int a=0;for(int i=0;i<40000000000;i++)a=i*i;}

const int maxN = 50;
const int maxK = 26;

// �ܾ� ����迭 
string str[maxN];

// ���ĺ��� 1��1 ����, �湮 ���� üũ 
bool visited[maxK];

// �ߺ� �����ϰ� ��������� ���� ���̺� 
string tbl;
bool visited_dfs[maxK];

// �ܾ� ������ �ִ밪 
int myMax = -1;	

int N, K;

// OK
// ��ó�� ���� 
void Preprocessing () {	 
	string my_tbl = "acint";
	
	// "anta", "tica" �ߺ� ���� ���� ����
	for (int i = 0; i < N; i++) {
		cin >> str[i];
		
		for (int j = 0; j < my_tbl.size(); j++) {
			str[i].erase(remove(str[i].begin(), str[i].end(), my_tbl[j]), str[i].end());
		} // OK
		
		for (string::iterator iter = str[i].begin(); iter != str[i].end(); ++iter) {
			visited[*iter - 'a'] = true;
		} // OK
	}
	
	// ������ ���ڵ� �ߺ� ���� ������ ���̺� ����� tbl 
	for (int i = 0; i < maxK; i++) {
		if (visited[i] == true) 
			tbl.push_back(i + 'a');
	} // OK
}

// tbl ������ ��� �� �ִ� ���ڸ� �� ����� �� ������ �ܾ� ���� ��� 
int learnWord () {
	int cnt = 0;
	
	string letters;
	for (int i = 0; i < maxK; i++) {
		if (visited_dfs[i] == true) {
			letters.push_back(tbl[i]);
		}
	}
	
	// ���ݱ��� ��� ���ڵ�� �� �ܾ ��� �� �ִ��� �Ǵ� 
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
	// tbl ���� ���� �� ���� ��� �� �ִ� ���� ���� �� ���� ��� 
	if (tbl.size() <= K-5) {
		myMax = N;
		return ;
	}
	
	// tbl ������ ��� �� �ִ� ���ڸ� �� ����� ��
	// ��� �� �ִ� �ܾ� ���� ��� 
	if (cnt == K-5) {
		int tmp = learnWord();
		if (tmp > myMax) myMax = tmp;
		
		return ;
	}
	
	// tbl ������ dfs 
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
	
	// ������ return ���� �ڵ� ������ ����ϰ� ����� ��ũ�� 
	if (K < 5) {
		cout << 0 << endl;
		return 0;
	}
	if (K == 26) {
		cout << N << endl;
		return 0;
	}
	
	// DFS ���� ��ó���� ���� 
	Preprocessing();
	
	DFS(0, 0);
	
	cout << myMax;
	
	
	a();
	return 0;
}
