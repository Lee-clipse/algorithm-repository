#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

// 3:50 ~ 4:00 (10+)

int solution(int n) {
    int answer = 0;
    
    // k는 n보다 작은 수 중 가장 큰 3의 승수
    int k = 0;
    while (pow(3, k++) <= n);
    k -= 2;
    
    for (int i = 0; i <= k; i++) {
        
        // n을 3진법으로 한 번에 만들고 뒤집지 않고 10진법으로 바로 변환
        answer += ((n / (int)pow(3, k-i)) * (int)pow(3, i));
        n = n % (int)pow(3, k-i);
    }
    
    return answer;
}
