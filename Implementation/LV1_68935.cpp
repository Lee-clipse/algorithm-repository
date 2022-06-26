#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    queue <int> Q;
    
    while (n) {
        Q.push(n % 3);
        n /= 3;
    }
    
    while (!Q.empty()) {
        answer = answer * 3 + Q.front();
        Q.pop();
    }
    
    return answer;
}
