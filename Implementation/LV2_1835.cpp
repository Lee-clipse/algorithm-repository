#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 2:15 ~ 2:57 (42)

vector <string> row;

// 지금 이 줄이 규칙에 맞는지 검사 후 맞다면 1반환, 아니라면 0 반환
int isOk(string order) {
    
    // 인물 p1, p2라고 지칭
    string p1{order[0]}, p2{order[2]}, act{order[3]};
    int distance = order[4] - '0';
    
    // 두 인물의 인덱스 찾기
    auto it1 = find(row.begin(), row.end(), p1) - row.begin();
    auto it2 = find(row.begin(), row.end(), p2) - row.begin();
    
    // 둘 사이의 거리는 둘 사이의 사람 수이기 때문에 (거리 - 1)
    if (act == "=" && (abs(it2 - it1) - 1 == distance)) return 1;
    else if (act == "<" && (abs(it2 - it1) - 1 < distance)) return 1;
    else if (act == ">" && (abs(it2 - it1) - 1 > distance)) return 1;
    
    return 0;
}


int solution(int n, vector<string> data) {
    int answer = 0;
    
    // 줄 세우기
    row = {"A", "C", "F", "J", "M", "N", "R", "T"};
    
    do {
        int ok_sign = 1;
        
        for (auto d : data) {
            ok_sign *= isOk(d);
            
            // 하나라도 조건 안맞으면 다시 줄 세우기
            if (!ok_sign) break;
        }
        
        answer += ok_sign;
        
    } while (next_permutation(row.begin(), row.end()));
    
    return answer;
}
