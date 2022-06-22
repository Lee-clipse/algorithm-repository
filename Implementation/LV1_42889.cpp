#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(pair<int, double>a, pair<int, double>b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second > b.second;
	}
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    // 스테이지 분류를 위한 정렬
    sort(stages.begin(), stages.end());
    
    // 실패율 계산을 위한 변수
    double fail_rate;
    
    // 스테이지별 실패율을 저장할 리스트
    vector < pair<int, double> > fail_rate_list;
    
    for (int i = 1; i <= N; i++) {
        
        // i단계에 도달했지만 클리어하지 못한 유저
        double not_clear_user = count(stages.begin(), stages.end(), i);
        
        // i단계에 도달했고 이미 클리어한 유저
        double clear_user = stages.size() - (lower_bound(stages.begin(), stages.end(), i) - stages.begin());
        
        // 실패율
        double fail_rate = not_clear_user / clear_user;
        
        // 0으로 변환해주지 않으면 nan때문에 오답이 난다
        if (not_clear_user == 0 || clear_user == 0) {
            fail_rate = 0.0;
        }
        
        // 실패율 저장
        fail_rate_list.push_back({i, fail_rate});
    }
    
    // 실패율을 정렬하여 answer에 넘겨줌
    sort(fail_rate_list.begin(), fail_rate_list.end(), compare);
    
    for (auto iter : fail_rate_list) {
        answer.push_back(iter.first);
    }
    
    return answer;
}
