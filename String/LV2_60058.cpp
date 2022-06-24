#include <string>
#include <vector>
#include <iostream>

using namespace std;

string makeGoodstring(string w) {
    
    string result = "";
    
    // 1. 빈 문자열
    if (w == "") {
        return "";
    }
    
    
    // 2. 균형잡힌 문자열인지 검사
    string u = "", v = "";
    int i, temp = 0;
    for (i = 0; i < w.size(); i++) {
        w[i] == '(' ? temp++ : temp--;
        if (temp == 0) break;
    }
    
    // 두 문자열 u, v를 분리
    u = w.substr(0, i+1);
    v = w.substr(i+1);
    
    
    // 3. u는 올바른 문자열
    if (u.front() == '(') {
        
        // v에 대해 재귀적 수행 후 반환
        result = u + makeGoodstring(v);
    }
    
    // 4. u는 올바른 문자열이 아님
    else {
        result = '(' + makeGoodstring(v) + ')';
        
        // 4-4. 앞뒤 자르고 나머지 뒤집어 붙히기
        string uu = "";
        for (int i = 1; i < u.size()-1; i++) {
            u[i] == '(' ? uu += ')' : uu += '(';
        }
        
        result += uu;
    }

    // 결과 반환
    return result;
}

string solution(string p) {
    string answer = "";
    
    answer = makeGoodstring(p);
    
    return answer;
}
