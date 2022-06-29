#include <iostream>
#include <string>
#include <stack>

using namespace std;

// 12:03 ~ 12:31 (30)

int solution(string s) {
    int answer = -1;

    stack <char> S;
    S.push(s[0]);
    for (int i = 1; i < s.size(); i++) {
        if (!S.empty() && S.top() == s[i]) {
            S.pop();
        }
        else {
            S.push(s[i]);
        }
    }

    answer = S.empty();


    return answer;
}
