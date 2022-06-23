#include <string>
#include <vector>
#include <iostream>

// 12:55 ~ 13:40 (45)

using namespace std;

int getCompressLength(string str, int slice) {
    
    // <자른 문자, 중복 수> 를 저장할 배열
    vector < pair<string, int> > board;
    
    int i = 0;
    while (i < str.size()) {
        
        // 자른 문자열
        string s;
        
        // 범위 내에서 자르기
        if (i + slice <= str.size()) {
            s = str.substr(i, slice);
        }
        
        // 범위 밖이라면 그냥 붙이기
        else {
            s = str.substr(i);
        }
        
        
        // 신규 등록
        if (board.empty() || board.back().first != s) {
            board.push_back({s, 1});
        }
        
        // 중복이라면 +1
        else {
            board.back().second += 1;
        }
        
        // 다음 인덱스 이동
        i += slice;
    }
    
    // 압축한 문자열의 길이
    string compressed_str = "";
    
    for (auto b : board) {
        compressed_str += b.first;
        
        // 중복이 두 자리, 세 자리까지 가능하기 때문에 string을 안전하게 만든다
        if (b.second > 1) {
            compressed_str += to_string(b.second);    
        }
    }
    
    return compressed_str.size();
}

using namespace std;

int solution(string s) {
    int answer = 1001;
    
    // 문자열을 i개 단위로 잘라 가장 짧은 길이 추출
    for (int i = 1; i <= s.size() / 2 + 1; i++) {
        answer = min(answer, getCompressLength(s, i));  
    }
    
    return answer;
}
