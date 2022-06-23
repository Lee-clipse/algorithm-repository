#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>

// 13:57 ~ 14:30 (33)

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    // 아이디 - 닉네임 현황을 저장할 map
    map <string, string> id_name_map;
    
    // 입장, 퇴장 기록을 저장할 vector
    vector < pair<string, int> > log;
    
    for (auto rec : record) {
        
        // record 파싱
        stringstream ss(rec);
        string act, uid, name;
        ss >> act >> uid >> name;
        
        // 입장 시, log 저장과 닉네임 변경 사항 갱신
        if (act == "Enter") {
            log.push_back({uid, 1});
            id_name_map[uid] = name;
        }
        
        // 퇴장 시, log 저장
        else if (act == "Leave") {
            log.push_back({uid, -1});
        }
        
        // 아이디 변경 시, 변경 사항 갱신
        else if (act == "Change") {
            id_name_map[uid] = name;
        }
    }
    
    // log의 +1, -1과 id_name_map을 바탕으로 result에 결과 담기
    for (auto l : log) {
        string message = id_name_map[l.first];
        if (l.second > 0) {
            message += "님이 들어왔습니다.";  
        }
        else {
            message += "님이 나갔습니다.";
        }
        answer.push_back(message);
    }
    
    return answer;
}
