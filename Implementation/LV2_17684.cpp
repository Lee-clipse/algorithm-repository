#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 1:41 ~ 2:03 (22)

vector<int> solution(string msg) {
    vector<int> answer;
    
    // 사전 생성
    vector <string> dict(27);
    for (int i = 1; i <= 26; i++) {
        dict[i] += ('A' + i-1);
    }
    
    int idx = 0;
    while (idx < msg.size()) {
        
        string target = "";
        for (int i = msg.size()-idx; i > 0; i--) {
            
            target = msg.substr(idx, i);
            auto iter = find(dict.begin(), dict.end(), target);
            
            // 사전에 등록되어 있으면 색인 번호 출력 및 사전 등록
            if (dict.end() != iter) {
                answer.push_back(iter - dict.begin());
                dict.push_back(msg.substr(idx, i+1));
                break;
            }
        }
        idx += target.size();
    }
    
    return answer;
}
