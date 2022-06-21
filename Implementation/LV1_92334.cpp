#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    
    // 결과 vector를 0으로 초기화
    vector<int> answer(id_list.size(), 0);
    
    // 사용자의 index를 저장할 map
    map<string, int> id_idx_map;
    
    // [신고된 사용자, 신고한 사용자]를 저장할 map
    map<string, set<string>> report_map;
    
    // 사용자의 index를 map에 저장
    for (int i = 0; i < id_list.size(); i++) {
        id_idx_map[id_list[i]] = i;
    }
    
    // [신고된 사용자, 신고한 사용자]를 map에 저장
    for (auto rep : report) {
        
        // 신고 정보를 parsing
        stringstream ss(rep);
        string from, to;
        ss >> from >> to;
        
        // 신고된 사용자를 조회하면 신고한 사용자를 알 수 있도록 저장
        report_map[to].insert(from);
    }
    
    // 신고한 사용자가 K명 이상인 경우, 신고한 사용자의 메일 수 +1
    for (auto iter : report_map) {
        if (iter.second.size() >= k) {
            for (auto in_iter : iter.second) {
                answer[id_idx_map[in_iter]]++;
            }
        }
    }
    
    return answer;
}
