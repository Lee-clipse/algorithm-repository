#include <string>
#include <vector>
#include <iostream>
#include <queue>

// 7:37 ~ 7:48

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    // 우선순위 큐로 scoville 지수를 항시 정렬
    // 이렇게 한 번에 벡터로부터 옮겨담기 가능
    priority_queue <int, vector<int>, greater<int>> scov_list (scoville.begin(),scoville.end());
    
    // 모든 스코빌 지수가 K 이상이 될 때까지 반복
    // 섞는 과정에서 음식 수가 줄어드는데, 1개 이하가 되면 종료
    while (scov_list.top() < K) {
        
        // 섞는 과정을 반복했지만 만족하지 못하는 경우 -1 출력
        if (scov_list.size() <= 1) {
            return -1;
        }
        
        // 추출
        int scov_1st = scov_list.top();
        scov_list.pop();
        int scov_2nd = scov_list.top();
        scov_list.pop();
        
        // 섞어서 우선순위 큐에 삽입
        scov_list.push(scov_1st + 2 * scov_2nd);
        answer++;
    }
    
    return answer;
}
