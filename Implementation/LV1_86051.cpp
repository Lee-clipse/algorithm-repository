#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    
    // 1부터 9까지 합
    int answer = 45;
    
    // 나오는 수를 빼기
    for (auto num : numbers) {
        answer -= num;
    }
    
    return answer;
}
