#include <string>
#include <vector>
#include <set>

using namespace std;

// 4:18 ~ 4:24

vector<int> solution(vector<int> numbers) {
    vector <int> answer;
    
    // 중복 허용 안하고 정렬도 해주는 자료구조
    set <int> arr;
    
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i+1; j < numbers.size(); j++) {
            arr.insert(numbers[i] + numbers[j]);
        }
    }
    
    // assign 함수로 벡터에 재할당
    answer.assign(arr.begin(), arr.end());
    
    return answer;
}
