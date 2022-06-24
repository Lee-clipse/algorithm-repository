#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

// 4:52 ~ 5:20

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    // lower_bound 사용을 위래 정렬
    sort(citations.begin(), citations.end());
    
    int n = citations.size();
    int max_h = citations.back();

    // h번 이상 인용된 논문의 수: quote
    for (int h = 0; h < max_h; h++) {
        int quote = n - (lower_bound(citations.begin(), citations.end(), h) - citations.begin());
        if (quote >= h) {
            answer = max(answer, h);
        }
    }
    
    return answer;
}
