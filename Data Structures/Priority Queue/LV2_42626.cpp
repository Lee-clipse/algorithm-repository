#include <string>
#include <vector>
#include <iostream>
#include <queue>

// 7:37 ~ 7:48

using namespace std;

typedef unsigned long long ll;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    // 우선순위 큐로 scoville 지수를 항시 정렬
    priority_queue <ll, vector<ll>, greater<ll> > scov_list;
    
    // 옮겨담기
    for (auto s : scoville) {
        scov_list.push(s);   
    }
    
    // 모든 스코빌 지수가 K 이상이 될 때까지 반복
    // 섞는 과정에서 음식 수가 줄어드는데, 1개 이하가 되면 종료
    while (scov_list.size() >= 2 && scov_list.top() < K) {
        
        // 추출
        ll scov_1st = scov_list.top();
        scov_list.pop();
        ll scov_2nd = scov_list.top();
        scov_list.pop();
        
        // 섞기
        ll new_scov = scov_1st + 2 * scov_2nd;
        
        // 우선순위 큐에 삽입
        scov_list.push(new_scov);
        answer++;
    }
    
    // 섞는 과정을 반복했지만 만족하지 못하는 경우 -1 출력
    if (scov_list.top() < K) {
        answer = -1;
    }
    
    return answer;
}
