#include <iostream>

using namespace std;

// 5:14 ~ 5:25 포기

long long solution(int price, int money, int count) {
    long long answer = -1;
    
    // count번 타면 내야하는 이용료
    long long fee = 1LL * (count * (count + 1) / 2) * price;
    
    answer = fee - money;
    
    // 금액이 모자라지 않으면 0을 반환
    if (answer < 0) answer = 0;
    
    return answer;
}
