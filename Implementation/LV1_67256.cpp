#include <string>
#include <vector>

using namespace std;

// from 부터 to 까지 거리를 리턴
int getDistance(int from, int to) {
    int distance = 0;
    
    distance += abs(((from-1) % 3) - ((to - 1) % 3));
    distance += abs(((from-1) / 3) - ((to - 1) / 3));
    
    return distance;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    // *: 10 / 0: 11 / #: 12
    // 왼손, 오른손의 최근 위치 저장
    int left_pos  = 10;
    int right_pos = 12;
    
    for (auto num : numbers) {
        
        // 0 -> 11
        if (num == 0) {
            num = 11;
        }
        
        // 3, 6, 9
        if (num % 3 == 0) {
            answer += "R";
            right_pos = num;
        }
        
        // 1, 4, 7
        else if (num % 3 == 1) {
            answer += "L";
            left_pos = num;
        }
        
        // 2, 5, 8, 0(11)
        else {
            
            // 왼손이 더 가까운 경우
            if (getDistance(left_pos, num) < getDistance(right_pos, num)) {
                answer += "L";
                left_pos = num;
            }
            
            // 오른손이 더 가까운 경우
            else if (getDistance(left_pos, num) > getDistance(right_pos, num)) {
                answer += "R";
                right_pos = num;               
            }
            
            // 거리가 같은 경우
            else {
                if (hand == "left") {
                    answer += "L";
                    left_pos = num;
                }
                else {
                    answer += "R";
                    right_pos = num;
                }
            }
        }
        
    }
    
    return answer;
}
