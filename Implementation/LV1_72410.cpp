#include <bits/stdc++.h>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    // 1 단계
    // tolower(char): 대문자 -> 소문자
    string temp = "";
    for (auto c : new_id) {
        temp += tolower(c);
    }
    new_id = temp;
    
    
    // 2 단계
    // isalpha(char): 알파벳 범위인지 검사
    // isdigit(char): 숫자 범위인지 검사
    // strchr(A, B): A에서 B를 찾고 있으면 B반환, 없으면 NULL 반환
    temp = "";
    for (auto c : new_id) {
        if (isalpha(c) || isdigit(c) || strchr("-_.", c)) {
            temp += c;
        }
    }
    new_id = temp;
    
    
    // 3 단계
    // 특정 문자 중복 제거 테크닉
    // 지금 보는게 '.'이고, 방금 temp에 넣은게 '.'이면 continue로 패스
    temp = "";
    for (auto c : new_id) {
        if (c == '.' && temp.back() == '.') {
            continue;
        }
        temp += c;
    }
    new_id = temp;
    
    
    // 4 단계
    // string == vector
    if (new_id.front() == '.') {
        new_id.erase(0, 1);
    }
    if (new_id.back() == '.') {
        new_id.pop_back();
    }
    
    
    // 5 단계
    if (new_id.empty()) {
        new_id = "a";
    }
    
    
    // 6 단계
    if (new_id.size() >= 16) {
        new_id.erase(new_id.begin()+15, new_id.end());
    }
    if (new_id.back() == '.') {
        new_id.pop_back();
    }
    
    
    // 7 단계
    while (new_id.size() < 3) {
        new_id.push_back(new_id.back());
    }
    
    
    answer = new_id;
    return answer;
}
