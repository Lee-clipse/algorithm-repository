#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

deque <int> parsing(const string& s) {
    // return 값이니까 변수명 ret
    deque<int> ret;

    // size()하면 마지막 ']'일 때 ret에 0이 들어가서 안됨
    for (int i = 1; i < s.size() - 1; i++) {
        int cur = 0;

        // if문이 아닌 while문으로 N자리 수일 경우 대비
        while (isdigit(s[i])) {
            cur = 10 * cur + s[i] - '0';
            i++;
        }
        ret.push_back(cur);
    }
    return ret;
}

void Print(const deque<int>& DQ) {
	cout << '[';
	for (int i = 0; i < DQ.size(); i++) {
		cout << DQ[i];
		if (i != DQ.size() - 1) cout << ',';
	}
	cout << ']' << '\n';
}

int main() {
	fastio;
	int N; cin >> N;
	while (N--) {
		string cmd, s; int n; cin >> cmd >> n >> s;

        // 함수 return 타입이 정해져있으니 auto로 선언
		auto DQ = parsing(s);

        // 이런건 int가 아니라 bool로 취급해주자
		bool rev = 0, flag = 0; //error flag
		for (auto& c : cmd) {
			if (c == 'R') rev ^= 1; // ^= 1 로 0과 1을 toggle
			else if (c == 'D') {
                // break로 빠지고 무언가 처리해야 한다면 flag로 남기자
                // 어차피 break 할거니까 else if 안에 넣어서 다같이 처리하는 판단
				if (DQ.empty()) { flag = 1; break; }
				if (!rev) DQ.pop_front();
				else DQ.pop_back();
			}
		}

		if (flag) cout << "error" << '\n';
		else {
            // 지금까진 뒤집은 척 했지만, 마지막 cmd가 'R'이라면 마지막에는 진짜 뒤집어야 함
			if (rev) reverse(DQ.begin(), DQ.end());
			Print(DQ);
		}
	}
}