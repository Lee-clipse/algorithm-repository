#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

void a(){int a=0;for(int i=0;i<40000000000;i++)a=i*i;}

const int maxN = 50;
const int maxK = 26;

// 단어 저장배열 
string str[maxN];

// 알파벳과 1대1 대응, 방문 여부 체크 
bool visited[maxK];

// 중복 제외하고 만들어지는 글자 테이블 
string tbl;
bool visited_dfs[maxK];

// 단어 개수의 최대값 
int myMax = -1;	

int N, K;

// OK
// 전처리 수행 
void Preprocessing () {	 
	string my_tbl = "acint";
	
	// "anta", "tica" 중복 글자 전부 제거
	for (int i = 0; i < N; i++) {
		cin >> str[i];
		
		for (int j = 0; j < my_tbl.size(); j++) {
			str[i].erase(remove(str[i].begin(), str[i].end(), my_tbl[j]), str[i].end());
		} // OK
		
		for (string::iterator iter = str[i].begin(); iter != str[i].end(); ++iter) {
			visited[*iter - 'a'] = true;
		} // OK
	}
	
	// 나머지 글자들 중복 없이 쓸어담아 테이블 만들기 tbl 
	for (int i = 0; i < maxK; i++) {
		if (visited[i] == true) 
			tbl.push_back(i + 'a');
	} // OK
}

// tbl 위에서 배울 수 있는 글자를 다 배웠을 때 가능한 단어 개수 출력 
int learnWord () {
	int cnt = 0;
	
	string letters;
	for (int i = 0; i < maxK; i++) {
		if (visited_dfs[i] == true) {
			letters.push_back(tbl[i]);
		}
	}
	
	// 지금까지 배운 글자들로 이 단어를 배울 수 있는지 판단 
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
	// tbl 위의 글자 수 보다 배울 수 있는 글자 수가 더 많을 경우 
	if (tbl.size() <= K-5) {
		myMax = N;
		return ;
	}
	
	// tbl 위에서 배울 수 있는 글자를 다 배웠을 때
	// 배울 수 있는 단어 개수 출력 
	if (cnt == K-5) {
		int tmp = learnWord();
		if (tmp > myMax) myMax = tmp;
		
		return ;
	}
	
	// tbl 위에서 dfs 
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
	
	// 과감한 return 으로 코드 구조를 깔끔하게 만드는 테크닉 
	if (K < 5) {
		cout << 0 << endl;
		return 0;
	}
	if (K == 26) {
		cout << N << endl;
		return 0;
	}
	
	// DFS 전에 전처리를 수행 
	Preprocessing();
	
	DFS(0, 0);
	
	cout << myMax;
	
	
	a();
	return 0;
}
