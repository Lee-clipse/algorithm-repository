#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 3:24 ~ 3:31

int isAdd(int num) {
    int result = 1;
    
    // 1부터 num-1까지 약수 카운팅 (1도 고려해야하므로)
    for (int i = 1; i < num; i++) {
        if (num % i == 0) result++;
    }

    if (result % 2 == 0) return 1;
    return -1;
}

int solution(int left, int right) {
    int answer = 0;
    
    for (int i = left; i <= right; i++) {
        
        // isAdd()의 값은 약수가 짝수이면 +1, 홀수이면 -1
        answer += (isAdd(i) * i);
    }
    
    return answer;
}
