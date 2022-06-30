#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <functional>

using namespace std;

// 10:00 ~ 10:45 (45) 시간 종료
// 거의 다 왔는데 알수없는 로직 에러
// 10:51 로직 에러 발견 후 정답: 코딩테스트 점수를 string으로 저장해서 int 비교가 안되었던 것
// 하지만 효율성 테스트 전부 탈락
// 이제보니 O(5 * 100,000 * 50,000) 이네

// 11:21 queue로 교체했지만 효율성 테스트 탈락
// 이제보니 O(100,000 * 2 * 50,000) 이네

// Q하나당 N번 돌면 탈락이니 hash 써야만함
// 모범코드: unordered_map 사용

// 4:52 ~ 5:20 (28)

void makeInfo(vector<string> condition, int score, unordered_map<string, vector<int>>& info_map) {
    vector<string> sign = {"0000", "0001", "0011", "0111"};
    
    for (int i = 0; i < sign.size(); i++) {
        do {
            string cond = "";
            for (int j = 0; j < sign[i].size(); j++) {
                cond += (sign[i][j] == '1') ? condition[j] : "-";
            }
            info_map[cond].push_back(score);
            
        } while (next_permutation(sign[i].begin(), sign[i].end()));
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    // 원하는 조건을 조회하면 해당 조건에 부합하는 지원자의 코테 점수들이 나오는 map
    unordered_map<string, vector<int>> info_map;
    
    for (int i = 0; i < info.size(); i++) {
        
        int score;
        vector<string> info_vct(4);
        
        stringstream ss(info[i]);
        ss >> info_vct[0] >> info_vct[1] >> info_vct[2] >> info_vct[3] >> score;
        
        string condition = info_vct[0] + info_vct[1] + info_vct[2] + info_vct[3];
        
        // 지원자의 정보를 공백 없이 코테 점수와 함께 map에 저장
        info_map[condition].push_back(score);
        
        // 해당 지원자의 -를 포함한 모든 조건의 경우의 수를 map에 저장
        makeInfo(info_vct, score, info_map);
    }

    // query 조건을 바탕으로 코테 점수를 보고 합격 여부를 카운팅
    for (int i = 0; i < query.size(); i++) {
        
        int standard_score;
        vector<string> query_vct(4);
        string temp;
        
        stringstream ss(query[i]);
        for (int j = 0; j <= 6; j++) {
            (j%2 == 0) ? ss >> query_vct[j/2] : ss >> temp;
        }
        ss >> standard_score;
        
        string condition = query_vct[0] + query_vct[1] + query_vct[2] + query_vct[3];

        // 조건에 부합하는 지원자 중, 코테 점수가 기준 이상이라면 카운팅
        int count = 0;
        for (auto score : info_map[condition]) {
            if (standard_score <= score) {
                count++;
            }
        }
        answer.push_back(count);
    }
    
    return answer;
}
