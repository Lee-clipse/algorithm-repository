#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

// 3:14 ~ 3:19

int solution(vector<int> nums) {
    int answer = 0;
    
    /*
    
    // 예전 내 풀이: 정렬 -> 중복 제거 -> 고르기
    
    int N = nums.size();
    
    sort(nums.begin(), nums.end());
    
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    
    answer = N/2;
    
    if (nums.size() < N/2) {
        answer = nums.size();
    }
    */
    
    // 모범 풀이
    
    // unordered_set으로 자동 중복 제거 + nums배열 살려서 나중에 활용
    unordered_set <int> poketmon(nums.begin(), nums.end());
    
    // 굳이 if문 쓸 필요 없이 min으로 판별
    answer = min(nums.size() / 2, poketmon.size());
    
    return answer;
}
