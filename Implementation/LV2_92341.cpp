#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
#include <cmath>

// 7:16 ~ 7:53 정답
// 7:55 ~ 8:10 코드 정리

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    // (차량번호, <입차 분, 누적 분>) 기록할 map
    map <string, pair<int, int>> parking_log;
    
    for (auto rec : records) {
        
        // 입차 출차 기록을 parsing
        stringstream ss(rec);
        string time, num, act;
        ss >> time >> num >> act;
        
        // nn:nn 형식을 분으로 변환
        int real_time = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
        
        // 누적 분
        int minute_sum = parking_log[num].second;
        
        // 입차
        if (act == "IN") {
            
            // <입차 분, 누적 분>을 갱신, 없다면 생성
            parking_log[num] = {real_time, minute_sum};
        }
        
        // 출차
        else if (act == "OUT") {
            
            // 출차 분 - 입차 분을 누적 분에 누적시킴
            int in_time = parking_log[num].first;
            parking_log[num] = {0 , minute_sum + (real_time - in_time)};
        }
    }
    
    // 23:59이 되어 출차하지 않은 차량에 대해 요금 청구
    for (auto log : parking_log) {
        
        string car_num = log.first;
        int in_time = log.second.first;
        int minute_sum = log.second.second;
        
        // 출차하지 않은 경우 입차 시각 ~ 23:59 만큼 누적
        if (in_time != 0 || minute_sum == 0) {
            parking_log[car_num] = {0, minute_sum + (1439 - in_time)};
        }
    }
    
    // 누적 분을 요금표에 맞게 요금으로 환산
    for (auto log : parking_log) {
        int minute_sum = log.second.second;
        
        // 기본 요금
        if (minute_sum < fees[0]) {
            answer.push_back(fees[1]);
        }
        
        // 기본 시간 초과했으므로 단위 요금 청구
        else {
            answer.push_back(fees[1] + ceil((minute_sum - fees[0]) / (double)fees[2] ) * fees[3] );
        }
    }
    
    return answer;
}
