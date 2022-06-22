#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    
    // 예산 검토를 위해 정렬
    sort(d.begin(), d.end());
    
    // 더이상 지원이 불가능할 때까지 예산이 작은 부서부터 순차적으로 지원
    int idx = 0;
    while (idx < d.size() && budget >= d[idx]) {
        budget -= d[idx];
        idx++;
    }
    
    answer = idx;
    
    return answer;
}
