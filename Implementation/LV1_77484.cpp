#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    
    // 결과 vector를 0으로 초기화
    vector<int> answer(2, 0);
    
    // 0의 개수 저장
    int zero_count = 0;
    
    // 0이 아닌 번호 중 일치하는 번호 개수 저장
    int correct_count = 0;
    
    // 당첨 번호와 비교
    for (auto num : lottos) {
        
        // 0이 아닌 번호 조회
        if (num != 0) {
            for (auto win : win_nums) {
                if (num == win) {
                    correct_count++;
                    break;
                }
            }
        }
        // 0인 번호 수 카운팅
        else {
            zero_count++;
        }
    }      
    
    // 로또 순위로 변환해주는 배열
    // 맨 앞의 6은 7등을 변환해주기 위함이다
    int rank[7] = {6, 6, 5, 4, 3, 2, 1};
    
    // count값들을 기반으로 최고, 최저 순위 결정
    answer[0] = rank[correct_count + zero_count];
    answer[1] = rank[correct_count];
    
    return answer;
}
