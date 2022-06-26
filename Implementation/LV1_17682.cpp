#include <string>
#include <iostream>
#include <cmath>
#include <map>
#include <vector>

using namespace std;

// 5:40 ~ 6:03 (23)

int solution(string dartResult) {
    int answer = 0;
    
    // 점수를 저장할 벡터
    vector <int> score(3);
    
    // 보너스 map
    map <char, int> bonus_map = {{'S', 1}, {'D', 2}, {'T', 3}};
    
    int idx = 0;
    while (idx < dartResult.size()) {
        int num;
        char bonus, option = '-';
        
        // 점수 추출
        string num_str;
        while (isdigit(dartResult[idx])) {
            num_str.push_back(dartResult[idx++]);
        }
        num = stoi(num_str);
        
        // 보너스 추출
        bonus = dartResult[idx++];
        
        // 방금 얻은 점수
        int this_score = pow(num, bonus_map[bonus]);
        
        // 옵션이 있다면 추출
        if (!isdigit(dartResult[idx])) {
            option = dartResult[idx++];
            
            if (option == '*' && !score.empty()) {
                score.back() *= 2;
                this_score *= 2;
            }
            
            else if (option == '#') {
                this_score *= -1;
            }
        }
        
        // 점수 저장
        score.push_back(this_score);
    }
    
    // 점수 합산
    for (auto sc : score) {
        answer += sc;
    }
    
    return answer;
}
